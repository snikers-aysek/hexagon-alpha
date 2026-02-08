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
