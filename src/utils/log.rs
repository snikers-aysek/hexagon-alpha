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


use std::fs::{File, create_dir_all, OpenOptions};
use std::io::Write;
use std::time::SystemTime;

pub enum LogLevel {
    Info,
    Warn,
    Err,
}

pub fn hexagon_log(level: LogLevel, msg: &str) {
    let log_dir = "logs";
    create_dir_all(log_dir).ok();

    let log_file = format!("{}/hexagon.log", log_dir);

    let mut file = OpenOptions::new()
        .append(true)
        .create(true)
        .open(&log_file)
        .unwrap();

    let level_str = match level {
        LogLevel::Info => "INFO",
        LogLevel::Warn => "WARN",
        LogLevel::Err => "ERR",
    };

    let now = SystemTime::now();
    let datetime: chrono::DateTime<chrono::Local> = now.into();
    let timestamp = datetime.format("%Y-%m-%d %H:%M:%S");

    writeln!(file, "[{}] [{}] {}", timestamp, level_str, msg). ok();
}
