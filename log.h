#ifndef LOG_H // header guard
#define LOG_H

#ifdef __unix__
    const int separator_status = 1;
    const char separator[] = "";
#elif defined WIN32
    const int separator_status = 0;
    const char separator[] = "";
#else
    const int separator_status = 1;
    const char separator[] = "./";
#endif

void log_all();
void log_logcat();
void log_last_kmsg();
void log_dmesg();
void log_kmsg();
void log_kernel_version();

void help();

// To be added
void log_archive_win();
void log_archive_linux();
void log_archive_mac();

#endif
