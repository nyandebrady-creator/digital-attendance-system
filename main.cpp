#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Student Class (Week 1 Milestone)
class Student {
public:
    string indexNumber;
    string name;

    void display() {
        cout << "Index: " << indexNumber << " | Name: " << name << endl;
    }
};

// Function Prototypes
void mainMenu();
void registerStudent();
void viewStudents();
void createSession();

int main() {
    int choice;
    while (true) {
        mainMenu();
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: createSession(); break;
            case 0: cout << "Exiting system..." << endl; return 0;
            default: cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}

void mainMenu() {
    cout << "\n=== EEE227 DIGITAL ATTENDANCE SYSTEM ===" << endl;
    cout << "1. Register Student" << endl;
    cout << "2. View All Registered Students" << endl;
    cout << "3. Create Lecture Session (Mark Attendance)" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Choice: ";
}

void registerStudent() {
    string name, index;
    cout << "Enter Index Number: "; getline(cin, index);
    cout << "Enter Full Name: "; getline(cin, name);

    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open()) {
        outFile << index << "," << name << endl;
        outFile.close();
        cout << "Student Registered Successfully!" << endl;
    }
}

void viewStudents() {
    ifstream inFile("students.txt");
    string line;
    cout << "\n--- Registered Students ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void createSession() {
    // Week 2/3 Logic: Implement session file naming and attendance marking here
    cout << "Session Module - Coming soon in Week 3/4 Milestone!" << endl;
}
