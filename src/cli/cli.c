#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../core/hexagon.h"
#include "../modules/honeypot.h"
#include "../utils/log.h"
#include "cli.h"

extern int hexagon_running;
extern int honeypot_running;

void hexagon_help(void) {
    printf("HEXAGON %s - alpha\n", HEXAGON_VERSION);
    printf("Commands:\n");
    printf("  help           - show this message\n");
    printf("  version        - show HEXAGON version\n");
    printf("  status         - show HEXAGON status\n");
    printf("  log            - show last log lines\n");
    printf("  start          - start HEXAGON\n");
    printf("  stop           - stop HEXAGON\n");
    printf("  honeypot start|stop - control honeypot\n");
    printf("  update         - update virus database (future)\n");
    printf("  scan           - scan files/processes (future)\n");
    printf("  clear-logs     - clear log file\n");
    printf("  restart        - restart HEXAGON and active modules");
}

void hexagon_version(void) {
    printf("HEXAGON version: %s\n", HEXAGON_VERSION);
}

void hexagon_status(void) {
    printf("HEXAGON status: %s\n", hexagon_running ? "running" : "stopped");
    printf("Honeypot module: %s\n", honeypot_running ? "active" : "inactive");
}

void hexagon_log_cmd(void) {
    FILE *f = fopen("logs/hexagon.log", "r");
    if(!f) {
        printf("No logs found.\n");
        return;
    }
    char line[512];
    while(fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

void hexagon_start_cmd(void) {
    printf("Honeypot starting...\n");
    hexagon_start();
}

void hexagon_stop_cmd(void) {
    printf("Honeypot stopping...\n");
    hexagon_stop();
}

void hexagon_restart_cmd(void) {
    printf("Hexagon restarting...\n");
    hexagon_stop();
    hexagon_start();
}

void hexagon_honeypot(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: hexagon honeypot <start|stop>\n");
        return;
    }
    if(strcmp(argv[2], "start") == 0) hexagon_start_cmd();
    else if(strcmp(argv[2], "stop") == 0) hexagon_stop_cmd();
    else printf("Unknown honeypot command: %s\n", argv[2]);
}

void hexagon_update(void) {
    printf("Updating virus database... (not implemented yet)\n");
}

void hexagon_scan(void) {
    printf("Scanning files/processes... (not implemented yet)\n");
}

void hexagon_clear_logs(void) {
    if(remove("logs/hexagon.log") == 0)
        printf("Log file cleared.\n");
    else
        printf("No log file to clear.\n");
}

void cli_parse(int argc, char **argv) {
    if(argc < 2) {
        hexagon_help();
        return;
    }

    if(strcmp(argv[1], "help") == 0) hexagon_help();
    else if(strcmp(argv[1], "version") == 0) hexagon_version();
    else if(strcmp(argv[1], "status") == 0) hexagon_status();
    else if(strcmp(argv[1], "log") == 0) hexagon_log_cmd();
    else if(strcmp(argv[1], "start") == 0) hexagon_start_cmd();
    else if(strcmp(argv[1], "stop") == 0) hexagon_stop_cmd();
    else if(strcmp(argv[1], "honeypot") == 0) hexagon_honeypot(argc, argv);
    else if(strcmp(argv[1], "update") == 0) hexagon_update();
    else if(strcmp(argv[1], "scan") == 0) hexagon_scan();
    else if(strcmp(argv[1], "clear-logs") == 0) hexagon_clear_logs();
    else if(strcmp(argv[1], "restart") == 0) hexagon_restart_cmd();
    else printf("Unknown command: %s\n", argv[1]);
}
