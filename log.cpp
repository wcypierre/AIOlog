/*
 *   log.cpp
 *   This file contains all the codes to log information from an android device
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

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "log.h"
#include "lang.h"
#include "error.h"

using namespace std;

void log_essential()
{
    log_logcat();
    log_dmesg();
    log_last_kmsg();
    log_kmsg();

    log_archive(LOG_ESSENTIAL);
}

void log_all()
{
    log_logcat();
    log_dmesg();
    log_last_kmsg();
    log_kmsg();
    log_kernel_version();

    log_archive(LOG_ALL);
}

void log_logcat()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_THREADTIME);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_THREADTIME);
    }

    system(command.c_str());

    cout << LOGCAT_MESSAGE << endl;

    dir_create();
    log_push(LOGCAT_FILENAME, LOGCAT_PHONE_ROOT_FILENAME);
    log_push(LOGCAT_FILENAME, LOGCAT_PHONE_DOT_AIOLOG_FILENAME);
    log_push(LOGCAT_FILENAME, LOGCAT_PHONE_AIOLOG_FILENAME);

    log_archive(LOGCAT);

    command.clear();
}

void log_logcat_continuous()
{
    string command;

    cout << endl;

    wait_for_device();

    cout << LOGCAT_CONTINUOUS_MESSAGE << endl;

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_CONTINUOUS_THREADTIME);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_CONTINUOUS_THREADTIME);
    }

    system(command.c_str());
}

void log_logcat_radio()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_RADIO_THREADTIME);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_RADIO_THREADTIME);
    }

    system(command.c_str());

    cout << LOGCAT_RADIO_MESSAGE << endl;

    dir_create();
    log_push(LOGCAT_RADIO_FILENAME, LOGCAT_RADIO_PHONE_ROOT_FILENAME);
    log_push(LOGCAT_RADIO_FILENAME, LOGCAT_RADIO_PHONE_DOT_AIOLOG_FILENAME);
    log_push(LOGCAT_RADIO_FILENAME, LOGCAT_RADIO_PHONE_AIOLOG_FILENAME);

    log_archive(LOGCAT_RADIO);

    command.clear();
}

void log_logcat_clear()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_CLEAR);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LOGCAT_CLEAR);
    }

    system(command.c_str());

    cout << LOGCAT_CLEAR_MESSAGE << endl;

    command.clear();
}

void log_last_kmsg()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LAST_KMSG_CODE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(LAST_KMSG_CODE);
    }

    system(command.c_str());

    cout << LAST_KMSG_MESSAGE << endl;

    dir_create();
    log_push(LAST_KMSG_FILENAME, LAST_KMSG_PHONE_ROOT_FILENAME);
    log_push(LAST_KMSG_FILENAME, LAST_KMSG_PHONE_DOT_AIOLOG_FILENAME);
    log_push(LAST_KMSG_FILENAME, LAST_KMSG_PHONE_AIOLOG_FILENAME);

    log_archive(LAST_KMSG);

    command.clear();
}

void log_dmesg()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DMESG_CODE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DMESG_CODE);
    }

    system(command.c_str());

    cout << DMESG_MESSAGE << endl;

    dir_create();
    log_push(DMESG_FILENAME, DMESG_PHONE_ROOT_FILENAME);
    log_push(DMESG_FILENAME, DMESG_PHONE_DOT_AIOLOG_FILENAME);
    log_push(DMESG_FILENAME, DMESG_PHONE_AIOLOG_FILENAME);

    log_archive(DMESG);

    command.clear();
}

void log_dmesg_clear()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DMESG_CLEAR_CODE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DMESG_CLEAR_CODE);
    }

    system(command.c_str());

    cout << DMESG_CLEAR_MESSAGE << endl;

    command.clear();
}

void log_kmsg()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(KMSG_CODE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(KMSG_CODE);
    }

    system(command.c_str());

    cout << KMSG_MESSAGE << endl;

    dir_create();
    log_push(KMSG_FILENAME, KMSG_PHONE_ROOT_FILENAME);
    log_push(KMSG_FILENAME, KMSG_PHONE_DOT_AIOLOG_FILENAME);
    log_push(KMSG_FILENAME, KMSG_PHONE_AIOLOG_FILENAME);

    log_archive(KMSG);

    command.clear();
}

void log_kmsg_continuous()
{
    string command;

    cout << endl;

    wait_for_device();

    cout << KMSG_CONTINUOUS_MESSAGE << endl;

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(KMSG_CONTINUOUS_CODE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(KMSG_CONTINUOUS_CODE);
    }

    system(command.c_str());

    command.clear();
}

void log_push(std::string from, std::string to)
{
    string command;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(ADB_PUSH_CODE);
        command.append(from);
        command.append(WHITESPACE);
        command.append(to);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(ADB_PUSH_CODE);
        command.append(from);
        command.append(WHITESPACE);
        command.append(to);
    }

    system(command.c_str());

    command.clear();
}

void dir_create()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DIR_AIOLOG_CREATE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DIR_AIOLOG_CREATE);
    }

    system(command.c_str());

    command.clear();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DIR_DOT_AIOLOG_CREATE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(DIR_DOT_AIOLOG_CREATE);
    }

    system(command.c_str());

    command.clear();
}

void log_archive(std::string option)
{
    string archive_filename;
    string input_filename;

    if(option.compare(LOGCAT) == 0)
    {
        archive_filename = LOGCAT;
        input_filename = LOGCAT_FILENAME;
    }
    else if(option.compare(LAST_KMSG) == 0)
    {
        archive_filename = LAST_KMSG;
        input_filename = LAST_KMSG_FILENAME;
    }
    else if(option.compare(DMESG) == 0)
    {
        archive_filename = DMESG;
        input_filename = DMESG_FILENAME;
    }
    else if(option.compare(KMSG) == 0)
    {
        archive_filename = KMSG;
        input_filename = KMSG_FILENAME;
    }
    else if(option.compare(LOG_ESSENTIAL) == 0)
    {
        archive_filename = LOG_ESSENTIAL;
        input_filename = LOG_ESSENTIAL_INPUT_FILENAME;
    }
    else if(option.compare(LOG_ALL) == 0)
    {
        archive_filename = LOG_ALL;
        input_filename = LOG_ALL_INPUT_FILENAME; // More to be added
    }
    else if(option.compare(LAST_KMSG) == 0)
    {
        archive_filename = LAST_KMSG;
        input_filename = LAST_KMSG_FILENAME;
    }
    else if(option.compare(LOGCAT_RADIO) == 0)
    {
        archive_filename = LOGCAT_RADIO;
        input_filename = LOGCAT_RADIO_FILENAME;
    }
    else if(option.compare(KERNEL_VERSION) == 0)
    {
        archive_filename = KERNEL_VERSION;
        input_filename = KERNEL_VERSION_FILENAME;
    }
    else if(option.compare(CID_VERSION) == 0)
    {
        archive_filename = CID_VERSION;
        input_filename = CID_VERSION_FILENAME;
    }

    if(os_type == 0)
    {
    	archive_filename.append(ZIP_DOT);

        log_archive_win(archive_filename, input_filename);
    }
    else if(os_type == 1)
    {
    	archive_filename.append(TAR_DOT);

        log_archive_linux(archive_filename, input_filename);
    }
}

void log_archive_linux(std::string archive_filename, std::string input_filename)
{
    string command;
    string archive_command;

    string remote_root_filename = SDCARD_LOCATION;
    string remote_aiolog_filename = SDCARD_LOCATION;
    string remote_dot_aiolog_filename = SDCARD_LOCATION;

    cout << endl;

    remote_root_filename.append(archive_filename);

    remote_aiolog_filename.append(AIOLOG_SLASH);
    remote_aiolog_filename.append(archive_filename);

    remote_dot_aiolog_filename.append(AIOLOG_DOT_SLASH);
    remote_dot_aiolog_filename.append(archive_filename);

    archive_command.append(TAR_CREATE);
    archive_command.append(archive_filename);
    archive_command.append(WHITESPACE);
    archive_command.append(input_filename);

    system(archive_command.c_str());

    log_push(archive_filename, remote_root_filename);
    log_push(archive_filename, remote_aiolog_filename);
    log_push(archive_filename, remote_dot_aiolog_filename);
}

void log_archive_win(std::string archive_filename, std::string input_filename)
{
    string command;
    string archive_command;

    string remote_root_filename = SDCARD_LOCATION;
    string remote_aiolog_filename = SDCARD_LOCATION;
    string remote_dot_aiolog_filename = SDCARD_LOCATION;

    cout << endl;

    remote_root_filename.append(archive_filename);

    remote_aiolog_filename.append(AIOLOG_SLASH);
    remote_aiolog_filename.append(archive_filename);

    remote_dot_aiolog_filename.append(AIOLOG_DOT_SLASH);
    remote_dot_aiolog_filename.append(archive_filename);

    archive_command.append(ZIP_CREATE);
    archive_command.append(archive_filename);
    archive_command.append(WHITESPACE);
    archive_command.append(input_filename);
    archive_command.append(ZIP_PARAM);

    system(archive_command.c_str());

    log_push(archive_filename, remote_root_filename);
    log_push(archive_filename, remote_aiolog_filename);
    log_push(archive_filename, remote_dot_aiolog_filename);
}

void header()
{
    cout << "**********************************************************" << endl;
    cout << "*              AIOlog - All in One Android Logger        *" << endl;
    cout << "*                         Version: " << AIOLOG_VERSION << "                   *" << endl;
    cout << "*                       By: wcypierre                    *" << endl;
    cout << "**********************************************************" << endl << endl;
}

void help()
{
    cout << "Format: %filename% %parameter%" << endl;
    cout << "Format List: " << endl;
    cout << "--device-id -id %id_value%\tChooses the Device ID to be used if there are more than one devices at the computer" << endl;
    cout << "--logcat -l\t\t\tDumps the logcat at the current directory and the file is called logcat.txt" << endl;
    cout << "--last-kmsg -lk\t\t\tDumps the last_kmsg at the current directory and the file is called last_kmsg.txt" << endl;
    cout << "--dmesg -d\t\t\tDumps the dmesg at the current directory and the file is called dmesg.txt" << endl;
    cout << "--kmsg -k\t\t\tDumps the kmsg at the current directory and the file is called kmsg.txt" << endl;

    cout << endl << EN_ENTER_TO_CONTINUE << endl;
    cin.get();
}

void misc_options()
{
    cout << EN_MISC_MENU_OPTION_1 << endl;
    cout << EN_MISC_MENU_OPTION_2 << endl;
    cout << EN_INMENU_OPTION_BACK << endl;
}

void settings_options()
{
    cout << EN_SETTINGS_MENU_OPTION_1 << endl;
    cout << EN_INMENU_OPTION_BACK << endl;
}

void advanced_options()
{
    cout << EN_ADVANCED_MENU_OPTION_1 << endl;
    cout << EN_ADVANCED_MENU_OPTION_2 << endl;
    cout << EN_ADVANCED_MENU_OPTION_3 << endl;
    cout << EN_INMENU_OPTION_BACK << endl;
}

void log_kernel_version()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(KERNEL_VERSION_CODE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(KERNEL_VERSION_CODE);
    }

    system(command.c_str());

    cout << KERNEL_VERSION_MESSAGE << endl;

    log_archive(KERNEL_VERSION);

    command.clear();
}

void log_cid_version()
{
    string command;

    string temp_buffer;
    char buffer[BUFFER_SIZE];

    size_t found;

    command.append(ADB_WITH_DEVICE_ID);
    command.append(device_id);
    command.append(CID_CODE);

    FILE * cid = popen(command.c_str(), READ_MODE);

    cout << endl;

    if(cid != NULL)
    {
        while(fgets(buffer, sizeof(buffer), cid) != NULL)
        {
            while(fgets(buffer, sizeof(buffer), cid) != NULL)
            {

            }
        }

        temp_buffer.assign(buffer);

        found = temp_buffer.find('\n');

        if(found != string::npos)
        {
            temp_buffer.erase(int(found));
        }

        if(temp_buffer.compare(DEVICE_NOT_FOUND_MESSAGE) == 0)
        {
            cout << EN_DEVICE_NOT_FOUND << endl << endl;
        }
        else if(temp_buffer.compare(EMPTY) == 0)
        {
            cout << CID_INVALID_LOCATION << endl << endl;
        }
        else
        {
            cout << EN_CID_VERSION_SHOW << temp_buffer << endl << endl;
        }
    }

    pclose(cid);

    command.clear();

    command.append(ADB_WITH_DEVICE_ID);
    command.append(device_id);
    command.append(CID_TO_TXT);

    system(command.c_str());

    log_archive(CID_VERSION);
}

void set_device_id(string & device_id)
{
    string command;
    string temp_device_id;
    int device_status = -1;

    char buffer[BUFFER_SIZE];
    string temp_buffer;

    size_t found;

    cin.clear();
    cin.ignore(100, NEWLINE);

    do
    {
        command.clear();

        cout << EN_SET_DEVICE_ID;

        if(os_type == 0)
        {
            command.append(separator);
            command.append(ADB_DEVICES);
        }
        else if(os_type == 1)
        {
            command.append(separator);
            command.append(ADB_DEVICES);
        }

        system(command.c_str());

        cout << endl;

        cout << EN_DEVICE_ID_PROMPT;
        getline(cin, temp_device_id);

        command.clear();

        if(device_id[0] != '\0')
        {
            FILE * serial_no = popen(command.c_str(), READ_MODE);

            if(serial_no != NULL)
            {
                while(fgets(buffer, sizeof(buffer), serial_no) != NULL)
                {
                    while(fgets(buffer, sizeof(buffer), serial_no) != NULL)
                    {

                    }
                }

                temp_buffer.assign(buffer);

                found = temp_buffer.find(NEWLINE);

                if(found != string::npos)
                {
                    temp_buffer.erase(int(found));
                }

                if(temp_buffer.compare(DEVICE_NOT_FOUND_INDICATOR) == 0)
                {
                    device_status = -1;
                }
                else
                {
                    device_status = 1;
                }

                cout << EN_DEVICE_ID_SHOW << device_id << endl;
            }

            pclose(serial_no);
        }

        clear_screen();
    }while(device_status != 1);

    if(temp_device_id[0] != '\0')
    {
        device_id.assign(temp_device_id);
    }

    command.clear();
    temp_device_id.clear();
}

void adb_start_server()
{
    string command;

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_START_SERVER);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_START_SERVER);
    }

    system(command.c_str());

    command.clear();
}

void wait_for_device()
{
    string command;

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(ADB_WAIT_FOR_DEVICE);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_WITH_DEVICE_ID);
        command.append(device_id);
        command.append(ADB_WAIT_FOR_DEVICE);
    }

    system(command.c_str());

    command.clear();
}

void adb_devices()
{
    string command;

    if(os_type == 0)
    {
        command.append(separator);
        command.append(ADB_DEVICES);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_DEVICES);
    }

    system(command.c_str());

    command.clear();
}

void clear_screen()
{
    if(os_type == 0)
    {
        system(CLEAR_SCREEN_WIN);
    }
    else
    {
        system(CLEAR_SCREEN_UNIX);
    }
}

// To do
void log_tegra3_cpu_variant()
{
    //[7]: cpu_speedo_id = 4 - AP33
    // 7 - Threshold ID, cpu_speedo_id = 4, soc_speedo_id = 1 [refer to [7] above the cpu_speedo_id check]

    // Tegra3: CPU Speedo ID 4<cpu_speedo_id>, Soc Speedo ID 1<soc_speedo_id>
    // Tegra Revision: A03 SKU: 0x81 CPU Process: 2 Core Process: 2
    // cpu_dvfs->process_id: 2<possible core_process_id>
    // core_nominal_mv_index: 7<possible threshold_index>

    // Reference: https://github.com/franciscofranco/One_X-2.6.39.4/blob/master/arch/arm/mach-tegra/tegra3_speedo.c

    int soc_speedo_id;
    int cpu_speedo_id;
    int cpu_process_id;
    int core_process_id;
    int threshold_index;

    char tegra3_revision[4];
    char tegra3_sku[5];

    if(threshold_index == 12)
    {
		if(cpu_process_id <= 2)
		{
		    cpu_speedo_id = 9;
		}
		else if(cpu_process_id >= 3 && cpu_process_id < 6)
        {
            cpu_speedo_id = 10;
        }
	}

    if(cpu_speedo_id == 0)
    {

    }
    else if(cpu_speedo_id == 1)
    {

    }
    else if(cpu_speedo_id == 2)
    {

    }
    else if(cpu_speedo_id == 3)
    {

    }
    else if(cpu_speedo_id == 4)
    {

    }
    else if(cpu_speedo_id == 5)
    {

    }
    else if(cpu_speedo_id == 6)
    {

    }
    else if(cpu_speedo_id == 7)
    {

    }
    else if(cpu_speedo_id == 8)
    {

    }
    else if(cpu_speedo_id == 9)
    {

    }
    else if(cpu_speedo_id == 10)
    {

    }
    else if(cpu_speedo_id == 11)
    {

    }
}

void log_logcat_option();
void log_dmesg_option();
void log_last_kmsg_option();
void log_kmsg_option();
void log_recovery_logcat();

void log_archive_mac();

void log_cpu_min_frequency();
void log_cpu_max_frequency();

void log_recovery();

void reboot_recovery();
void reboot_bootloader();
void reboot_download();
void reboot();
void shutdown();

void html_logcat();
void html_dmesg();
void html_kmsg();
void html_last_kmsg();
