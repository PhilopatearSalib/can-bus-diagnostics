# Architecture

Both nodes use the same layered static architecture, described in the 2019 report (pages 4 and 15 of `Final_Project_Report.pdf`):

| Layer | Contents |
|---|---|
| **Application** | Project logic: the diagnostic services on the tool, the state machine and responses on the ECU |
| **ECU abstraction** | Project modules wrapping the board: `CAN0`, LEDs, switches, console, delays |
| **MCU abstraction** | TI TivaWare `driverlib` and `utils/uartstdio` (not part of this repository) |
| **Peripherals** | TM4C123GH6PM on-chip CAN0, GPIO, UART0 and system control |

![Layered architecture of both nodes](images/architecture.svg)

The module-to-layer assignment follows the report's figures. The arrows below follow the `#include` and call relationships in the code. Direct `UARTprintf`/`UARTgetc` calls from the application modules are left out for readability.

## System overview

```mermaid
flowchart LR
    PC["PC serial terminal<br/>115200 baud"] -- "UART0 via USB debug port" --> T
    SW["On-board switches<br/>PF0, PF4"] --> T
    T["Node 1: Diagnostic Tool<br/>TM4C123GH6PM LaunchPad"] -- "PB4/PB5" --> X1["CAN transceiver"]
    X1 ===|"CAN bus, 500 kbit/s<br/>120 Ω at each end"| X2["CAN transceiver"]
    X2 -- "PB4/PB5" --> E["Node 2: ECU (CAN State Machine)<br/>TM4C123GH6PM LaunchPad"]
    E --> LED["On-board RGB LED<br/>PF1 red, PF2 blue, PF3 green"]
    E -- "UART0 log" --> PC2["PC serial terminal<br/>115200 baud"]
```

## Node 1: Diagnostic Tool (`diagnostic-tool/`)

```mermaid
flowchart TB
    main["main.c<br/>console command loop"]

    subgraph APP["Application layer"]
        RS["ReadSession"]
        WS["WriteSession"]
        CS["ControlSession"]
        RX["Receive"]
        TO["TimeOut"]
    end

    subgraph ECUA["ECU abstraction layer"]
        CAN["CAN0"]
        UI["UART_Init"]
        SWM["Switches"]
        DL["Delay"]
    end

    subgraph MCUA["MCU abstraction layer: TivaWare (external)"]
        DCAN["driverlib/can"]
        DGPIO["driverlib/gpio"]
        DUART["driverlib/uart + utils/uartstdio"]
        DSYS["driverlib/sysctl + interrupt"]
    end

    main --> RS & WS & CS
    main --> CAN & UI & SWM
    RS & WS & CS --> CAN & DL & TO & RX
    RX --> CAN & UI
    TO --> UI
    SWM --> CAN & DL
    CAN --> UI
    SWM --> DUART
    CAN --> DCAN & DGPIO & DSYS
    UI --> DUART & DGPIO & DSYS
    SWM --> DGPIO & DSYS
    DL --> DSYS
```

| Module | Layer | Responsibility |
|---|---|---|
| `main.c` | Application (entry point) | Initialises CAN, UART and switches, then reads commands (`0x10`, `0x22`, `0x2E`) from the console |
| `ReadSession` | Application | Sends Read requests (LED state / direction) and waits for the reply |
| `WriteSession` | Application | Sends Write requests (LED colour / direction) and waits for the reply |
| `ControlSession` | Application | Sends Session Control requests (default / extended) |
| `Receive` | Application | Decodes a response ID and payload and prints it |
| `TimeOut` | Application | Prints `Time Out` and clears the receive flag |
| `CAN0` | ECU abstraction | CAN0 init, interrupt handler, send/receive helpers |
| `UART_Init` | ECU abstraction | Clock and UART0 console setup, message printing |
| `Switches` | ECU abstraction | PF0/PF4 interrupt setup and handler, sends `0x31` / `0x32` |
| `Delay` | ECU abstraction | Busy-wait delays (1 s, 500 ms timeout, 500 ms debounce) |

## Node 2: ECU / CAN State Machine (`ecu-state-machine/`)

```mermaid
flowchart TB
    main["main.c<br/>request dispatcher"]

    subgraph APP["Application layer"]
        SM["StateMachine"]
        PR["PositiveResponse"]
        NR["NegativeResponse"]
    end

    subgraph ECUA["ECU abstraction layer"]
        CAN["CAN0"]
        LED["LEDs"]
        CON["InitConsole"]
        DL["Delay"]
    end

    subgraph MCUA["MCU abstraction layer: TivaWare (external)"]
        DCAN["driverlib/can"]
        DGPIO["driverlib/gpio"]
        DUART["driverlib/uart + utils/uartstdio"]
        DSYS["driverlib/sysctl + interrupt"]
    end

    main --> SM & PR & NR
    main --> CAN & LED & CON
    SM --> LED & DL
    PR --> LED & CAN
    NR --> CAN
    CAN --> DCAN & DGPIO & DSYS & DUART
    LED --> DGPIO & DSYS
    CON --> DUART & DGPIO & DSYS
    DL --> DSYS
```

| Module | Layer | Responsibility |
|---|---|---|
| `main.c` | Application (entry point) | Initialises the node and dispatches each received frame by CAN ID and current session |
| `StateMachine` | Application | Advances the LED one step clockwise or counter-clockwise |
| `PositiveResponse` | Application | Executes allowed Read / Write / Session Control requests and sends the `+0x40` response |
| `NegativeResponse` | Application | Sends the negative response for a service not allowed in the active session |
| `CAN0` | ECU abstraction | CAN0 init, interrupt handler, send helpers, receive helpers |
| `LEDs` | ECU abstraction | RGB LED init, on/off, and read-back |
| `InitConsole` | ECU abstraction | Clock and UART0 console setup |
| `Delay` | ECU abstraction | 1 s busy-wait delay |

## Notes

- The report's figures label the bottom-right driver as "Systick". The functions in that box are `SysCtlDelay`, `SysCtlPeripheralEnable` and `SysCtlPeripheralReady`, from TivaWare's `sysctl` driver. The project does not use the SysTick timer.
- Both nodes run from the 16 MHz main oscillator without the PLL (`SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ`). UART0 is clocked from the 16 MHz PIOSC.
- Interrupt handlers (`CANIntHandler` on both nodes, `Switches_HANDLER` on the Diagnostic Tool) are placed in the vector table of TI's CCS startup file. That file is not included here, so the README explains the required edits.
