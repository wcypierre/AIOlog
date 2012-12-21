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
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "log.h"
#include "lang.h"
#include "error.h"

using namespace std;

string device_id;

int main(int argc, char ** argv)
{
    char selection;

    device_id[0] = '\0';

    string command;
    char misc_selection;

    int device_availability;

    int device_status;

    size_t found;

    char buffer[BUFFER_SIZE];
    string temp_buffer;

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
        command.append(ADB_GET_SERIAL_NO);
    }
    else if(os_type == 1)
    {
        command.append(separator);
        command.append(ADB_GET_SERIAL_NO);
    }

    FILE * serial_no = popen(command.c_str(), READ_MODE);

    if(serial_no != NULL)
    {
        while(fgets(buffer, sizeof(buffer), serial_no) != NULL)
        {

        }
    }

    pclose(serial_no);

    temp_buffer.assign(buffer);

    found = temp_buffer.find(NEWLINE);

    if(found != string::npos)
    {
        temp_buffer.erase(int(found));
    }

    if(temp_buffer.compare(DEVICE_NOT_FOUND_INDICATOR) == 0)
    {
        device_availability = -1;
    }
    else
    {
        device_availability = 1;

        device_id.assign(temp_buffer);
    }

    if(argc == 0)
    {
        cout << EN_PARAMETER_ERROR_MSG << endl;

        return -1;
    }

    clear_screen();

    if(argc <= 1)
    {
        do
        {
            if(device_availability == -1)
            {
                device_status = -1;

                do
                {
                    header();

                    command.clear();

                    adb_devices();

                    cout << endl;

                    cout << EN_DEVICE_ID_PROMPT;
                    getline(cin, device_id);

                    FILE * serial_no = popen(ADB_GET_SERIAL_NO, READ_MODE);

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
                            device_id = temp_buffer;
                            device_status = 1;
                        }
                    }

                    pclose(serial_no);

                    command.clear();

                    if(os_type == 0)
                    {
                        command.append(separator);
                        command.append(ADB_WITH_DEVICE_ID);
                        command.append(device_id);
                        command.append(GET_SERIAL_NO);
                    }
                    else if(os_type == 1)
                    {
                        command.append(separator);
                        command.append(ADB_WITH_DEVICE_ID);
                        command.append(device_id);
                        command.append(GET_SERIAL_NO);
                    }

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

                    command.clear();

                    clear_screen();
                }while(device_status == -1);

                device_availability = 1; // Disable reprompt of Device ID after the Device ID has been entered

                header();
            }
            else
            {
                header();
            }

            cout << EN_DEVICE_MODEL_SHOW;

            command.clear();

            if(os_type == 0)
            {
                if(device_id[0] == '\0')
                {
                    command.append(separator);
                    command.append(ADB_GETPROP_PRODUCT_MODEL);
                }
                else
                {
                    command.append(separator);
                    command.append(ADB_WITH_DEVICE_ID);
                    command.append(device_id);
                    command.append(GETPROP_PRODUCT_MODEL);
                }
            }
            else if(os_type == 1)
            {
                if(device_id[0] == '\0')
                {
                    command.append(separator);
                    command.append(ADB_GETPROP_PRODUCT_MODEL);
                }
                else
                {
                    command.append(separator);
                    command.append(ADB_WITH_DEVICE_ID);
                    command.append(device_id);
                    command.append(GETPROP_PRODUCT_MODEL);
                }
            }

            system(command.c_str());

            command.clear();

            cout << endl;

            cout << EN_FUNCTIONS_SHOW << endl;
            cout << EN_MENU_OPTION_1 << endl;
            cout << EN_MENU_OPTION_2 << endl;
            cout << EN_MENU_OPTION_3 << endl;
            cout << EN_MENU_OPTION_4 << endl;
            cout << EN_MENU_OPTION_5 << endl;
            cout << EN_MENU_OPTION_6 << endl;
            cout << EN_MENU_OPTION_7 << endl;
            cout << EN_MENU_OPTION_MISCELLANEOUS << endl;
            cout << EN_MENU_OPTION_SETTINGS << endl;
            cout << EN_MENU_OPTION_ADVANCED << endl;
            cout << EN_MENU_OPTION_QUIT << endl << endl;

            do
            {
                cout << EN_SELECTION_INPUT_PROMPT;
                cin  >> selection;

                if(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6' && selection != '7' && selection != 'm' && selection != 'M' && selection != 's' && selection != 'S' && selection != 'a' && selection != 'A' && selection != 'q' && selection != 'Q')
                {
                    cout << EN_SELECTION_INVALID_MSG << endl;
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
                    cout << endl << EN_SELECTION_INPUT_PROMPT;
                    cin  >> misc_selection;

                    if(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B')
                    {
                        cout << EN_INMENU_OPTION_INVALID_MSG << endl;
                    }
                }while(misc_selection != '1' && misc_selection != 'b' && misc_selection != 'B');

                if(misc_selection == '1')
                {
                    cout << EN_DEVICE_ID_CURRENT_SHOW << device_id << endl << endl;

                    set_device_id(device_id);
                }
            }
            else if(selection == 'm' || selection == 'M')
            {
                misc_options();

                do
                {
                    cout << endl << EN_SELECTION_INPUT_PROMPT;
                    cin  >> misc_selection;

                    if(misc_selection != '1' && misc_selection != '2' && misc_selection != 'b' && misc_selection != 'B')
                    {
                        cout << EN_INMENU_OPTION_INVALID_MSG << endl;
                    }
                }while(misc_selection != '1' && misc_selection != '2' && misc_selection != 'b' && misc_selection != 'B');

                cout << endl;

                if(misc_selection == '1')
                {
                    log_kernel_version();
                }
                else if(misc_selection == '2')
                {
                    log_cid_version();

                    cout << EN_ENTER_TO_CONTINUE << endl;

                    cin.get();
                    cin.get();
                }
            }
            else if(selection == 'a' || selection == 'A')
            {
                advanced_options();

                do
                {
                    cout << endl << EN_SELECTION_INPUT_PROMPT;
                    cin  >> misc_selection;

                    if(misc_selection != '1' && misc_selection != '2' && misc_selection != '3' && misc_selection != 'b' && misc_selection != 'B')
                    {
                        cout << EN_INMENU_OPTION_INVALID_MSG << endl;
                    }
                }while(misc_selection != '1' && misc_selection != '2' && misc_selection != '3' && misc_selection != 'b' && misc_selection != 'B');

                if(misc_selection == '1')
                {
                    log_logcat_radio();
                }
                else if(misc_selection == '2')
                {
                    log_logcat_clear();
                }
                else if(misc_selection == '3')
                {
                    log_dmesg_clear();
                }
            }
            else if(selection == 'q' || selection == 'Q')
            {

            }

            if(selection != 'q' && selection != 'Q')
            {
                if(selection != 's' && selection != 'S' && selection != 'm' && selection != 'M' && selection != 'a' && selection != 'A')
                {
                    cout << endl << EN_ENTER_TO_CONTINUE << endl;

                    cin.get();
                    cin.get();
                }
            }

			clear_screen();
        }while(selection != 'q' && selection != 'Q');
    }

	clear_screen();

    return 0;
}
