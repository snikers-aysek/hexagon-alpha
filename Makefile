# HEXAGON Makefile for Rust
# v0.0.6-alpha

# Build release
build:
	cargo build --release

# Run HEXAGON with arguments
run:
	cargo run --release -- $(ARGS)

# Clean build artifacts
clean:
	cargo clean

# Install binary globally
install:
	cargo build --release
	sudo install -m 755 target/release/hexagon /usr/local/bin/hexagon

# Uninstall binary
uninstall:
	sudo rm -f /usr/local/bin/hexagon

.PHONY: build run clean install uninstall
