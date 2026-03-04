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
