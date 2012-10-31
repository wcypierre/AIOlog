/*
 *   main.cpp
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

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "log.h"

using namespace std;

int main(int argc, char ** argv)
{
    char selection;
    string device_id;
    device_id[0] = '\0';

    string command;
    char misc_selection;

    int device_availability;

    adb_start_server();

    /*
    if(argc > 1)
    {
        if(strcmp(argv[1], "--device-id") == 0 || strcmp(argv[1], "-id") == 0)
        {
            if(argv[2] != '\0')
            {
                //strcpy(device_id, argv[2]);
            }

            if(strcmp(argv[2], "--all") == 0 || strcmp(argv[2], "-a") == 0)
            {
                log_all();
            }
            else if(strcmp(argv[2], "--help") == 0 || strcmp(argv[2], "-h"))
            {
                help();
            }
            else
            {
                int log_all_status = 0;

                for(int index = 2; index < argc; index++)
                {
                    if(strcmp(argv[index], "--all") == 0 || strcmp(argv[index], "-a") == 0)
                    {
                        log_all();

                        log_all_status = 1;
                    }
                }

                if(log_all_status == 0)
                {
                    for(int index = 2; index < argc; index++)
                    {
                        if(strcmp(argv[index], "--logcat") == 0 || strcmp(argv[index], "-l") == 0 || strcmp(argv[index], "--last-kmsg") == 0 || strcmp(argv[index], "-lk") == 0 || strcmp(argv[index], "--kmsg") == 0 || strcmp(argv[index], "-k") == 0 || strcmp(argv[index], "--dmesg") == 0 || strcmp(argv[index], "-d") == 0 || strcmp(argv[index], "--kernel-version") == 0 || strcmp(argv[index], "-kv") == 0)
                        {
                            if(strcmp(argv[index], "--logcat") == 0 || strcmp(argv[index], "-l") == 0)
                            {
                                log_logcat();
                            }
                            else if(strcmp(argv[index], "--last-kmsg") == 0 || strcmp(argv[index], "-lk") == 0)
                            {
                                log_last_kmsg();
                            }
                            else if(strcmp(argv[index], "--kmsg") == 0 || strcmp(argv[index], "-k") == 0)
                            {
                                log_kmsg();
                            }
                            else if(strcmp(argv[index], "--dmesg") == 0 || strcmp(argv[index], "-d") == 0)
                            {
                                log_dmesg();
                            }
                            else if(strcmp(argv[index], "--kernel-version") == 0 || strcmp(argv[index], "-kv") == 0)
                            {
                                log_kernel_version();
                            }
                        }
                    }
                }
            }
        }
        else
        {
            int log_all_status = 0;

            if(argc == 2)
            {
                if(strcmp(argv[1], "--all") == 0 || strcmp(argv[1], "-a") == 0)
                {
                    log_all();
                }
                else if(strcmp(argv[1], "--logcat") == 0 || strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--last-kmsg") == 0 || strcmp(argv[1], "-lk") == 0 || strcmp(argv[1], "--kmsg") == 0 || strcmp(argv[1], "-k") == 0 || strcmp(argv[1], "--dmesg") == 0 || strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--kernel-version") == 0 || strcmp(argv[1], "-kv") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
                {
                    if(strcmp(argv[1], "--logcat") == 0 || strcmp(argv[1], "-l") == 0)
                    {
                        log_logcat();
                    }
                    else if(strcmp(argv[1], "--last-kmsg") == 0 || strcmp(argv[1], "-lk") == 0)
                    {
                        log_last_kmsg();
                    }
                    else if(strcmp(argv[1], "--kmsg") == 0 || strcmp(argv[1], "-k") == 0)
                    {
                        log_kmsg();
                    }
                    else if(strcmp(argv[1], "--dmesg") == 0 || strcmp(argv[1], "-d") == 0)
                    {
                        log_dmesg();
                    }
                    else if(strcmp(argv[1], "--kernel-version") == 0 || strcmp(argv[1], "-kv") == 0)
                    {
                        log_kernel_version();
                    }
                    else if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
                    {
                        help();
                    }
                }
            }

            for(int index = 1; index < argc; index++)
            {
                if(strcmp(argv[index], "--all") == 0 || strcmp(argv[index], "-a") == 0)
                {
                    log_all();

                    log_all_status = 1;
                }
            }

            if(log_all_status == 0)
            {
                for(int index = 2; index < argc; index++)
                {
                    if(strcmp(argv[index], "--logcat") == 0 || strcmp(argv[index], "-l") == 0 || strcmp(argv[index], "--last-kmsg") == 0 || strcmp(argv[index], "-lk") == 0 || strcmp(argv[index], "--kmsg") == 0 || strcmp(argv[index], "-k") == 0 || strcmp(argv[index], "--dmesg") == 0 || strcmp(argv[index], "-d") == 0 || strcmp(argv[index], "--kernel-version") == 0 || strcmp(argv[index], "-kv") == 0)
                    {
                        if(strcmp(argv[index], "--logcat") == 0 || strcmp(argv[index], "-l") == 0)
                        {
                            log_logcat();
                        }
                        else if(strcmp(argv[index], "--last-kmsg") == 0 || strcmp(argv[index], "-lk") == 0)
                        {
                            log_last_kmsg();
                        }
                        else if(strcmp(argv[index], "--kmsg") == 0 || strcmp(argv[index], "-k") == 0)
                        {
                            log_kmsg();
                        }
                        else if(strcmp(argv[index], "--dmesg") == 0 || strcmp(argv[index], "-d") == 0)
                        {
                            log_dmesg();
                        }
                        else if(strcmp(argv[index], "--kernel-version") == 0 || strcmp(argv[index], "-kv") == 0)
                        {
                            log_kernel_version();
                        }
                    }
                }
            }
        }

        if(strcmp(argv[1], "--device-id") != 0 && strcmp(argv[1], "-d") != 0)
        {
            if(argc > 2)
            {
                strcpy(device_id, argv[2]);
            }
        }
    }
    */

    command.clear();

    if(os_type == 0)
    {
        command.append(separator);
        command.append("adb -d shell uname -a");
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append("adb -d shell uname -a");
    }

    device_availability = system(command.c_str());

    command.clear();

    if(argc == 0)
    {
        cout << "Please include the parameters and try again" << endl;

        return -1;
    }

    if(os_type == 0)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }

    if(argc <= 1)
    {
        do
        {
            if(device_availability == -1)
            {
                int device_status = -1;

                do
                {
                    header();

                    command.clear();

                    adb_devices();

                    cout << endl;

                    cout << "Please enter your Device ID: ";
                    getline(cin, device_id);

                    if(device_id[0] != '\0')
                    {
                        if(os_type == 0)
                        {
                            command.append(separator);
                            command.append("adb -s ");
                            command.append(device_id);
                            command.append(" shell uname -a");
                        }
                        else if(os_type == 1)
                        {
                            command.append(separator);
                            command.append("adb -s ");
                            command.append(device_id);
                            command.append(" shell uname -a");
                        }

                        device_status = system(command.c_str());
                    }

                    command.clear();

                    if(os_type == 0)
                    {
                        system("cls");
                    }
                    else
                    {
                        system("clear");
                    }
                }while(device_status == -1);

                device_availability = 1; // Disable reprompt of Device ID after the Device ID has been entered

                header();
            }
            else
            {
                header();
            }

            cout << "Device Model: ";

            command.clear();

            if(os_type == 0)
            {
                if(device_id[0] == '\0')
                {
                    command.append(separator);
                    command.append("adb shell getprop ro.product.model");
                }
                else
                {
                    command.append(separator);
                    command.append("adb -s ");
                    command.append(device_id);
                    command.append(" shell getprop ro.product.model");
                }
            }
            else if(os_type == 1)
            {
                if(device_id[0] == '\0')
                {
                    command.append(separator);
                    command.append("adb shell getprop ro.product.model");
                }
                else
                {
                    command.append(separator);
                    command.append("adb -s ");
                    command.append(device_id);
                    command.append(" shell getprop ro.product.model");
                }
            }

            system(command.c_str());

            command.clear();

            cout << endl;

            cout << "Functions: " << endl;
            cout << "1. Log Essential(Logcat, last_kmsg, dmesg, kmsg)" << endl;
            cout << "2. Logcat" << endl;
            cout << "3. Logcat Continuous" << endl;
            cout << "4. Last_Kmsg" << endl;
            cout << "5. Dmesg" << endl;
            cout << "6. Kmsg" << endl;
            cout << "7. Kmsg Continuous" << endl;
            cout << "M. Miscellaneous" << endl;
            cout << "S. Settings" << endl;
            cout << "A. Advanced" << endl;
            cout << "Q. Quit" << endl << endl;

            do
            {
                cout << "Please enter your selection: ";
                cin  >> selection;

                if(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6' && selection != '7' && selection != 'm' && selection != 'M' && selection != 's' && selection != 'S' && selection != 'a' && selection != 'A' && selection != 'q' && selection != 'Q')
                {
                    cout << "Invalid selection, please try again" << endl;
                }
            }while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6' && selection != '7' && selection != 'm' && selection != 'M' && selection != 's' && selection != 'S' && selection != 'a' && selection != 'A' && selection != 'q' && selection != 'Q');

            if(selection == '1')
            {
                log_essential();
            }
            else if(selection == '2')
            {
                log_logcat();
            }
            else if(selection == '3')
            {
                log_logcat_continuous();
            }
            else if(selection == '4')
            {
                log_last_kmsg();
            }
            else if(selection == '5')
            {
                log_dmesg();
            }
            else if(selection == '6')
            {
                log_kmsg();
            }
            else if(selection == '7')
            {
                log_kmsg_continuous();
            }
            else if(selection == 's' || selection == 'S')
            {
                settings_options();

                do
                {
                    cout << endl << "Please enter your selection: ";
                    cin  >> misc_selection;

                    if(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B')
                    {
                        cout << "Invalid selection, please try again by selecting the number of the option" << endl;
                    }
                }while(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B');

                if(misc_selection == '1')
                {
                    cout << "Before: " << device_id << endl;

                    set_device_id(device_id);

                    cout << "After: " << device_id << endl;
                }
            }
            else if(selection == 'm' || selection == 'M')
            {
                misc_options();

                do
                {
                    cout << endl << "Please enter your selection: ";
                    cin  >> misc_selection;

                    if(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B')
                    {
                        cout << "Invalid selection, please try again by selecting the number of the option" << endl;
                    }
                }while(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B');

                if(misc_selection == '1')
                {
                    log_kernel_version();
                }
            }
            else if(selection == 'a' || selection == 'A')
            {
                advanced_options();

                do
                {
                    cout << endl << "Please enter your selection: ";
                    cin  >> misc_selection;

                    if(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B')
                    {
                        cout << "Invalid selection, please try again by selecting the number of the option" << endl;
                    }
                }while(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B');

                if(misc_selection == '1')
                {
                    log_logcat_radio();
                }
            }
            else if(selection == 'q' || selection == 'Q')
            {

            }

            if(selection != 'q' && selection != 'Q')
            {
                cout << endl << "Press enter to continue" << endl;

                cin.get();
                cin.get();
            }

            if(os_type == 0)
            {
                system("cls");
            }
            else
            {
                system("clear");
            }
        }while(selection != 'q' && selection != 'Q');
    }

    if(os_type == 0)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }

    return 0;
}
