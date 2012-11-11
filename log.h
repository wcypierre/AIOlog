/*
 *   log.h
 *   This file acts as an interface to interact with the users
 *
 *   Copyright (c) 2012, wcypierre <wcypierre@gmail.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOG_H // header guard
#define LOG_H

extern std::string device_id;

#ifdef _WIN64
    const int os_type = 0;
    const std::string separator = "";
#elif _WIN32
    const int os_type = 0;
    const std::string separator = "";
#elif __APPLE__
    const int os_type = 1;
    const std::string separator = "./";
#elif __linux
    const int os_type = 1;
    const std::string separator = "";
#elif __unix
    const int os_type = 1;
    const std::string separator = "";
#elif __posix
    const int os_type = 1;
    const std::string separator = "";
#endif

void log_essential();
void log_all();
void log_logcat();
void log_logcat_continuous();
void log_last_kmsg();
void log_dmesg();
void log_kmsg();
void log_kmsg_continuous();

void header();
void help();

void misc_options();
void log_kernel_version();

void settings_options();
void set_device_id(std::string &);

void advanced_options();
void log_logcat_radio();
void log_logcat_clear();
void log_dmesg_clear();

void adb_start_server();
void wait_for_device();
void adb_devices();

// To be added
void log_archive_win();
void log_archive_linux();
void log_archive_mac();
void log_cpu_min_frequency();
void log_cpu_max_frequency();
void log_tegra3_cpu_variant();
void log_push();
void html_logcat();
void html_dmesg();
void html_kmsg();
void html_last_kmsg();

#endif
