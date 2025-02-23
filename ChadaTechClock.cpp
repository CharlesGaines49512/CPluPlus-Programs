// Developer: Charles Austin Gaines	
// Assignment: CS210 Project One
// Description: This is an app created for the software company Chada Tech during a technical interview

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// Function prototypes
void displayClocks(int hour, int minute, int second);
void displayMenu();
void addHour(int& hour);
void addMinute(int& minute, int& hour);
void addSecond(int& second, int& minute, int& hour);
string formatTime(int hour, int minute, int second);


// Function to display the clocks
void displayClocks(int hour, int minute, int second) {
    // Display the two clocks side by side
    cout << "\n**************************       **************************" << endl;
    cout << "*     12-Hour Clock      *       *     24-Hour Clock      *" << endl;

    // Convert to 12-hour format
    int displayHour = hour % 12;
    if (displayHour == 0) displayHour = 12;
    string period = (hour < 12) ? "AM" : "PM";

    // Display the formatted times
    cout << "*     " << setw(2) << setfill('0') << displayHour << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second << " " << period
        << "      *       *     " << setw(2) << setfill('0') << hour << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second << "         *" << endl;

    cout << "**************************       **************************\n" << endl;
}

// Function to display the menu
void displayMenu() {
    cout << "********* MENU *********\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit\n";
    cout << "*************************\n";
    cout << "Enter your choice: ";
}

// Function to add one hour
void addHour(int& hour) {
    hour = (hour + 1) % 24; // Increment hour and wrap around at 24
}

// Function to add one minute
void addMinute(int& minute, int& hour) {
    minute = (minute + 1) % 60; // Increment minute and wrap around at 60
    if (minute == 0) {
        addHour(hour); // Add an hour if minutes wrap to 0
    }
}

// Function to add one second
void addSecond(int& second, int& minute, int& hour) {
    second = (second + 1) % 60; // Increment second and wrap around at 60
    if (second == 0) {
        addMinute(minute, hour); // Add a minute if seconds wrap to 0
    }
}

// Function to format time 
string formatTime(int hour, int minute, int second) {
    stringstream timeStream;
    timeStream << setw(2) << setfill('0') << hour << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second;
    return timeStream.str();
}

int main() {
    // Declare and initialize variables
    int hour = 0;       // Stores the hour value 
    int minute = 0;     // Stores the minute value 
    int second = 0;     // Stores the second value 
    bool running = true; // Controls the menu loop

    // Get initial time input from the user
    cout << "Enter hour (0-23): ";
    cin >> hour;

    cout << "Enter minute (0-59): ";
    cin >> minute;

    cout << "Enter second (0-59): ";
    cin >> second;

    // Input validation for time values
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        cout << "Invalid time entered. Exiting program." << endl;
        return 1;
    }

    // Main menu loop
    while (running) {
        displayClocks(hour, minute, second); // Display the clocks
        displayMenu();                      // Display the menu

        int choice = 0; // User's menu choice
        cin >> choice;

        // Process the menu choice
        switch (choice) {
        case 1:
            addHour(hour);
            break;
        case 2:
            addMinute(minute, hour);
            break;
        case 3:
            addSecond(second, minute, hour);
            break;
        case 4:
            running = false;
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}