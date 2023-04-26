#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
enum Category { POSITIVE,
                CLOSE_CONTACT,
                SUSPECTED,
                TRAVEL_HISTORY,
                LOW_RISK };
// structure used for capturing data about users
struct User {
    string username;
    string password;
    string name;
    int age;
    string address;
    string phone;
    string IC;
    Category category;
    string testdate;
};

// Function prototypes
void registration(vector<User> &users);
void login(vector<User> &users);
void reminder(vector<User> &users, string name);
void viewcategory(vector<User> &users, string name);
void takeTest(vector<User> &users, string name);
int categoryToInt(Category category);
bool isValidDate(const string &dateStr);
void update_profile(User *p_user);

void saveUsersToFile(string filename, vector<User> *users);
void view_profile(User *user);
void updateCategory(vector<User> &users, int index, int daysSinceTest, string name);
bool negative(vector<User> &users, string name);
bool result;
bool datamodified;
bool check;

vector<User> users;

int main() {
    // Initialize the vector of users with our sample data of 20 users

    ifstream infile("userdata.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);

            User user;
            string ageStr, categoryStr;
            getline(ss, user.username, ',');
            getline(ss, user.password, ',');
            getline(ss, user.name, ',');
            getline(ss, ageStr, ',');
            user.age = stoi(ageStr);
            getline(ss, user.address, ',');
            getline(ss, user.phone, ',');
            getline(ss, user.IC, ',');
            getline(ss, categoryStr, ',');

            int categoryInt = (categoryStr == "") ? 0 : stoi(categoryStr);
            switch (categoryInt) {
            case 0:
                user.category = Category::LOW_RISK;
                break;
            case 1:
                user.category = Category::TRAVEL_HISTORY;
                break;
            case 2:
                user.category = Category::SUSPECTED;
                break;
            case 3:
                user.category = Category::POSITIVE;
                break;
            default:
                cout << "Invalid category integer: " << categoryInt << endl;
                break;
            }

            getline(ss, user.testdate);

            users.push_back(user);
        }
        infile.close();

    } else {
        cerr << "Unable to open file, make files have been correctly named and placed" << endl;
        exit(1);
    }
    /*  for (int i = 0; i < users.size(); i++)
      {
          cout << users[i].category << endl;
      }*/

    // Main menu for the system
    ofstream file("userdata.txt");
    while (true) {
        cout << "======================================================" << endl;
        cout << "UTAR Covid-19 Management System for students and staff" << endl;
        cout << "======================================================" << endl;
        cout << "1. Register a new account" << endl;
        cout << "2. Login to the system" << endl;
        cout << "3. Exit and Save Changes" << endl;
        cout << "Enter your choice(1,2,3): ";
        int choice;
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            registration(users);
            system("pause");
            system("cls");
            break;
        case 2:
            login(users);
            system("pause");
            system("cls");
            break;
        case 3:
            if (file.is_open()) {

                saveUsersToFile("userdata.txt", &users);
                cout << "User data has been updated." << endl;

                file.close();

            } else {
                cerr << "Unable to open file, make files have been correctly named and placed" << endl;
                exit(1);
            }
            cout << "Thank you for using The UTAR Covid-19 Management System!" << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
    return 0;
}

void registration(vector<User> &users) {
    User user;
    ofstream data;
    string a = ",";
    data.open("userdata.txt", ios::app);
    cout << "Please enter your personal details: " << endl;
    cout << "Username: ";
    cin >> user.username;
    data << user.username;
    cout << "Password: ";
    cin >> user.password;
    data << a << user.password;
    cout << "Name: ";
    cin.ignore();
    getline(cin, user.name);
    data << a << user.name;
    cout << "Age: ";
    cin >> user.age;
    data << a << user.age;
    cout << "Address: ";
    cin.ignore();
    getline(cin, user.address);
    data << a << user.address;

    cout << "Phone number: ";
    cin >> user.phone;
    data << a << user.phone;
    cout << "Identification number (IC): ";
    cin >> user.IC;
    data << a << user.IC;

    // Add the new user to the vector of users
    users.push_back(user);
    data.close();

    cout << "Registration successful! Please remember your username and password." << endl;
}

void login(vector<User> &users) {
    string username, password;
    int choice;
    string name = "";
    int index = -1;

    while (name.empty()) {
        cout << "Please enter your username and password to login: " << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        // Check if the username and password match any user in the vector
        for (int i = 0; i < users.size(); i++) {
            if (users[i].username == username && users[i].password == password) {
                // User found, display user details and login menu
                cout << "Login successful! Welcome " << users[i].name << endl;
                reminder(users, users[i].name);
                name = users[i].name;
                index = i;
                break;
            }
        }

        if (name.empty()) {
            cout << "Incorrect username or password. Please try again." << endl;
        }
    }

    User *current_user = &users[index];

    do {
        cout << "||1.View Profile   ||  " << endl;
        cout << "||2.Update Profile ||  " << endl;
        cout << "||3.Take Test      ||  " << endl;
        cout << "||4.View Categories||  " << endl;
        cout << "||5.Exit           ||  " << endl;
        cout << "Please Enter the Number" << endl;
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            view_profile(current_user);
            break;
        case 2:
            update_profile(current_user);
            break;
        case 3:
            takeTest(users, name);
            break;
        case 4:
            viewcategory(users, name);

            break;
        case 5:
            name = "";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        if (choice == 5) {
            break;
        }
    } while (!name.empty() || choice != 5);
}

void viewcategory(vector<User> &users, string name) {

    int a = -1;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].name == name) {
            a = i;
            break;
        }
    }

    if (a != -1) {
        switch (users[a].category) {
        case Category::POSITIVE:
            cout << "User " << users[a].name << " is positive for Covid-19.\n";
            cout << "Please follow these actions:\n";
            cout << "Decide whether a Hospital Quarantine or Home Surveillance Order (HSO) subjected to MOH instructions would be more appropriate for your situation\n";
            cout << "Report to immediate supervisor (for staff) / respective lecturer (for students)\n";
            cout << "Report to Bilik Gerakan for close monitoring and sanitisation process.\n";
            cout << "Undergo qurantine for a period of 7 days\n";
            cout << "However, you may be released earlier if you are testesd negative on Day 4 (with supervision of medical practitioner)\n";
            break;
        case Category::SUSPECTED:
            cout << "User " << users[a].name << " is suspected to have Covid-19.\n";
            cout << "Please answer the following questions:\n";
            bool isSymptomaticB, liveWithPositive;
            cout << "- Do you feel any symptoms of COVID-19? (1 for yes, 0 for no)\n";
            cout << "  Common symptoms include fever, cough, shortness of breath, fatigue, body aches, headache, loss of taste or smell.\n";
            cin >> isSymptomaticB;
            cout << "- Do you live with someone who tested positive for COVID-19? (1 for yes, 0 for no) ";
            cin >> liveWithPositive;

            if (isSymptomaticB) {
                // Option 1: Symptomatic
                cout << "Please follow these actions:\n";
                cout << "Home Surveillance Order (HSO) subjected to MOH instructions or\n";
                cout << "Self-isolate and scheduled to Work From Home (Staff) / Online Teaching and Learning (Student) subjected to UTAR procedures\n";
                cout << "Report to immediate supervisor (for staff) / respective lecturer (for students)\n";
                cout << "Report to Bilik Gerakan for close monitoring and sanitisation process.\n";
                cout << "Undergo qurantine for a period of 3 days\n";
                cout << "Note: If your self-test results on the 3rd day were negative and no symptoms (or improved greatly), you will be allowed to work/study as usual and access campus\n";
                cout << "Additionally, You may refer to a doctor if you continue to have symptoms even if the self-test result on the 3rd day is negative.\n";
            } else if (liveWithPositive) {
                // Option 2: Living with positive case
                cout << "Please follow these actions:\n";
                cout << "Home Surveillance Order (HSO) subjected to MOH instructions or\n";
                cout << "Self-isolate and scheduled to Work From Home (Staff) / Online Teaching and Learning (Student) subjected to UTAR procedures\n";
                cout << "Report to immediate supervisor (for staff) / respective lecturer (for students)\n";
                cout << "Report to Bilik Gerakan for close monitoring and sanitisation process.\n";
                cout << "Undergo qurantine for a period of 3 days\n";
                cout << "Note: If your self-test results on the 3rd day were negative and no symptoms (or improved greatly), you will be allowed to work/study as usual and access campus\n";
            } else {
                // Option 3: Not symptomatic and not living with positive case
                cout << "Please follow these actions:\n";
                cout << "Home Surveillance Order (HSO) subjected to MOH instructions or\n";
                cout << "Self-isolate and scheduled to Work From Home (Staff) / Online Teaching and Learning (Student) subjected to UTAR procedures\n";
                cout << "Report to immediate supervisor (for staff) / respective lecturer (for students)\n";
                cout << "Report to Bilik Gerakan for close monitoring and sanitisation process.\n";
            }

            break;
            break;
        case Category::CLOSE_CONTACT:
            cout << "User " << users[a].name << " has been in close contact with a confirmed Covid-19 case.\n";
            cout << "Suggested action: Please self-isolate and get tested for Covid-19 as soon as possible.\n";
            break;
            break;
        case Category::TRAVEL_HISTORY:
            cout << "User " << users[a].name << " has recently traveled to a high-risk area for Covid-19.\n";
            break;

        case Category::LOW_RISK:
            check = negative(users, name);
            if (check == false) {
                cout << "User " << users[a].name << " is at low risk for Covid-19.\n";
                break;
            } else {
                break;
            }
        default:
            cout << "Invalid category.\n";
            break;
        }
        datamodified = false;

    } else {
        cout << "User not found.\n";
    }
    system("pause");
    system("cls");
}

void reminder(vector<User> &users, string name) {
    // Get current local time
    time_t now = time(0);
    tm localtm;
    // Get current day of the month
    int currentDay = localtm.tm_mday;

    int temp;
    // Find user with specified name in the vector
    for (int i = 0; i < users.size(); i++) {
        if (users[i].name == name) {
            temp = i;
            break;
        }
    }
    // Check user's category and test date

    if (users[temp].testdate.empty()) {
        cout << "Reminder: You should get tested for Covid-19.\n";
        takeTest(users, name);

    } else {
        // User needs to get tested for Covid-19
        stringstream ss(users[temp].testdate);
        string day, month, year;
        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year);

        // Calculate days since user's last test
        // Calculate days since user's last test
        int testDay = stoi(day);
        int testMonth = stoi(month) - 1;
        int testYear = stoi(year) - 1900;

        tm testtm = {0};
        testtm.tm_mday = testDay;
        testtm.tm_mon = testMonth;
        testtm.tm_year = testYear;
        time_t testtime = mktime(&testtm);
        double secondsSinceTest = difftime(now, testtime);
        int daysSinceTest = static_cast<int>(secondsSinceTest / (24 * 3600));

        // Remind user to get tested again if it's been 14 days since last test
        if (daysSinceTest >= 3 && daysSinceTest < 7) {
            cout << "Reminder: It has been " << daysSinceTest << " days since your last Covid-19 test. You should get tested again.\n";
        }

        if (users[temp].category == Category::CLOSE_CONTACT || users[temp].category == Category::SUSPECTED) {
            cout << "Reminder: You are a close contact/suspected case. Please take the test daily.\n";
            takeTest(users, name);
        } else {

            updateCategory(users, temp, daysSinceTest, name);
            stringstream ss;
            ss << setfill('0') << setw(2) << localtm.tm_mday << '/'
               << setfill('0') << setw(2) << localtm.tm_mon + 1 << '/'
               << localtm.tm_year + 1900;
            // change testdate to today's date
            users[temp].testdate = ss.str();
        }
    }
}
void updateCategory(vector<User> &users, int index, int daysSinceTest, string name)

{

    if (users[index].category == Category::POSITIVE && daysSinceTest >= 7) {
        users[index].category = Category::LOW_RISK;
        result = negative(users, name);
        if (result == false)
            cout << "You have completed 7 days of isolation.\n";
    }
}

// Function to take a Covid-19 test
void takeTest(vector<User> &users, string name) {

    int testResult = 0;
    string date;
    int symptoms = 0;
    int travelHistory = 0;
    bool hasFever = false;
    bool hasCough = false;
    bool hasBreathingDifficulty = false;
    bool hasBeenToHighRiskArea = false;
    ofstream data;
    int enter;

    data.open("userdata.txt", ios::app);
    // Get user ID
    int index = -1;

    // Find user in vector of users
    for (int i = 0; i < users.size(); i++) {
        if (users[i].name == name) {
            index = i;
            break;
        }
    }

    cout << "Do you have a fever? (1 for yes, 0 for no)\n";
    cin >> hasFever;

    cout << "Do you have a cough? (1 for yes, 0 for no)\n";
    cin >> hasCough;

    cout << "Do you have difficulty breathing? (1 for yes, 0 for no)\n";
    cin >> hasBreathingDifficulty;

    cout << "Have you traveled to a high-risk area in the past 14 days? (1 for yes, 0 for no)\n";
    cin >> hasBeenToHighRiskArea;

    // Get test result
    cout << "Enter test result (1 for positive, 0 for negative): ";
    cin >> testResult;

    if (hasFever && hasCough && hasBreathingDifficulty) {
        symptoms = 3;
    } else if (hasFever && hasCough) {
        symptoms = 2;
    } else if (hasFever || hasCough) {
        symptoms = 1;
    }

    if (hasBeenToHighRiskArea) {
        travelHistory = 1;
    }

    if (symptoms == 3 || (symptoms == 2 && travelHistory == 1) || (testResult == 1)) {
        users[index].category = Category::POSITIVE;
    } else if (symptoms == 2 || (symptoms == 1 && travelHistory == 1)) {
        users[index].category = Category::SUSPECTED;
    } else if (travelHistory == 1) {
        users[index].category = Category::TRAVEL_HISTORY;
    } else {
        users[index].category = Category::LOW_RISK;
    }
    data << categoryToInt(users[index].category) << ",";

    /* modifiedData = true;*/

    // Get test date
    do {
        cout << "Enter test date (DD/MM/YYYY): ";
        cin >> date;
        users[index].testdate = date;
        if (isValidDate(date)) {
            users[index].testdate = date;
            data << "," << users[index].testdate << endl;
            cout << "Test date recorded.\n";
            result = negative(users, name);

        } else {
            cout << "Invalid date format. Test date not recorded.\n";
        }
    } while (!isValidDate(date));
    datamodified = true;

    data.close();
}
bool isValidDate(const string &dateStr) {
    // Use regular expressions to check the format
    regex dateRegex("\\d{2}/\\d{2}/\\d{4}");
    if (!regex_match(dateStr, dateRegex)) {
        return false;
    }

    // Check if the date is a valid date
    stringstream ss(dateStr);
    int day, month, year;
    char sep;
    ss >> day >> sep >> month >> sep >> year;

    if (ss.fail() || (sep != '/') || (month < 1) || (month > 12) || (day < 1) || (day > 31)) {
        return false;
    }

    // Check for specific invalid dates
    if ((month == 2) && (day > 29)) {
        return false;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)) {
        return false;
    } else if ((month == 2) && (day == 29) && ((year % 4 != 0) || ((year % 100 == 0) && (year % 400 != 0)))) {
        return false;
    }

    return true;
}

int categoryToInt(Category category) {
    switch (category) {
    case Category::LOW_RISK:
        return 0;
    case Category::TRAVEL_HISTORY:
        return 1;
    case Category::SUSPECTED:
        return 2;
    case Category::POSITIVE:
        return 3;
    default:
        return -1;
    }
}

void update_profile(User *p_user) {
    do {
        system("cls");
        int choice;
        string name;
        int age;
        string address;
        string phone;
        string IC;
        string password;
        int temp = -1;

        cout << "Choose select which you want to update:\n";
        cout << "1. Name\n";
        cout << "2. Age\n";
        cout << "3. Address\n";
        cout << "4. Phone number\n";
        cout << "5. IC number\n";
        cout << "6.Password\n";
        cout << "7. Back to main menu.\n";

        cin >> choice;
        system("cls");

        if (choice == 1) // update name
        {

            cout << "Enter your name : ";
            cin.ignore();
            getline(cin, name);
            (*p_user).name = name;
            cout << "Your name was successfully updated!" << endl;

        } else if (choice == 2) // update age
        {
            cout << "Enter your age : ";
            cin >> age;
            (*p_user).age = age;
            cout << "Your age was successfully updated!" << endl;

        } else if (choice == 3) // update address
        {
            cout << "Enter your address : ";
            cin.ignore();
            getline(cin, address);
            (*p_user).address = address;
            cout << "Your address was successfully updated!" << endl;

        } else if (choice == 4) // update phone number
        {
            cout << "Enter your phone number (with dash -) : ";
            cin.ignore();
            getline(cin, phone);
            (*p_user).phone = phone;
            cout << "Your phone number was successfully updated!" << endl;

        } else if (choice == 5) // update ic number
        {
            cout << "Enter your IC number : ";
            cin.ignore();
            getline(cin, IC);
            (*p_user).IC = IC;
            cout << "Your IC number was successfully updated!" << endl;

        } else if (choice == 6) {
            cout << "Enter your old Password : ";
            string old_password;
            cin.ignore();
            getline(cin, old_password);

            if (old_password == (*p_user).password) {
                cout << "Enter your new Password : ";
                string new_password;
                getline(cin, new_password);
                (*p_user).password = new_password;
                cout << "Your password was successfully updated!" << endl;

            } else {
                cout << "Incorrect old password. Password not updated." << endl;
            }

        } else if (choice == 7) // back to main menu
        {

            return;
            datamodified = true;
        } else {
            cout << "Please choose which you want to update from the menu.\n";
            system("pause");
            system("cls");
        }
    } while (true); // Keep looping until a valid input is provided
}
void saveUsersToFile(string filename, vector<User> *users) {
    ofstream file(filename);
    if (file.is_open()) {
        for (auto &user : *users) {
            file << user.username << "," << user.password << "," << user.name << "," << user.age << "," << user.address << "," << user.phone << "," << user.IC << "," << categoryToInt(user.category) << "," << user.testdate << endl;
        }
        file.close();
    }
}
void view_profile(User *user) {
    system("cls");
    cout << "----------------------------" << endl;
    cout << "\tYour Profile\t" << endl;
    cout << "----------------------------" << endl;
    cout << "Name: " << user->name << endl;
    cout << "Age: " << user->age << endl;
    cout << "Address: " << user->address << endl;
    cout << "Phone number: " << user->phone << endl;
    cout << "IC: " << user->IC << endl;
    cout << "----------------------------" << endl;
    system("pause");
    system("cls");
}
bool negative(vector<User> &users, string name) {
    // Get current local time
    time_t now = time(0);
    tm localtm;
    localtime_r(&now, &localtm);
    // Get current day of the month
    int currentDay = localtm.tm_mday;

    int temp;
    // Find user with specified name in the vector
    for (int i = 0; i < users.size(); i++) {
        if (users[i].name == name) {
            temp = i;
            break;
        }
    }
    // Check user's category and test date

    // User needs to get tested for Covid-19
    stringstream ss(users[temp].testdate);
    string day, month, year;
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year);

    // Calculate days since user's last test
    // Calculate days since user's last test
    int testDay = stoi(day);
    int testMonth = stoi(month) - 1;
    int testYear = stoi(year) - 1900;

    tm testtm = {0};
    testtm.tm_mday = testDay;
    testtm.tm_mon = testMonth;
    testtm.tm_year = testYear;
    time_t testtime = mktime(&testtm);
    double secondsSinceTest = difftime(now, testtime);
    int daysSinceTest = static_cast<int>(secondsSinceTest / (24 * 3600));
    if (daysSinceTest >= 7 && users[temp].category == Category::POSITIVE) {
        return true;
    } else if (daysSinceTest == 0 && users[temp].category == Category::LOW_RISK) {
        return false;
    } else {
        return false;
    }
}
