/* 
log.cpp
This file contains all the codes to log information from an android device

Copyright (c) 2012, wcypierre <wcypierre@gmail.com>

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
        strcat(command, "adb logcat -d -v long > logcat.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb logcat -d -v long > logcat.txt");
    }

    system(command);

    cout << "Logcat saved at logcat.txt" << endl;
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

void log_archive_win();
void log_archive_linux();
void log_archive_mac();
