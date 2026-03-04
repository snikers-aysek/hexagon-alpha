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


use crate::modules::honeypot;
use crate::utils::log::{hexagon_log, LogLevel};

pub const HEXAGON_VERSION: &str = "v0.0.6-alpha";

pub struct Hexagon {
    pub running: bool,
}

impl Hexagon {
    pub fn new() -> Self {
        Hexagon { running: false }
    }

    pub fn init(&self) {
        hexagon_log(LogLevel::Info, "HEXAGON initializing...");
    }

    pub fn start(&mut self) {
        if self.running {
            hexagon_log(LogLevel::Warn, "HEXAGON already running!");
            return;
        }
        hexagon_log(LogLevel::Info, "HEXAGON starting...");
        honeypot::start();
        self.running = true;
    }

    pub fn stop(&mut self) {
        if !self.running {
            hexagon_log(LogLevel::Warn, "HEXAGON not running!");
            return;
        }
        hexagon_log(LogLevel::Info, "HEXAGON stopping...");
        honeypot::stop();
        self.running = false;
    }

    pub fn status(&self) {
        if self.running {
            println!("HEXAGON status: running (Honeypot active.)");
        } else {
            println!("HEXAGON status: stopped (Honeypot inactive.)");
        }
    }

    pub fn restart(&mut self) {
        hexagon_log(LogLevel::Info, "HEXAGON restarting...");
        self.stop();
        self.start();
    }
}
