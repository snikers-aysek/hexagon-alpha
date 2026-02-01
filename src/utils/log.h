#ifndef LOG_H
#define LOG_H

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERR
} log_level_t;

void hexagon_log(log_level_t level, const char *msg);

#endif