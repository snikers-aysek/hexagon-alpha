use std::fs::create_dir_all;
use crate::utils::log::{hexagon_log, LogLevel};

pub const HONEYPOT_DIR: &str = "honeypot_trap";

pub fn start() {
    create_dir_all(HONEYPOT_DIR).ok();
    hexagon_log(LogLevel::Info, "Honeypot activated");
}

pub fn stop() {
    hexagon_log(LogLevel::Info, "Honeypot deactivated") ;
}
