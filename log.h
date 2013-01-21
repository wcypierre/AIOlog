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

const float AIOLOG_VERSION = 0.7;

const char ADB_START_SERVER[] = "adb start-server";
const char ADB_WAIT_FOR_DEVICE[] = " wait-for-device";
const char ADB_DEVICES[] = "adb devices";
const char ADB_GET_SERIAL_NO[] = "adb get-serialno";
const char ADB_GETPROP_PRODUCT_MODEL[] = "adb shell getprop ro.product.model";

const char GET_SERIAL_NO[] = " get-serialno";
const char GETPROP_PRODUCT_MODEL[] = " shell getprop ro.product.model";

const char ADB_WITH_DEVICE_ID[] = "adb -s ";

const char DEVICE_NOT_FOUND_INDICATOR[] = "unknown";

const char LOGCAT[] = "logcat";
const char LOGCAT_RADIO[] = "logcat_radio";
const char KMSG[] = "kmsg";
const char LAST_KMSG[] = "last_kmsg";
const char DMESG[] = "dmesg";
const char KERNEL_VERSION[] = "kernel_version";
const char CID_VERSION[] = "cid";
const char LOG_ESSENTIAL[] = "log_essential";
const char LOG_ALL[] = "log_all";

const char DIR_AIOLOG_CREATE[] = " shell mkdir -p /mnt/sdcard/aiolog";
const char DIR_DOT_AIOLOG_CREATE[] = " shell mkdir -p /mnt/sdcard/.aiolog";

const char LOGCAT_THREADTIME[] = " logcat -d -v threadtime > logcat.txt";
const char LOGCAT_CONTINUOUS_THREADTIME[] = " logcat -v threadtime > logcat.txt";
const char LOGCAT_RADIO_THREADTIME[] = " logcat -d -v threadtime -b radio > logcat_radio.txt";
const char LOGCAT_CLEAR[] = " logcat -c";

const char LOGCAT_FILENAME[] = "logcat.txt";
const char LOGCAT_PHONE_ROOT_FILENAME[] = "/mnt/sdcard/logcat.txt";
const char LOGCAT_PHONE_AIOLOG_FILENAME[] = "/mnt/sdcard/aiolog/logcat.txt";
const char LOGCAT_PHONE_DOT_AIOLOG_FILENAME[] = "/mnt/sdcard/.aiolog/logcat.txt";

const char LOGCAT_RADIO_FILENAME[] = "logcat_radio.txt";
const char LOGCAT_RADIO_PHONE_ROOT_FILENAME[] = "/mnt/sdcard/logcat_radio.txt";
const char LOGCAT_RADIO_PHONE_AIOLOG_FILENAME[] = "/mnt/sdcard/aiolog/logcat_radio.txt";
const char LOGCAT_RADIO_PHONE_DOT_AIOLOG_FILENAME[] = "/mnt/sdcard/.aiolog/logcat_radio.txt";

const char LAST_KMSG_CODE[] = " shell cat /proc/last_kmsg > last_kmsg.txt";

const char LAST_KMSG_FILENAME[] = "last_kmsg.txt";
const char LAST_KMSG_PHONE_ROOT_FILENAME[] = "/mnt/sdcard/last_kmsg.txt";
const char LAST_KMSG_PHONE_AIOLOG_FILENAME[] = "/mnt/sdcard/aiolog/last_kmsg.txt";
const char LAST_KMSG_PHONE_DOT_AIOLOG_FILENAME[] = "/mnt/sdcard/.aiolog/last_kmsg.txt";

const char KMSG_CODE[] = " shell cat -f /proc/kmsg > kmsg.txt";
const char KMSG_CONTINUOUS_CODE[] = " shell cat /proc/kmsg > kmsg.txt";

const char KMSG_FILENAME[] = "kmsg.txt";
const char KMSG_PHONE_ROOT_FILENAME[] = "/mnt/sdcard/kmsg.txt";
const char KMSG_PHONE_AIOLOG_FILENAME[] = "/mnt/sdcard/aiolog/kmsg.txt";
const char KMSG_PHONE_DOT_AIOLOG_FILENAME[] = "/mnt/sdcard/.aiolog/kmsg.txt";

const char DMESG_CODE[] = " shell dmesg > dmesg.txt";
const char DMESG_CLEAR_CODE[] = " shell dmesg -c > .tmp";

const char DMESG_FILENAME[] = "dmesg.txt";
const char DMESG_PHONE_ROOT_FILENAME[] = "/mnt/sdcard/dmesg.txt";
const char DMESG_PHONE_AIOLOG_FILENAME[] = "/mnt/sdcard/aiolog/dmesg.txt";
const char DMESG_PHONE_DOT_AIOLOG_FILENAME[] = "/mnt/sdcard/.aiolog/dmesg.txt";

const char KERNEL_VERSION_FILENAME[] = "kernel_version.txt";

const char KERNEL_VERSION_CODE[] = " shell uname -a > kernel_version.txt";
const char KERNEL_VERSION_LOCAL_CODE[] = " shell uname -a";

const char CID_CODE[] = " shell getprop ro.cid";
const char CID_TO_TXT[] = " shell getprop ro.cid > cid.txt";

const char CID_VERSION_FILENAME[] = "cid.txt";
const char CID_PHONE_ROOT_FILENAME[] = "/mnt/sdcard/cid.txt";
const char CID_PHONE_AIOLOG_FILENAME[] = "/mnt/sdcard/aiolog/cid.txt";
const char CID_PHONE_DOT_AIOLOG_FILENAME[] = "/mnt/sdcard/.aiolog/cid.txt";

const char LOG_ESSENTIAL_INPUT_FILENAME[] = "logcat.txt kmsg.txt dmesg.txt last_kmsg.txt";
const char LOG_ALL_INPUT_FILENAME[] = "logcat.txt kmsg.txt dmesg.txt last_kmsg.txt";

const int BUFFER_SIZE = 50;

const char SDCARD_LOCATION[] = "/mnt/sdcard/";

const char AIOLOG_SLASH[] = "aiolog/";
const char AIOLOG_DOT_SLASH[] = ".aiolog/";

const char READ_MODE[] = "r";
const char WRITE_MODE[] = "w";

const char ZIP_CREATE[] = "7za a -tzip ";
const char TAR_CREATE[] = "tar cvf ";

const char ZIP_PARAM[] = " -mmt -aot -y";

const char ZIP_DOT[] = ".zip";
const char TAR_DOT[] = ".tar";

const char WHITESPACE[] = " ";
const char EMPTY[] = "";
const char NEWLINE = '\n';

const char DEVICE_NOT_FOUND_MESSAGE[] = "error: device not found";

const char ADB_PUSH_CODE[] = " push ";

const char CLEAR_SCREEN_WIN[] = "cls";
const char CLEAR_SCREEN_UNIX[] = "clear";

#ifdef _WIN64
    const int os_type = 0;
    const std::string separator = "";
#elif _WIN32
    const int os_type = 0;
    const std::string separator = "";
#elif __APPLE__
    const int os_type = 1;
    const std::string separator = "";
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

void log_push(std::string, std::string);
void dir_create();
void log_archive(std::string);
void log_archive_linux(std::string, std::string);
void log_archive_win(std::string, std::string);

void header();
void help();

void misc_options();
void log_kernel_version();
void log_cid_version();

void settings_options();
void set_device_id(std::string &);

void advanced_options();
void log_logcat_radio();
void log_logcat_clear();
void log_dmesg_clear();

void adb_start_server();
void wait_for_device();
void adb_devices();
void clear_screen();

// To be added
void log_logcat_option();
void log_dmesg_option();
void log_last_kmsg_option();
void log_kmsg_option();
void log_recovery_logcat();

void log_dumpsys();
void log_dumpstate();
void log_bugreport();

void log_archive_mac();

void log_cpu_min_frequency();
void log_cpu_max_frequency();
void log_tegra3_cpu_variant();

void log_recovery();
void log_fix_permissions();

void reboot_recovery();
void reboot_bootloader();
void reboot_download();
void reboot();
void shutdown();

void html_logcat();
void html_dmesg();
void html_kmsg();
void html_last_kmsg();

void open_xda();
void open_twitter();
void open_gplus();
void open_email();

void battery_voltage();
bool battery_charged();

void cpu_info();

#endif
