//Write a program that helps with dispensing monetary change (U.S.). A user enters total cents, and the program outputs the number of each coin to dispense 
//(quarters, dimes, nickels, pennies) using the fewest coins. Create a struct called change with those four data members, a function change computeChange(int totCents), 
//and a function void PrintChange(change c) that prints the change, and use those functions in main().

#include <iostream>
using namespace std;

struct change {
    int quarters;
    int dimes;
    int nickels;
    int pennies;
};

int UserInput();
change ComputeChange(int totalCents);
void PrintChange(change c);

int main()
{
    int userInput;
    change totalChange;
    
    userInput = UserInput();
    totalChange = ComputeChange(userInput);
    PrintChange(totalChange);
}

int UserInput()
{
    int input;
    cout << "Please enter the total amount change you have: ";
    cin >> input;

    return input;
}

change ComputeChange(int totalCents)
{
    change chnge;
    chnge.quarters = 0;
    chnge.dimes = 0;
    chnge.nickels = 0;
    chnge.pennies = 0;

    while (totalCents > 0)
    {
        if (totalCents >= 25)
        {
            chnge.quarters = totalCents / 25;
            totalCents -= chnge.quarters * 25;
        }
        else if (totalCents >= 10)
        {
            chnge.dimes = totalCents / 10;
            totalCents -= chnge.dimes * 10;
        }
        else if (totalCents >= 5)
        {
            chnge.nickels = totalCents / 5;
            totalCents -= chnge.nickels * 5;
        }
        else
        {
            chnge.pennies = totalCents / 1;
            totalCents -= chnge.pennies * 1;
        }
    }
    return chnge;
}

void PrintChange(change c)
{
    cout << "# of Quarters: " << c.quarters << endl;
    cout << "# of Dimes: " << c.dimes << endl;
    cout << "# of Nickles: " << c.nickels << endl;
    cout << "# of Pennies: " << c.pennies << endl;
}