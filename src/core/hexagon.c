#include <stdio.h>
#include "hexagon.h"
#include "../utils/log.h"
#include "../modules/honeypot.h"

int hexagon_running = 0;

void hexagon_init(void) {
    hexagon_log(LOG_INFO, "HEXAGON  initializing...");
}

void hexagon_start(void) {
    if(hexagon_running) {
        hexagon_log(LOG_WARN, "HEXAGOM already running!");
        return;
    }
    hexagon_log(LOG_INFO, "HEXAGON starting...");
    honeypot_start();
    hexagon_running = 1;
}

void hexagon_stop(void) {
    if(!hexagon_running) {
        hexagon_log(LOG_WARN, "HEXAGON not running!");
        return;
    }
    hexagon_log(LOG_INFO, "HEXAGON stopping...");
    honeypot_stop();
    hexagon_running = 0;
}