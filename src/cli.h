#ifndef HEXAGON_CLI_H
#define HEXAGON_CLI_H

void hexagon_help(void); // v0.0.1 version
void hexagon_version(void);
void hexagon_status(void);

void hexagon_log(const char *msg); // v0.0.2 version
void hexagon_start(void);
void hexagon_stop(void);

#endif