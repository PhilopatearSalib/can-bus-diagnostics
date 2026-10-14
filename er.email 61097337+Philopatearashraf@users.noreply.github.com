cab3526  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Correct inaccurate function comments; README wording
dacf7fb  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  README: hardware photo, carrier-board note, and no-license statement
9e61c04  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  README: reword build-check note
d1dfab0  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Docs: update for the Switches.c fix and header edits
8c59e9f  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Switches.c: drop pointer cast when writing the GPIO lock key
0c4985a  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Add docs/CHANGES.md listing every change since the 2019 submission
9ec029e  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Record the 2026 GCC build check
f334a95  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  README: link the demo video
e48e426  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Add README
a2c5f83  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Reconstruct missing PositiveResponse.h (ECU)
53b76fb  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Fix two includes so the sources build from a clean TivaWare install
80b69c5  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Fix typos in comments (comments only)
95c6ea0  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Make indentation consistent (4 spaces), whitespace only
e023e52  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Normalize line endings to LF and add .gitattributes
7236b3d  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Add architecture and protocol documentation
baf304c  Philopatear Salib <12345678+username@users.noreply.github.com>  2026-10-13  Add .gitignore for Code Composer Studio build output and TivaWare files
7f913c1  Philopatear Salib <12345678+username@users.noreply.github.com>  2019-09-05  Import original 2019 course project (TI files removed)
