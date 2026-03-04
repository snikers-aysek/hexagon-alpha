/*
 * HEXAGON Honey Pot Antivirus (v0.0.6-alpha)
 * Copyright (C) 2026 Bad4Ending
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */


use crate::core::hexagon::Hexagon;
use crate::utils::log::{hexagon_log, LogLevel};

pub fn cli_parse(hex: &mut Hexagon, args: &[String]) {
    if args.len() < 2 {
        hexagon_help();
        return;
    }

    match args[1].as_str() {
        "help" => hexagon_help(),
        "version" => hexagon_version(),
        "log" => hexagon_log_cmd(),
        "start" => hex.start(),
        "stop" => hex.stop(),
        "restart" => hex.restart(),
        "honeypot" => {
            if args.len() < 3 {
                println!("Usage: hexagon honeypot <start|stop>");
                return;
            }
            match args[2].as_str() {
                "start" => hex.start(),
                "stop" => hex.stop(),
                _ => println!("Unknown honeypot command: {}", args[2]),
            }
        }
        "clear-logs" => clear_logs(),
        "update" => println!("Updating virus database... (not implemented yet)"),
        "scan" => println!("Scanning files/processes... (not implemented yet)"),
        _ => println!("Unknown command: {}", args[1]),
    }
}

fn hexagon_help() {
    println!("HEXAGON {} - alpha", crate::core::hexagon::HEXAGON_VERSION);
    println!("Commands:");
    println!("  help           - show this message");
    println!("  version        - show HEXAGON version");
    println!("  status         - show HEXAGON status");
    println!("  log            - show last log lines");
    println!("  start          - start HEXAGON");
    println!("  stop           - stop HEXAGON");
    println!("  honeypot start|stop - control honeypot");
    println!("  update         - update virus database (future)");
    println!("  scan           - scan files/processes (future)");
    println!("  clear-logs     - clear log file");
    println!("  restart        - restart HEXAGON and active modules");
}

fn hexagon_version() {
    println!("HEXAGON version: {}", crate::core::hexagon::HEXAGON_VERSION);
}

fn hexagon_log_cmd() {
    use std::fs::File;
    use std::io::{BufReader, BufRead};

    let file = File::open("logs/hexagon.log");
    if let Ok(f) = file {
        let reader = BufReader::new(f);
        for line in reader.lines() {
            if let Ok(l) = line { println!("{}", l); }
        }
    } else {
        println!("No logs found.");
    }
}

fn clear_logs() {
    use std::fs;
    if fs::remove_file("logs/hexagon.log").is_ok() {
        println!("Log file cleared.");
    } else {
        println!("No log file to clear.");
     }
}
