/* Programmer: Liam McAleavey
 * Class: CS 2250
 * Due Date: Feb 5, 2020
 * Description: This program creates shapes of varying shapes and sizes. It takes
 *              input from the user for which shape to make, prints it, and then
 *              gives them the option to create another. All input is validated,
 *              and in input of 6 quits the application.
 */

#include <iostream>
using namespace std;

void DisplayMenu();
int PromptForInteger(int minRange, int maxRange, string shapeName);
void MakeSquare(int size);
void MakeRightTriangle(int size);
void MakeIsoscelesTriangle(int size, bool reverse, bool cutTop);
void MakeHourglass(int size);
void MakeDiamond(int size);

int main()
{
    int userInput = 0;  //We'll use this to store our user's input later

    // Display the welcome message. This should only happen once.
    cout << "Welcome to the shape renderer!" << endl
         << "You can draw a few different shapes at a variety of sizes!" << endl;

    // Now we'll enter the main loop of the program. By design, we'll always want this to run
    // at least once, so a do-while works great for this
    do
    {
        //Begin by displaying the menu to our user
        DisplayMenu();

        //Now start getting their input
        userInput = PromptForInteger(1, 6, "menu");

        switch (userInput)
        {
            case 1:
                MakeSquare(PromptForInteger(1, 20, "square"));
                break;
            case 2:
                MakeRightTriangle(PromptForInteger(1, 20, "right triangle"));
                break;
            case 3:
                MakeIsoscelesTriangle(PromptForInteger(1, 20, "isosceles triangle"), false, false);
                break;
            case 4:
                MakeHourglass(PromptForInteger(1, 20, "hourglass"));
                break;
            case 5:
                MakeDiamond(PromptForInteger(1, 20, "diamond"));
                break;
            default:
                cout << "Thank you for using our application!  Good-bye!";
                break;
        }

    } while (userInput != 6);

    return 0;
}

void DisplayMenu()
{
    cout << "********************************************************************************"
         << endl << "* Please select a menu option(1 - 6) :" << endl << "* 1 - Square" << endl
         << "* 2 - Right Triangle" << endl << "* 3 - Isosceles Triangle" << endl
         << "* 4 - Hourglass" << endl << "* 5 - Diamond" << endl
         << "* 6 - Quit(exit the application)" << endl
         << "********************************************************************************"
         << endl;
}

int PromptForInteger(int minRange, int maxRange, string shapeName)
{
    int input = 0;          // this will store whatever the user inputs

    if (shapeName == "menu")
    {
        cout << "Please select a menu option(1-6)" << endl;
    }

    else
    {
        cout << "You have selected a " << shapeName << "! What size should your " << shapeName
             << " be (" << minRange << "-" << maxRange << ")?" << endl;
    }

    cin >> input;

    while (input < minRange || input > maxRange)
    {
        if (shapeName == "menu")
        {
            cout << "You have not selected a valid menu option, please try again." << endl
                 << "Please select a menu option(1-6)" << endl;
        }

        else
        {
            cout << "You have not selected an appropriate size, please try again." << endl
                 << "You have selected a " << shapeName << "! What size should your " << shapeName
                 << " be (" << minRange << "-" << maxRange << ")?" << endl;
        }

        cin >> input;
    }

    return input;
}

void MakeSquare(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void MakeRightTriangle(int size)
{
    int rowSentinel = 1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < rowSentinel; j++)
        {
            cout << "*";
        }
        cout << endl;
        rowSentinel++;
    }
}

void MakeIsoscelesTriangle(int size, bool reverse, bool cutTop)
{
    if (!reverse)
    {
        int spacesToPrint = (((size * 2) - 1) / 2);
        int astToPrint = 1;

        if (cutTop)
        {
            spacesToPrint--;
            astToPrint += 2;
            size--;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < spacesToPrint; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < astToPrint; j++)
            {
                cout << "*";
            }

            cout << endl;

            spacesToPrint--;
            astToPrint += 2;
        }
    }

    else
    {
        int spacesToPrint = 0;
        int astToPrint = ((size * 2) - 1);

        if (cutTop)
        {
            spacesToPrint++;
            astToPrint -= 2;
            size--;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < spacesToPrint; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < astToPrint; j++)
            {
                cout << "*";
            }

            cout << endl;

            spacesToPrint++;
            astToPrint -= 2;
        }
    }
}

void MakeHourglass(int size)
{
    MakeIsoscelesTriangle(size, true, false);
    MakeIsoscelesTriangle(size, false, true);
}

void MakeDiamond(int size)
{
    MakeIsoscelesTriangle(size, false, false);
    MakeIsoscelesTriangle(size, true, true);
}