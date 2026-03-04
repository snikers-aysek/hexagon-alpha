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


mod core;
mod modules;
mod utils;
mod cli;

use core::hexagon::Hexagon;
use cli::cli_parse;

fn main() {
    let mut hexagon = Hexagon::new();
    let args: Vec<String> = std::env::args().collect();
    cli_parse(&mut hexagon, &args);
}
