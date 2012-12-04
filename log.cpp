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

using namespace std;

void log_essential()
{
    log_logcat();
    log_dmesg();
    log_last_kmsg();
    log_kmsg();

    log_archive("log_essential");
}

void log_all()
{
    log_logcat();
    log_dmesg();
    log_last_kmsg();
    log_kmsg();
    log_kernel_version();
}

void log_logcat()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -d -v threadtime > logcat.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -d -v threadtime > logcat.txt");
    }

    system(command.c_str());

    cout << "Logcat saved at logcat.txt" << endl;

    dir_create();
    log_push("logcat.txt", "/mnt/sdcard/logcat.txt");
    log_push("logcat.txt", "/mnt/sdcard/.aiolog/logcat.txt");
    log_push("logcat.txt", "/mnt/sdcard/aiolog/logcat.txt");

    log_archive("logcat");

    command.clear();
}

void log_logcat_continuous()
{
    string command;

    cout << endl;

    wait_for_device();

    cout << "Logcat will be saved at logcat.txt" << endl
         << "Please press CTRL and C to close the program and stop the logging" << endl;

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -v threadtime > logcat.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -v threadtime > logcat.txt");
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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -d -v threadtime -b radio > logcat_radio.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -d -v threadtime -b radio > logcat_radio.txt");
    }

    system(command.c_str());

    cout << "Logcat for radio issues will be saved at logcat_radio.txt" << endl;

    dir_create();
    log_push("logcat_radio.txt", "/mnt/sdcard/logcat_radio.txt");
    log_push("logcat_radio.txt", "/mnt/sdcard/.aiolog/logcat_radio.txt");
    log_push("logcat_radio.txt", "/mnt/sdcard/aiolog/logcat_radio.txt");

    log_archive("logcat_radio");

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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -c");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" logcat -c");
    }

    system(command.c_str());

    cout << "Logcat is cleared" << endl;

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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell dmesg -c > .tmp");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell dmesg -c > .tmp");
    }

    system(command.c_str());

    cout << "Dmesg is cleared" << endl;

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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell cat /proc/last_kmsg > last_kmsg.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell cat /proc/last_kmsg > last_kmsg.txt");
    }

    system(command.c_str());

    cout << "last_kmsg saved at last_kmsg.txt" << endl;

    dir_create();
    log_push("last_kmsg.txt", "/mnt/sdcard/last_kmsg.txt");
    log_push("last_kmsg.txt", "/mnt/sdcard/.aiolog/last_kmsg.txt");
    log_push("last_kmsg.txt", "/mnt/sdcard/aiolog/last_kmsg.txt");

    log_archive("last_kmsg");

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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell dmesg > dmesg.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell dmesg > dmesg.txt");
    }

    system(command.c_str());

    cout << "dmesg saved at dmesg.txt" << endl;

    dir_create();
    log_push("dmesg.txt", "/mnt/sdcard/dmesg.txt");
    log_push("dmesg.txt", "/mnt/sdcard/.aiolog/dmesg.txt");
    log_push("dmesg.txt", "/mnt/sdcard/aiolog/dmesg.txt");

    log_archive("dmesg");

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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell cat -f /proc/kmsg > kmsg.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell cat -f /proc/kmsg > kmsg.txt");
    }

    system(command.c_str());

    cout << "kmsg saved at kmsg.txt" << endl;

    dir_create();
    log_push("kmsg.txt", "/mnt/sdcard/kmsg.txt");
    log_push("kmsg.txt", "/mnt/sdcard/.aiolog/kmsg.txt");
    log_push("kmsg.txt", "/mnt/sdcard/aiolog/kmsg.txt");

    log_archive("kmsg");

    command.clear();
}

void log_kmsg_continuous()
{
    string command;

    cout << endl;

    wait_for_device();

    cout << "kmsg will be saved at kmsg.txt" << endl;
    cout << "Please press CTRL and C to close the program and stop the logging" << endl;

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell cat /proc/kmsg > kmsg.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell cat /proc/kmsg > kmsg.txt");
    }

    system(command.c_str());
}

void log_push(std::string from, std::string to)
{
    string command;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" push ");
        command.append(from);
        command.append(" ");
        command.append(to);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" push ");
        command.append(from);
        command.append(" ");
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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell mkdir -p /mnt/sdcard/aiolog");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell mkdir -p /mnt/sdcard/aiolog");
    }

    system(command.c_str());

    command.clear();

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell mkdir -p /mnt/sdcard/.aiolog");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell mkdir -p /mnt/sdcard/.aiolog");
    }

    system(command.c_str());
}

void log_archive(std::string option)
{
    string archive_filename;
    string input_filename;

    if(option.compare("logcat") == 0)
    {
        archive_filename = "logcat";
        input_filename = "logcat.txt";
    }
    else if(option.compare("last_kmsg") == 0)
    {
        archive_filename = "last_kmsg";
        input_filename = "last_kmsg.txt";
    }
    else if(option.compare("dmesg") == 0)
    {
        archive_filename = "dmesg";
        input_filename = "dmesg.txt";
    }
    else if(option.compare("kmsg") == 0)
    {
        archive_filename = "kmsg";
        input_filename = "kmsg.txt";
    }
    else if(option.compare("log_essential") == 0)
    {
        archive_filename = "log_essential";
        input_filename = "logcat.txt kmsg.txt dmesg.txt last_kmsg.txt";
    }
    else if(option.compare("log_all") == 0)
    {
        archive_filename = "log_all";
        //input_filename = "logcat.txt kmsg.txt dmesg.txt last_kmsg.txt"; to be added
    }
    else if(option.compare("last_kmsg") == 0)
    {
        archive_filename = "last_kmsg";
        input_filename = "last_kmsg.txt";
    }
    else if(option.compare("logcat_radio") == 0)
    {
        archive_filename = "logcat_radio";
        input_filename = "logcat_radio.txt";
    }
    else if(option.compare("kernel_version") == 0)
    {
        archive_filename = "kernel_version";
        input_filename = "kernel_version.txt";
    }

    if(os_type == 0)
    {
    	archive_filename.append(".zip");

        log_archive_win(archive_filename, input_filename);
    }
    else if(os_type == 1)
    {
    	archive_filename.append(".tar");

        log_archive_linux(archive_filename, input_filename);
    }
}

void log_archive_linux(std::string archive_filename, std::string input_filename)
{
    string command;
    string archive_command;

    string remote_root_filename = "/mnt/sdcard/";
    string remote_aiolog_filename = "/mnt/sdcard/";
    string remote_dot_aiolog_filename = "/mnt/sdcard/";

    cout << endl;

    remote_root_filename.append(archive_filename);

    remote_aiolog_filename.append("aiolog/");
    remote_aiolog_filename.append(archive_filename);

    remote_aiolog_filename.append(".aiolog/");
    remote_aiolog_filename.append(archive_filename);

    archive_command.append("tar cvf ");
    archive_command.append(archive_filename);
    archive_command.append(" ");
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

    string remote_root_filename = "/mnt/sdcard/";
    string remote_aiolog_filename = "/mnt/sdcard/";
    string remote_dot_aiolog_filename = "/mnt/sdcard/";

    cout << endl;

    remote_root_filename.append(archive_filename);

    remote_aiolog_filename.append("aiolog/");
    remote_aiolog_filename.append(archive_filename);

    remote_aiolog_filename.append(".aiolog/");
    remote_aiolog_filename.append(archive_filename);

    archive_command.append("7za a -tzip ");
    archive_command.append(archive_filename);
    archive_command.append(" ");
    archive_command.append(input_filename);
    archive_command.append(" -mmt -aot -y");

    system(archive_command.c_str());

    log_push(archive_filename, remote_root_filename);
    log_push(archive_filename, remote_aiolog_filename);
    log_push(archive_filename, remote_dot_aiolog_filename);
}

void header()
{
    cout << "**********************************************************" << endl;
    cout << "*              AIOlog - All in One Android Logger        *" << endl;
    cout << "*                         Version: 0.7                   *" << endl;
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

    cout << endl << "Press enter to continue" << endl;
    cin.get();
}

void misc_options()
{
    cout << "1. Kernel Version" << endl;
    cout << "2. CID Version" << endl;
    cout << "B. Back to Main Menu" << endl;
}

void settings_options()
{
    cout << "1. Set Device ID" << endl;
    cout << "B. Back to Main Menu" << endl;
}

void advanced_options()
{
    cout << "1. Logcat Radio" << endl;
    cout << "2. Logcat Clear" << endl;
    cout << "3. Dmesg Clear" << endl;
    cout << "B. Back to Main Menu" << endl;
}

void log_kernel_version()
{
    string command;

    cout << endl;

    wait_for_device();

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell uname -a > kernel_version.txt");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" shell uname -a > kernel_version.txt");
    }

    system(command.c_str());

    cout << "Kernel Version is saved at kernel_version.txt" << endl;

    log_archive("kernel_version");

    command.clear();
}

void log_cid_version()
{
    string command;

    string temp_buffer;
    char buffer[50];

    size_t found;

    command.append("adb -s ");
    command.append(device_id);
    command.append(" shell getprop ro.cid");

    FILE * cid = popen(command.c_str(), "r");

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

        if(temp_buffer.compare("error: device not found") == 0)
        {
            cout << "Device Not found" << endl << endl;
        }
        else if(temp_buffer.compare("") == 0)
        {
            cout << "AIOlog [Error]: Invalid CID location, please contact me via xda or my email @ wcypierre@gmail.com and provide me with your Device name" << endl << endl;
        }
        else
        {
            cout << "CID Version: " << temp_buffer << endl << endl;
        }
    }

    pclose(cid);
}

void set_device_id(string & device_id)
{
    string command;
    string temp_device_id;
    int device_status = -1;

    cin.clear();
    cin.ignore(100, '\n');

    do
    {
        command.clear();

        cout << "*****************" << endl;
        cout << "* Set Device ID *" << endl;
        cout << "*****************" << endl;

        if(os_type == 0)
        {
            command.append(separator);
            command.append("adb devices");
        }
        else if(os_type == 1)
        {
            command.append(separator);
            command.append("adb devices");
        }

        system(command.c_str());

        cout << endl;

        cout << "Please enter your Device ID: ";
        getline(cin, temp_device_id);

        command.clear();

        if(temp_device_id[0] != '\0')
        {
            if(os_type == 0)
            {
                command.append(separator);
                command.append("adb -s ");
                command.append(temp_device_id);
                command.append(" shell uname -a");
            }
            else if(os_type == 1)
            {
                command.append(separator);
                command.append("adb -s ");
                command.append(temp_device_id);
                command.append(" shell uname -a");
            }

            device_status = system(command.c_str());
        }

        if(os_type == 0)
        {
            system("cls");
        }
        else
        {
            system("clear");
        }
    }while(device_status == 1);

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
        command.append("adb start-server");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb start-server");
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
        command.append("adb -s ");
        command.append(device_id);
        command.append(" wait-for-device");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -s ");
        command.append(device_id);
        command.append(" wait-for-device");
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
        command.append("adb devices");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb devices");
    }

    system(command.c_str());

    command.clear();
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
