#include <stdio.h>
#include "cli.h"

void hexagon_help(void) {
    printf(
        "Hexagon - Open Source Honeypot Antivirus\n\n"
        "Usage:\n"
        "   hexagon <command>\n\n"
        "Commands:\n"
        "   help        Show this help\n"
        "   version     Show version\n"
        "   status      Show system status\n"
    );
}

void hexagon_version(void) {
    printf("HEXAGON Alpha v0.0.1 \"Honeypot Awakening\"\n");
}

void hexagon_status(void) {
    printf(
        "Honeypot: OFFLINE\n"
        "Threat DB: EMPTY\n"
        "Shield: DISABLED\n"
    );
}