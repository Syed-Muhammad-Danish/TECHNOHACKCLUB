#include <iostream>
#include<stdio.h>
#include <conio.h>
using namespace std;

int main()
{
    char choice;

    do
    {
        system("cls");
        cout << "\n\n\n\t\t\t\tTemperature Conversion Menu:" << endl;
        cout << "\n\n\t\t\t\t1. Convert from Fahrenheit to Celsius" << endl;
        cout << "\t\t\t\t2. Convert from Celsius to Fahrenheit" << endl;
        cout << "\t\t\t\t3. Exit" << endl;
        cout << "\n\t\t\t\tEnter your choice (1-3): ";

        cin >> choice;

        if (choice == '3')
        {
            cout << "\n\n\t\t\t\t\tExiting the program." << endl;
            break;
        }

        double temperature, convertedTemperature;

        if (choice >= '1' && choice <= '2')
        {
            cout << "\n\n\t\t\t\tEnter the temperature value: ";
            cin >> temperature;
        }

        switch (choice)
        {
        case '1':
            convertedTemperature = (temperature - 32.0) * 5.0 / 9.0; // Fahrenheit to Celsius
            cout << "\n\t\t\t\tConverted temperature: " << convertedTemperature << " Celsius" << endl;
            break;
        case '2':
            convertedTemperature = (temperature * 9.0 / 5.0) + 32.0; // Celsius to Fahrenheit
            cout << "\n\t\t\t\tConverted temperature: " << convertedTemperature << " Fahrenheit" << endl;
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice. Please enter a valid option (1-3)." << endl;
            return 1;
        }
        
    } while (choice != '3');

    return 0;
}
