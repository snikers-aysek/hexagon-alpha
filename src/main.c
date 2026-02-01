#include <stdio.h>
#include <string.h>
#include "cli.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        hexagon_help();
        return 0;
    }

    if (strcmp(argv[1], "help") == 0) { // hexagon help
        hexagon_help();
    } else if(strcmp(argv[1], "version") == 0) { // hexagon version
        hexagon_version();
    } else if(strcmp(argv[1], "status") == 0) { // hexagon status
        hexagon_status();
    } else if(strcmp(argv[1], "honeypot") == 0) { // hexagon honeypot
        if(argc < 3) {
            printf("Usage: hexagon honeypot <start|stop>\n"); // hexagon honeypot help
        } else if(strcmp(argv[2], "start") == 0) {
            hexagon_start();
        } else if(strcmp(argv[2], "stop") == 0) {
            hexagon_stop();
        } else {
            printf("Unknown honeypot command: %s\n", argv[2]);
        }
    } else {
        printf("Unknown command: %s\n", argv[1]);
        printf("Use 'hexagon help'\n");
    }

    return 0;
}