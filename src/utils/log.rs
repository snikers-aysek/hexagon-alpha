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
