# HEXAGON Honey Pot Antivirus (v0.0.6-alpha)

HEXAGON is a fully **open-source antivirus for Linux**, using a **honeypot system** to analyze malware.

> Linux only. Windows is not supported.

HEXAGON creates fake processes (honeypots) that lure viruses, analyzes them, and stores all data in the **HEXAGON Virus Database**.  
If HEXAGON on another machine detects the same virus in the database, it automatically blocks it on startup.

---

## Features (v0.0.6-alpha)

- CLI to manage the antivirus
- Start / stop HEXAGON
- Activate / deactivate honeypot
- View logs (`logs/hexagon.log`)
- Clear logs
- Basic structure for future scanning and virus database updates

---

## Installation and usage

1. Make sure **Rust** is installed: https://www.rust-lang.org/tools/install
2. Clone the repository:

```bash
git clone https://github.com/snikers-aysek/HEXAGON.git
cd HEXAGON
```

3. Build and run:

```bash
cargo build --release
./target/release/hexagon <command>
```
To rebuild after changes, just run: cargo build --release.

---

Available commands:
```
hexagon help                 - show help
hexagon version              - show HEXAGON version
hexagon status               - show HEXAGON and honeypot status
hexagon start                - start HEXAGON
hexagon stop                 - stop HEXAGON
hexagon restart              - restart HEXAGON
hexagon honeypot start       - activate honeypot
hexagon honeypot stop        - deactivate honeypot
hexagon log                  - show last log lines
hexagon clear-logs           - clear log file
hexagon update               - update virus database (future)
hexagon scan                 - scan files/processes (future)
```

---

All logs stored in:
logs/hexagon.log
