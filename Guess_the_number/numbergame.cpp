#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h> // for Windows-specific text color

using namespace std;

// Function to set text color (Windows-specific)
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    int random;
    srand(time(0));
    random = rand() % 100 + 1;
    int guess = 0;
    int num = 0;
    string choice;
    int count = 8;
    system("cls");
    cout << random;
    cout << "\n\n\n\t\t\t\tWELCOME TO NUMBER GAME\t\t\t" << endl;
    cout << "\n\n\t\t\t\tA Random Number is Generated" << endl;
    cout << "\t\t\t\tPress Enter to start the game or 'q' to quit: ";
    char startKey = _getch(); // Use _getch() to read a single character

    if (startKey != 'q')
    {
        system("cls");
        while (true)
        {
            cout << "\n\n\t\t\t\tYou Have " << count << " Attempts to Guess the right number." << endl;
            cout << "\t\t\t\tGuess the random Number Generator : ";
            cin >> num;
            guess++;
            count--;

            if (num == random)
            {
                system("cls");
                setColor(10); // Set text color to green
                cout << "\n\t\t\t\tYou guessed correctly." << endl;
                cout << "\n\t\t\t\tYou Guessed the Correct Random-Number " << random << " in " << guess << " Attempts" << endl;
                setColor(7); // Reset text color to default
                break;
            }
            else if (num > random)
            {
                cout << "\n\t\t\t\tYour guess is too big." << endl;
            }
            else if (num < random)
            {
                cout << "\n\t\t\t\tYour guess is too small." << endl;
            }
            else
            {
                cout << "\n\t\t\t\tInvalid input." << endl;
            }

            // Check if the user wants to quit during the game
            if (_kbhit()) // Check if a key is pressed
            {
                char quitKey = _getch();
                if (quitKey == 'q')
                {
                    cout << "\n\t\t\t\tPress 'y' to confirm quitting or any other key to continue: ";
                    char confirmKey = _getch();
                    if (confirmKey == 'y')
                    {
                        setColor(12); // Set text color to red
                        cout << "\n\t\t\t\tYou Quit the game." << endl;
                        setColor(7); // Reset text color to default
                        exit(0); // Quit the program
                    }
                }
            }

            // Switch case for providing messages based on how close the guessed number is to the random number
            switch (abs(num - random))
            {
                case 0:
                    break; // Exact match, no message needed
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    cout << "\n\t\t\t\tToo close!" << endl;
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    cout << "\n\t\t\t\tA bit close." << endl;
                    break;
                default:
                    break;
            }

            if (count <= 0)
            {
                system("cls");
                setColor(12); // Set text color to red
                cout << "\n\t\t\t\tYou Could not guess the Random-Number " << random << " in 8   Attempts" << endl;
                setColor(7); // Reset text color to default
                break;
            }
        }
    }
    else
    {
        exit(0);
    }
    return 0;
}
