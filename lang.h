#ifndef LANG_H
#define LANG_H

#include <string>

using namespace std;

const char EN_PARAMETER_ERROR_MSG[] = "Please include the parameters and try again";
const char EN_DEVICE_ID_PROMPT[] = "Please enter your Device ID: ";
const char EN_DEVICE_ID_SHOW[] = "Device ID: ";
const char EN_DEVICE_MODEL_SHOW[] = "Device Model: ";

const char EN_FUNCTIONS_SHOW[] = "Functions: ";
const char EN_MENU_OPTION_1[] = "1. Log Essential(Logcat, last_kmsg, dmesg, kmsg)";
const char EN_MENU_OPTION_2[] = "2. Logcat";
const char EN_MENU_OPTION_3[] = "3. Logcat Continuous";
const char EN_MENU_OPTION_4[] = "4. Last_Kmsg";
const char EN_MENU_OPTION_5[] = "5. Dmesg";
const char EN_MENU_OPTION_6[] = "6. Kmsg";
const char EN_MENU_OPTION_7[] = "7. Kmsg Continuous";
const char EN_MENU_OPTION_MISCELLANEOUS[] = "M. Miscellaneous";
const char EN_MENU_OPTION_SETTINGS[] = "S. Settings";
const char EN_MENU_OPTION_ADVANCED[] = "A. Advanced";
const char EN_MENU_OPTION_QUIT[] = "Q. Quit";

const char EN_SELECTION_INPUT_PROMPT[] = "Please enter your selection: ";
const char EN_SELECTION_INVALID_MSG[] = "Invalid selection, please try again";

const char EN_INMENU_OPTION_INVALID_MSG[] = "Invalid selection, please try again by selecting the number of the option";

const char EN_DEVICE_ID_CURRENT_SHOW[] = "Current Device ID: ";

const char EN_ENTER_TO_CONTINUE[] = "Press enter to continue";

const char LOGCAT_MESSAGE[] = "Logcat saved at logcat.txt";
const char LOGCAT_CONTINUOUS_MESSAGE[] = "Logcat will be saved at logcat.txt \nPlease press CTRL and C to close the program and stop the logging";
const char LOGCAT_RADIO_MESSAGE[] = "Logcat for radio issues will be saved at logcat_radio.txt";
const char LOGCAT_CLEAR_MESSAGE[] = "Logcat is cleared";

const char LAST_KMSG_MESSAGE[] = "last_kmsg saved at last_kmsg.txt";

const char KMSG_MESSAGE[] = "kmsg saved at kmsg.txt";
const char KMSG_CONTINUOUS_MESSAGE[] = "kmsg will be saved at kmsg.txt\nPlease press CTRL and C to close the program and stop the logging";

const char DMESG_MESSAGE[] = "dmesg saved at dmesg.txt";
const char DMESG_CLEAR_MESSAGE[] = "Dmesg is cleared";

const char KERNEL_VERSION_MESSAGE[] = "Kernel Version is saved at kernel_version.txt";

const char CID_MESSAGE[] = "CID Information is stored at cid.txt";

const char EN_PROGRAM_DESCRIPTION[] = "All in One Android Logger";

const char EN_PROGRAM_VERSION_SHOW[] = "Version: ";

const char EN_MISC_MENU_OPTION_1[] = "1. Kernel Version";
const char EN_MISC_MENU_OPTION_2[] = "2. CID Version";

const char EN_SETTINGS_MENU_OPTION_1[] = "1. Set Device ID";

const char EN_ADVANCED_MENU_OPTION_1[] = "1. Logcat Radio";
const char EN_ADVANCED_MENU_OPTION_2[] = "2. Logcat Clear";
const char EN_ADVANCED_MENU_OPTION_3[] = "3. Dmesg Clear";

const char EN_INMENU_OPTION_BACK[] = "B. Back to Main Menu";

const char EN_DEVICE_NOT_FOUND[] = "Device Not found";

const char EN_CID_VERSION_SHOW[] = "CID Version: ";

const char EN_SET_DEVICE_ID[] = "*****************\n* Set Device ID *\n*****************\n";

#endif
