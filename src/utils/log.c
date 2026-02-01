#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include "log.h"

#define LOG_FILE "logs/hexagon.log"

void hexagon_log(log_level_t level, const char *msg) {
    mkdir("logs", 0755); // создаём папку, если нет

    FILE *f = fopen(LOG_FILE, "a");
    if(!f) return;

    const char *level_str = (level==LOG_INFO) ? "INFO" :
                            (level==LOG_WARN) ? "WARN" : "ERR";

    time_t t = time(NULL);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));

    fprintf(f, "[%s] [%s] %s\n", buf, level_str, msg);
    fclose(f);
}
