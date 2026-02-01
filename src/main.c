#include <stdio.h>
#include <string.h>
#include "cli.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        hexagon_help();
        return 0;
    }

    if (strcmp(argv[1], "help") == 0) {
        hexagon_help();
    } else if (strcmp(argv[1], "version") == 0) {
        hexagon_version();
    } else if (strcmp(argv[1], "status") == 0) {
        hexagon_status();
    } else {
        printf("Unknown command: %s\n", argv[1]);
        printf("Use 'hexagon help'\n");
    }

    return 0;
}