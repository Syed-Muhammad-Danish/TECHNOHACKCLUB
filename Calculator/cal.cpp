#include <iostream>
#include <windows.h>
using namespace std;

void setGreenColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // Set text color to green
}


void resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset text color to default
}

int main() {
    int choice;
    float num1, num2;

    while (true) {
        system("cls");
        setGreenColor();
        cout << "\n\n\n\t\t\t\t Welcome to Calculator Menu" << endl << endl;
        resetColor();
        cout << "\t\t\t\t 1. Addition" << endl;
        cout << "\t\t\t\t 2. Subtraction" << endl;
        cout << "\t\t\t\t 3. Multiplication" << endl;
        cout << "\t\t\t\t 4. Division" << endl;
        cout << "\t\t\t\t 5. Quit" << endl;
        cout << "\t\t\t\t Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        if (choice == 5) {
            // Exit the program if the user chooses to quit
            setGreenColor();
            cout << endl << "\t\t\t\t Calculator is exiting. Goodbye!" << endl;
            resetColor();
            break;
        }

        if (choice < 1 || choice > 4) {
            // Invalid choice
            cout << "\t\t\t\t Invalid choice. Please select a valid operation (1/2/3/4/5)." << endl;
            continue;
        }

        system("cls");
        // Prompt the user for two numbers
        cout << "\n\n\n\t\t\t\t Enter first number: ";
        cin >> num1;
        cout << "\t\t\t\t Enter second number: ";
        cin >> num2;

        // Perform the selected operation and display the result
        float result;
        switch (choice) {
            case 1:
                result = num1 + num2;
                break;
            case 2:
                result = num1 - num2;
                break;
            case 3:
                result = num1 * num2;
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    setGreenColor(); // Set text color to green
                    cout << "\t\t\t\t Error: Division by zero is not allowed." << endl;
                    resetColor(); // Reset text color
                    // Wait for user input to continue
                    cout << "\n\t\t\t\t Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                    continue;
                }
                break;
            default:
                break;
        }

        // Center-align the output
        int width = 40; // Total width of the output
        int padding = (width - 16) / 2; // Padding to center-align text
        cout << string(padding, ' '); // Output padding
        setGreenColor(); // Set text color to green
        cout << endl << "\t\t\t\t Result: " << result << endl;
        resetColor(); // Reset text color

        // Wait for user input to continue
        cout << "\t\t\t\t Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
