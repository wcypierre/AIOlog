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
#include <cstring>
#include <cstdlib>
#include "log.h"

using namespace std;

void log_all()
{
    log_logcat();
    log_dmesg();
    log_last_kmsg();
    log_kmsg();
}

void log_logcat()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -d -v threadtime > logcat.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -d -v threadtime > logcat.txt");
    }

    system(command);

    cout << "Logcat saved at logcat.txt" << endl;
}

void log_logcat_continuous()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    cout << "Logcat will be saved at logcat.txt" << endl;
    cout << "Please press CTRL and C to close the program and stop the logging" << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -v long > logcat.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -v long > logcat.txt");
    }

    system(command);
}

void log_logcat_radio()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    cout << "Logcat for radio issues will be saved at logcat_radio.txt" << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -d -v threadtime -b radio > logcat_radio.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -d -v threadtime -b radio > logcat_radio.txt");
    }

    system(command);
}

void log_last_kmsg()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat /proc/last_kmsg > last_kmsg.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat /proc/last_kmsg > last_kmsg.txt");
    }

    system(command);

    cout << "last_kmsg saved at last_kmsg.txt" << endl;
}

void log_dmesg()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb shell dmesg > dmesg.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb shell dmesg > dmesg.txt");
    }

    system(command);

    cout << "dmesg saved at dmesg.txt" << endl;
}

void log_kmsg()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat -f /proc/kmsg > kmsg.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat -f /proc/kmsg > kmsg.txt");
    }

    system(command);

    cout << "kmsg saved at kmsg.txt" << endl;
}

void log_kmsg_continuous()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    cout << "kmsg will be saved at kmsg.txt" << endl;
    cout << "Please press CTRL and C to close the program and stop the logging" << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat /proc/kmsg > kmsg.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat /proc/kmsg > kmsg.txt");
    }

    system(command);
}

void header()
{
    cout << "*************************************************" << endl;
    cout << "*            AIOlog - All in One Logger         *" << endl;
    cout << "*                  Version: 0.2                 *" << endl;
    cout << "*              By: wcypierre - xda              *" << endl;
    cout << "*************************************************" << endl << endl;
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
    cout << "B. Back to Main Menu" << endl;
}

void log_kernel_version()
{
    char command[100];

    cout << endl;

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb shell uname -a > kernel_version.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb shell uname -a > kernel_version.txt");
    }

    system(command);

    cout << "Kernel Version is saved at kernel_version.txt" << endl;
}

void set_device_id(char * device_id)
{
    char command[100];
    char temp_device_id[25];
    int device_status = -1;

    cin.clear();
    cin.ignore(100, '\n');

    do
    {
        cout << "*****************" << endl;
        cout << "* Set Device ID *" << endl;
        cout << "*****************" << endl;

        if(separator_status == 0)
        {
            strcpy(command, separator);
            strcat(command, "adb devices");
        }
        else if(separator_status == 1)
        {
            strcpy(command, separator);
            strcat(command, "adb devices");
        }

        system(command);

        cout << endl;

        cout << "Please enter your Device ID: ";
        cin.getline(temp_device_id, 25);

        if(temp_device_id[0] != '\0')
        {
            if(separator_status == 0)
            {
                strcpy(command, separator);
                strcat(command, "adb -s ");
                strcat(command, temp_device_id);
                strcat(command, " shell uname -a");
            }
            else if(separator_status == 1)
            {
                strcpy(command, separator);
                strcat(command, "adb -s ");
                strcat(command, temp_device_id);
                strcat(command, " shell uname -a");
            }

            device_status = system(command);
        }

        if(separator_status == 0)
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
        strcpy(device_id, temp_device_id);
    }
}

void log_archive_win();
void log_archive_linux();
void log_archive_mac();
