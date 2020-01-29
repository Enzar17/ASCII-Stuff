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
int ProcessMenuInput();
int PromptForInteger();
void MakeSquare();
void MakeRightTriangle();
void MakeIsoscelesTriangle();
void MakeHourglass();
void MakeDiamond();

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
        userInput = ProcessMenuInput();

        switch (userInput)
        {
            case 1:
                MakeSquare();
                break;
            case 2:
                MakeRightTriangle();
                break;
            case 3:
                MakeIsoscelesTriangle();
                break;
            case 4:
                MakeHourglass();
                break;
            case 5:
                MakeDiamond();
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

int ProcessMenuInput()
{
    int input = 0;  //this will store whatever the user inputs

    cout << "Please select a menu option(1-6)" << endl;
    cin >> input;

    while (input < 1 || input > 6)
    {
        cout << "You have not selected a valid menu option, please try again." << endl
             << "Please select a menu option(1-6)" << endl;
        cin >> input;

    }

    return input;
}

int PromptForInteger()
{
    return 0;
}

void makeSquare()
{
    cout << "Square!" << endl;
}

void makeRightTriangle()
{
    cout << "R Triangle!" << endl;
}

void makeIsoscelesTriangle()
{
    cout << "I Triangle!" << endl;
}

void makeHourglass()
{
    cout << "Hourglass!" << endl;
}

void makeDiamond()
{
    cout << "Diamond!" << endl;
}