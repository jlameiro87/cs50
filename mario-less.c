#include <cs50.h>
#include <stdio.h>
#include <string.h>

void printLine(int lineNumber, int height);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Enter the piramid height, it should be a number between 1 and 8 inclusived\n");
    }
    while (height < 1 || height > 8);
    for (int i = 1; i <= height; i++)
    {
        // Printing the current piramid row
        printLine(i, height);
    }
}

void printLine(int lineNumber, int height)
{
    // Print spaces required to align the piramid row
    printf("%*s", height - lineNumber, "");
    
    // Piramid row
    char c = '#';
    for (int i = 0; i < lineNumber; i++)
    {
        putchar(c);
    }

    // Printing the current piramid row
    printf("\n");
}
