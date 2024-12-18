#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

void ListProcesses() {
    cout << "\nListing all processes...\n" << endl;
    int result = system("tasklist");
    if (result != 0) {
        cout << "Failed to retrieve process list. Please ensure you have the necessary permissions." << endl;
    }
}
c
bool IsNumeric(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

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
void DisplayMenu() {
    cout << "\n==== Process Manager ====" << endl;
    cout << "1. List all processes" << endl;
    cout << "2. Terminate a process by ID" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int GetMenuChoice() {
    int choice;
    while (true) {
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); /
