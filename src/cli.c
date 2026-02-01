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
        "Honeypot commands:\n"
        "   honeypot start      Start the honeypot\n"
        "   honeypot stop       Stop the honeypot\n"
    );
}

void hexagon_version(void) {
    printf("HEXAGON Alpha v0.0.2 \"Honeypot Awakening\"\n");
}

void hexagon_status(void) {
    printf(
        "Honeypot: OFFLINE\n"
        "Threat DB: EMPTY\n"
        "Shield: DISABLED\n"
    );
}

void hexagon_log(const char *msg) {
    FILE *f = fopen("logs/hexagon.log", "a");
    if(f) {
        fprintf(f, "%s\n", msg);
        fclose(f);
    }
}

void hexagon_start(void) {
    printf("[+] Honeypot activated\n");
    hexagon_log("Honeypot started.");
}

void hexagon_stop(void) {
    printf("[-] Honeypot deactivated\n");
    hexagon_log("Honeypot stopped.");
}
