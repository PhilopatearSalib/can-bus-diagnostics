# Changes since the 2019 submission

The first commit in this repository contains the project as submitted in September 2019, unchanged apart from the folder names and the removal of Texas Instruments files. This page lists every change made in 2026 to prepare it for publication, and why.

**Summary:** the compiled program is unchanged. All 18 `.c` files produce identical object code before and after the cleanup (checked with `arm-none-eabi-gcc` 13.2). No lines were added to or removed from the original source files, so the line numbers cited in the report's MISRA section still match.

## Removed

| File | Node | Why |
|---|---|---|
| `tm4c123gh6pm_startup_ccs.c` | both | TI license restricts redistribution. CCS generates this file; see the README for the vector-table edits |
| `uartstdio.c`, `uartstdio.h` | both | TI license restricts redistribution. Taken from TivaWare `utils/` |
| `tm4c123gh6pm.h` | both | TI file, provided by TivaWare `inc/` |
| `interrupt.h` | Diagnostic Tool | Unmodified copy of TivaWare `driverlib/interrupt.h` |

## Renamed

| Before | After | Why |
|---|---|---|
| `CAN State Machine/` | `ecu-state-machine/` | No spaces, consistent naming |
| `Diagnostic Tool/` | `diagnostic-tool/` | No spaces, consistent naming |
| `Final Project.pdf` | `docs/Final_Project_Report.pdf` | Grouped with the documentation. Content unchanged: the "Data Fromat" typo remains because the Word source is not available |

## Added

| File | Why |
|---|---|
| `README.md` | Overview, protocol summary, hardware, build steps, usage, MISRA notes, authors, demo link |
| `docs/architecture.md` | Layer diagrams of both nodes, based on the report's static-architecture figures and the code |
| `docs/protocol.md` | Byte-level protocol, session rules, and notes on observed behaviour, all taken from the code |
| `docs/CHANGES.md` | This file |
| `.gitignore` | Keeps CCS build output, workspace files and TI files out of the repository |
| `.gitattributes` | Stores text files with LF line endings |
| `ecu-state-machine/PositiveResponse.h` | **Reconstructed.** The original header was missing from the 2019 archive, but `main.c` and `PositiveResponse.c` include it. It declares only the three functions defined in `PositiveResponse.c` and is marked in the file as reconstructed in 2026 |

## Modified

**Every one of the 33 original source files was converted from CRLF to LF line endings.** The table below lists the other changes. "Indentation" means leading whitespace only. "Comments" means comment text or comment-box alignment only. Original author headers were left untouched.

| File | Indentation | Comments | Code |
|---|:-:|:-:|---|
| `ecu-state-machine/main.c` | ✓ | ✓ the clockwise branch comment said "Counter Clockwise" | `#include "Leds.h"` → `"LEDs.h"`, matching the file name (needed on case-sensitive systems) |
| `ecu-state-machine/CAN0.c` | ✓ | ✓ "is configure" → "is configured" | |
| `ecu-state-machine/CAN0.h` | | ✓ box alignment | |
| `ecu-state-machine/Delay.h` | | ✓ box alignment | |
| `ecu-state-machine/InitConsole.h` | | ✓ "Non- Reentrant" | |
| `ecu-state-machine/LEDs.h` | | ✓ "Non- Reentrant" | |
| `ecu-state-machine/PositiveResponse.c` | ✓ | | |
| `ecu-state-machine/StateMachine.c` | ✓ | ✓ "BLue" → "Blue" | |
| `diagnostic-tool/CAN0.c` | ✓ | | |
| `diagnostic-tool/CAN0.h` | | ✓ "Non- Reentrant" | |
| `diagnostic-tool/ControlSession.c` | ✓ | | |
| `diagnostic-tool/ControlSession.h` | | ✓ "Non- Reentrant" | |
| `diagnostic-tool/ReadSession.c` | ✓ | | |
| `diagnostic-tool/Receive.c` | ✓ | | |
| `diagnostic-tool/Receive.h` | | ✓ "Receiving el Response" → "Receiving the Response" | |
| `diagnostic-tool/Switches.c` | ✓ | | |
| `diagnostic-tool/UART_Init.h` | | ✓ "Non- Reentrant" | Bare `#include "interrupt.h"` replaced by a comment. The same header is already included as `"driverlib/interrupt.h"`, and the local copy was removed |
| `diagnostic-tool/WriteSession.c` | ✓ | ✓ "Clock wise" → "Clockwise" | |
| `diagnostic-tool/WriteSession.h` | | ✓ "Non- Reentrant" | |

All other source files received only the line-ending conversion: `ecu-state-machine/` `Delay.c`, `InitConsole.c`, `LEDs.c`, `NegativeResponse.c`, `NegativeResponse.h`, `StateMachine.h`; and `diagnostic-tool/` `Delay.c`, `Delay.h`, `ReadSession.h`, `Switches.h`, `TimeOut.c`, `TimeOut.h`, `UART_Init.c`, `main.c`.

## Deliberately not changed

- Program output strings, such as `"Write - Clock Wise"`.
- Function and variable names.
- The behaviour quirks listed in [protocol.md](protocol.md#notes-on-observed-behaviour), including the 4-byte request length and the `Switches.c` line that newer GCC versions reject.
- Inaccurate function comments that are not typos. For example, the ECU's `Get_MSG_ID` / `Get_MSG_Data` comments say "Outputs: void", and the Diagnostic Tool's `Send_Command` comment says `int obj`.
