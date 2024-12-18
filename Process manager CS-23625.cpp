#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm> // For std::all_of

using namespace std;

// Function to list all processes
void ListProcesses() {
    cout << "\nListing all processes...\n" << endl;
    int result = system("tasklist");
    if (result != 0) {
        cout << "Failed to retrieve process list. Please ensure you have the necessary permissions." << endl;
    }
}

// Function to check if a string is numeric
bool IsNumeric(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

// Function to terminate a process by its ID
void TerminateProcessByID(const string& processID) {
    if (!IsNumeric(processID)) {
        cout << "Invalid Process ID. Please enter a numeric value." << endl;
        return;
    }

    string command = "taskkill /PID " + processID + " /F";
    int result = system(command.c_str());

    if (result == 0) {
        cout << "Process with ID " << processID << " terminated successfully." << endl;
    } else {
        cout << "Failed to terminate process with ID " << processID
             << ". Make sure the ID is correct and you have the necessary permissions." << endl;
    }
}

// Function to display the main menu
void DisplayMenu() {
    cout << "\n==== Process Manager ====" << endl;
    cout << "1. List all processes" << endl;
    cout << "2. Terminate a process by ID" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to get a validated menu choice from the user
int GetMenuChoice() {
    int choice;
    while (true) {
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the error state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a numeric value: ";
        } else if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please select a number between 1 and 3: ";
        } else {
            return choice; // Valid input
        }
    }
}

// Main program
int main() {
    while (true) {
        DisplayMenu();
        int choice = GetMenuChoice();

        switch (choice) {
            case 1:
                ListProcesses();
                break;
            case 2: {
                cout << "Enter the Process ID to terminate: ";
                string processID;
                cin >> processID;
                TerminateProcessByID(processID);
                break;
            }
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                // This should never be reached due to validation in GetMenuChoice()
                cout << "Unknown error occurred. Please try again." << endl;
        }
    }
}
