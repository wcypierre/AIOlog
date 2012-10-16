#include <iostream>
#include <cstring>
#include <cstdlib>

removed output to sdcard(as it can't be done via adb automatically)

#ifdef __unix__
    const int separator_status = 1;
    const char separator[] = "./";
#elif defined WIN32
    const int separator_status = 0;
    const char separator[] = "";
#else
    const int separator_status = 1;
    const char separator[] = "./";
#endif

using namespace std;

void log_all();
void log_logcat();
void log_last_kmsg();
void log_dmesg();
void log_kmsg();
void log_kernel_version();

void help();

int main(int argc, char ** argv)
{
    char selection;
    char device_id[25];
    device_id[0] = '\0';

    char command[100];

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb kill-server");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb kill-server");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb start-server");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb start-server");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, separator);
        strcat(command, "adb remount");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb remount");
    }

    system(command);

    if(argc > 1)
    {
        cout << argc << endl;

        if(strcmp(argv[1], "--device-id") == 0 || strcmp(argv[1], "-id") == 0)
        {
            if(argv[2] != '\0')
            {
                strcpy(device_id, argv[2]);
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

    if(separator_status == 0)
    {
        strcpy(command, "adb -d shell uname -a");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb -d shell uname -a");
    }

    cout << "Command: " << command << endl;

    int device_availability = system(command);

    cout << endl << device_availability << endl;

    if(argc == 0)
    {
        cout << "Please include the parameters and try again" << endl;

        return -1;
    }

    if(separator_status == 0)
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
                    cout << "*************************************************" << endl;
                    cout << "*            AIOlog - All in One Logger         *" << endl;
                    cout << "*                  Version: 0.1                 *" << endl;
                    cout << "*              By: wcypierre - xda              *" << endl;
                    cout << "*************************************************" << endl << endl;

                    if(separator_status == 0)
                    {
                        strcpy(command, "adb devices");
                    }
                    else if(separator_status == 1)
                    {
                        strcpy(command, separator);
                        strcat(command, "adb devices");
                    }

                    system(command);

                    cout << endl;

                    cout << "Please enter your Device ID: ";
                    cin.getline(device_id, 25);

                    if(separator_status == 0)
                    {
                        strcpy(command, "adb -s ");
                        strcat(command, device_id);
                        strcat(command, " shell uname -a");
                    }
                    else if(separator_status == 1)
                    {
                        strcpy(command, separator);
                        strcat(command, "adb -s ");
                        strcat(command, device_id);
                        strcat(command, " shell uname -a");
                    }

                    device_status = system(command);

                    if(separator_status == 0)
                    {
                        system("cls");
                    }
                    else
                    {
                        system("clear");
                    }
                }while(strlen(device_id) == 0 || device_status == -1);

            }
            else
            {
                cout << "*************************************************" << endl;
                cout << "*            AIOlog - All in One Logger         *" << endl;
                cout << "*                  Version: 0.1                 *" << endl;
                cout << "*              By: wcypierre - xda              *" << endl;
                cout << "*************************************************" << endl << endl;
            }

            cout << "Device Model: ";

            if(separator_status == 0)
            {
                if(device_id[0] == '\0')
                {
                    strcpy(command, "adb shell getprop ro.product.model");
                }
                else
                {
                    strcpy(command, "adb -s ");
                    strcat(command, device_id);
                    strcat(command, " shell getprop ro.product.model");
                }
            }
            else if(separator_status == 1)
            {
                if(device_id[0] == '\0')
                {
                    strcpy(command, separator);
                    strcat(command, "adb shell getprop ro.product.model");
                }
                else
                {
                    strcpy(command, separator);
                    strcat(command, "adb -s ");
                    strcat(command, device_id);
                    strcat(command, " shell getprop ro.product.model");
                }
            }

            system(command);

            cout << endl;

            cout << "Functions: " << endl;
            cout << "1. Log all(Logcat, last_kmsg, dmesg, kmsg)" << endl;
            cout << "2. Logcat" << endl;
            cout << "3. Last_Kmsg" << endl;
            cout << "4. Dmesg" << endl;
            cout << "5. Kmsg" << endl;
            cout << "6. Kernel Version" << endl;
            cout << "7. Quit" << endl << endl;

            do
            {
                cout << "Please enter your selection: ";
                cin  >> selection;

                if(selection != '1' && selection != '2' && selection != '3' && selection != '4'  && selection != '5' && selection != '6' && selection != '7')
                {
                    cout << "Invalid selection, please try again" << endl;
                }
            }while(selection != '1' && selection != '2' && selection != '3' && selection != '4'  && selection != '5' && selection != '6' && selection != '7');

            if(selection == '1')
            {
                log_all();
            }
            else if(selection == '2')
            {
                log_logcat();
            }
            else if(selection == '3')
            {
                log_last_kmsg();
            }
            else if(selection == '4')
            {
                log_dmesg();
            }
            else if(selection == '5')
            {
                log_kmsg();
            }
            else if(selection == '6')
            {
                log_kernel_version();
            }
            else if(selection == '7')
            {

            }

            if(selection != '7')
            {
                cout << endl << "Press enter to continue" << endl;

                cin.get();
                cin.get();

                if(separator_status == 0)
                {
                    system("cls");
                }
                else
                {
                    system("clear");
                }
            }
        }while(selection != '7');
    }

    if(separator_status == 0)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }

    cout << "Killing adb............" << endl;

    if(separator_status == 0)
    {
        strcpy(command, "adb kill-server");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb kill-server");
    }

    system(command);

    cin.get();

    return 0;
}

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
        strcpy(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    if(separator_status == 0)
    {
        strcpy(command, "adb logcat -d -v long > logcat.txt");
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
        strcpy(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    if(separator_status == 0)
    {
        strcpy(command, "adb shell cat /proc/last_kmsg > last_kmsg.txt");
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
        strcpy(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    if(separator_status == 0)
    {
        strcpy(command, "adb shell dmesg > dmesg.txt");
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
        strcpy(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, "adb shell cat /proc/kmsg > kmsg.txt");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb shell cat /proc/kmsg > kmsg.txt");
    }

    system(command);

    cout << "kmsg saved at kmsg.txt" << endl;
}

void log_kernel_version()
{
    char command[100];

    cout << endl;

    strcpy(command, "adb wait-for-device");
    }
    else if(separator_status == 1)
    {
        strcpy(command, separator);
        strcat(command, "adb wait-for-device");
    }

    system(command);

    if(separator_status == 0)
    {
        strcpy(command, "adb shell uname -a > kernel_version.txt");
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
