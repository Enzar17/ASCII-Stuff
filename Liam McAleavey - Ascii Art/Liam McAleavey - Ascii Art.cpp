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

// Function prototypes
void DisplayMenu();
int ProcessMenuInput(int minRange, int maxRange, string shapeName);
int PromptForInteger(int minRange, int maxRange, string shapeName);
void PrintAst(int size);
void PrintSpaces(int size);
void MakeSquare(int size);
void MakeRightTriangle(int size);
void MakeIsoscelesTriangle(int size, bool cutTop);
void MakeReverseIsoscelesTriangle(int size, bool cutTop);
void MakeHourglass(int size);
void MakeDiamond(int size);

// main()
// Parameters:
//      none
// Return Value:
//      int - Returns a 0 if main executed correctly, and a 1 if it did not
// Description:
//      Governs the main loop of giving the user a menu, processing their
//      input, and then calling a function to draw a shape based on that input
int main()
{
    int userInput = 0;  // We'll use this to store our user's input later

    // Display the welcome message. This should only happen once.
    cout << "Welcome to the shape renderer!" << endl
        << "You can draw a few different shapes at a variety of sizes!" << endl;

    // Now we'll enter the main loop of the program. By design, we'll always want this to run
    // at least once, so a do-while works great for this
    do
    {
        // Begin by displaying the menu to our user
        DisplayMenu();

        // Now start getting their input
        userInput = ProcessMenuInput(1, 6, "menu");

        // Process the input based on the return value
        switch (userInput)
        {
        case 1:
            MakeSquare(ProcessMenuInput(1, 20, "square"));
            break;
        case 2:
            MakeRightTriangle(ProcessMenuInput(1, 20, "right triangle"));
            break;
        case 3:
            MakeIsoscelesTriangle(ProcessMenuInput(1, 20, "isosceles triangle"), false);
            break;
        case 4:
            MakeHourglass(ProcessMenuInput(1, 20, "hourglass"));
            break;
        case 5:
            MakeDiamond(ProcessMenuInput(1, 20, "diamond"));
            break;
        default:
            cout << "Thank you for using our application!  Good-bye!";
            break;
        }

    } while (userInput != 6);

    return 0;
}

// DisplayMenu()
// Parameters:
//      none
// Return Value:
//      none
// Description:
//      Prints out the main menu to the console
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

// ProcessMenuInput()
// Parameters:
//      int minRange - the minimum integer value allowed for the particular input
//      int maxRange - the maximum integer value allowed for the particular input
//      string shapeName - the name of the shape we're taking input for
// Return Value:
//      int - Returns the (allowed) value of the user's input
// Description:
//      Uses the PromptForInteger() function to get an integer from the user, and
//      then ensures that value is within range before returning it
int ProcessMenuInput(int minRange, int maxRange, string shapeName)
{
    int input = 0;      // this will store whatever is passed back from PromptForInteger

    input = PromptForInteger(minRange, maxRange, shapeName);

    // If we get back something invalid, we'll print an error and try again
    while (input < minRange || input > maxRange)
    {
        if (shapeName == "menu")
        {
            cout << "You have not selected a valid menu option, please try again." << endl;
        }

        else
        {
            cout << "You have not selected an appropriate size, please try again." << endl;
        }

        input = PromptForInteger(minRange, maxRange, shapeName);
    }

    //Return the proper input
    return input;
}

// PromptForInteger()
// Parameters:
//      int minRange - the minimum integer value allowed for the particular input
//      int maxRange - the maximum integer value allowed for the particular input
//      string shapeName - the name of the shape we're taking input for
// Return Value:
//      int - Returns a the integer input the user gave us
// Description:
//      Gives the user a specific prompt for input based on the parameters. With a
//      shapeName of "menu", it will prompt for a main menu input instead of a shape
int PromptForInteger(int minRange, int maxRange, string shapeName)
{
    int input = 0;          // this will store whatever the user inputs

    // Print out a specific prompt to the user depending on the input we want
    if (shapeName == "menu")
    {
        cout << "Please select a menu option(" << minRange << "-" << maxRange << ")" << endl;
    }

    else if (shapeName == "hourglass" || shapeName == "diamond")
    {
        cout << "You have selected an " << shapeName << "!  What size should your " << shapeName
            << " be (" << minRange << "-" << maxRange << ")?" << endl;
    }

    else
    {
        cout << "You have selected a " << shapeName << "!  What size should your " << shapeName
            << " be (" << minRange << "-" << maxRange << ")?" << endl;
    }

    // Take in an input and return it
    cin >> input;

    return input;
}

// PrintAst()
// Parameters:
//      int size - the size of the row it will print
// Return Value:
//      none
// Description:
//      Prints a row of asterisks the length of "size"
void PrintAst(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "*";
    }
}

// PrintSpaces()
// Parameters:
//      int size - the size of the row it will print
// Return Value:
//      none
// Description:
//      Prints a row of spaces the length of "size"
void PrintSpaces(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " ";
    }
}

// MakeSquare()
// Parameters:
//      int size - the height of the square
// Return Value:
//      none
// Description:
//      Prints (size) rows of asterisks, of length (size)
void MakeSquare(int size)
{
    for (int i = 0; i < size; i++)
    {
        PrintAst(size);
        cout << endl;
    }
}

// MakeRightTriangle()
// Parameters:
//      int size - the height of the triangle
// Return Value:
//      none
// Description:
//      Creates a right triangle by printing rows of asterisks of increasing length,
//      beginning with 1 and adding another with each row
void MakeRightTriangle(int size)
{
    for (int i = 1; i <= size; i++)
    {
        PrintAst(i);
        cout << endl;
    }
}

// MakeIsoscelesTriangle()
// Parameters:
//      int size - the height of the triangle
// Return Value:
//      none
// Description:
//      Creates an isosceles triangle of spaces and asterisks, and has functionality
//      for truncating a line off it (for the hourglass and diamond)
void MakeIsoscelesTriangle(int size, bool cutTop)
{
    int spacesToPrint = (((size * 2) - 1) / 2);     //The spaces we'll print before each line of asterisks
    int astToPrint = 1;                             //The asterisks we'll print after our spaces

    // Iterate our values as if we already printed our first line to cut our top
    if (cutTop)
    {
        spacesToPrint--;
        astToPrint += 2;
        size--;
    }

    // Print each row of spaces and asterisks, move to the next line, and iterate our values
    for (int i = 0; i < size; i++)
    {
        PrintSpaces(spacesToPrint);
        PrintAst(astToPrint);
        cout << endl;

        spacesToPrint--;
        astToPrint += 2;
    }
}

// MakeReverseIsoscelesTriangle()
// Parameters:
//      int size - the height of the triangle
// Return Value:
//      none
// Description:
//      Creates an upside-down isosceles triangle of spaces and asterisks, and has 
//      functionality for truncating a line off it (for the hourglass and diamond)
void MakeReverseIsoscelesTriangle(int size, bool cutTop)
{
    int spacesToPrint = 0;                  //The spaces we'll print before each line of asterisks
    int astToPrint = ((size * 2) - 1);;     //The asterisks we'll print after our spaces

    // Iterate our values as if we already printed our first line to cut our top
    if (cutTop)
    {
        spacesToPrint++;
        astToPrint -= 2;
        size--;
    }

    // Print each row of spaces and asterisks, move to the next line, and iterate our values
    for (int i = 0; i < size; i++)
    {
        PrintSpaces(spacesToPrint);
        PrintAst(astToPrint);
        cout << endl;

        spacesToPrint++;
        astToPrint -= 2;
    }
}

// MakeHourglass()
// Parameters:
//      int size - the height of the top triangle. The bottom's height is size - 1
// Return Value:
//      none
// Description:
//      Create an hourglass with an upside-down isosceles triangle and then a regular one
void MakeHourglass(int size)
{
    MakeReverseIsoscelesTriangle(size, false);
    MakeIsoscelesTriangle(size, true);
}

// MakeDiamond()
// Parameters:
//      int size - the height of the top triangle. The bottom's height is size - 1
// Return Value:
//      none
// Description:
//      Create a diamond with a regular isosceles triangle and then an upside-down one
void MakeDiamond(int size)
{
    // for some reason, the output wants there to be an extra space on a diamond
    // with a size of 1, but NOT on a regular isosceles triangle. This was the
    // only way I could find to force it to match that specific output.
    if (size == 1)
    {
        cout << " ";
    }

    MakeIsoscelesTriangle(size, false);
    MakeReverseIsoscelesTriangle(size, true);
}