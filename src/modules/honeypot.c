#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../utils/log.h"
#include "honeypot.h"

#define HONEYPOT_DIR "honeypot_trap"

void honeypot_start(void) {
    mkdir(HONEYPOT_DIR, 0755); // создаём папку-ловушку
    hexagon_log(LOG_INFO, "Honeypot activated");
}

void honeypot_stop(void) {
    hexagon_log(LOG_INFO, "Honeypot deactivated");
}
