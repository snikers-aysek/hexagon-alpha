#ifndef HEXAGON_CLI_H
#define HEXAGON_CLI_H

void cli_parse(int argc, char **argv);

void hexagon_help(void); // v0.0.1 version
void hexagon_version(void);
void hexagon_status(void); // v0.0.2 version
void hexagon_start(void);
void hexagon_stop(void);
void hexagon_log_cmd(void); // v0.0.3 version
void hexagon_start_cmd(void);
void hexagon_stop_cmd(void);
void hexagon_honeypot(int argc, char **argv);
void hexagon_update(void);
void hexagon_scan(void);
void hexagon_clear_logs(void);
void hexagon_restart(void);

#endif