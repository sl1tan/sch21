#include "logger.h"

int logcat(FILE* log_file, char* message, log_level level) {
    time_t curr_time = time(0);
    struct tm* ltm = localtime(&curr_time);
    switch (level) {
        case debug:
            fprintf(log_file, "[%-8s] %d:%d:%d %s\n", "DEBUG", ltm->tm_hour, ltm->tm_min, 1 + ltm->tm_sec,
                    message);
            return 0;
        case info:
            fprintf(log_file, "[%-8s] %d:%d:%d %s\n", "INFO", ltm->tm_hour, ltm->tm_min, 1 + ltm->tm_sec,
                    message);
            return 0;
        case warning:
            fprintf(log_file, "[%-8s] %d:%d:%d %s\n", "WARNING", ltm->tm_hour, ltm->tm_min, 1 + ltm->tm_sec,
                    message);
            return 0;
        case error:
            fprintf(log_file, "[%-8s] %d:%d:%d %s\n", "ERROR", ltm->tm_hour, ltm->tm_min, 1 + ltm->tm_sec,
                    message);
            return 0;
    }
    return 1;
}

FILE* log_init(char* filename) { return fopen(filename, "a"); }

int log_close(FILE* log_file) { return fclose(log_file); }
