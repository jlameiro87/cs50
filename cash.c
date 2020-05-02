#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Total of coins used to give a change
    int coins = 0;
    // Change amount entered by the user
    float change = 0.0;

    do
    {
        change = get_float("Please enter how much change is owed\n");
    }
    while (change <= 0);

    // Rounding the user input
    int cents = round(change * 100);

    // Do the process until change is greather than 0
    while (cents > 0)
    {
        // If a quarter can be used
        if (cents - 25 >= 0)
        {
            cents -= 25;
            coins++;
        }
        // If a dim can be used
        else if (cents - 10 >= 0)
        {
            cents -= 10;
            coins++;
        }
        // If a nickel can be used
        else if (cents - 5 >= 0)
        {
            cents -= 5;
            coins++;
        }
        // A cent should be used
        else
        {
            cents -= 1;
            coins++;
        }
    }

    printf("%i\n", coins);
}
