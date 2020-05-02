#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool isFinalPunctuation(char letter);

int main(void)
{
    string userInput = get_string("Text: ");
    // get user entry length
    int length = strlen(userInput);

    // letters to be counted
    int letters = 0;
    // spaces are used to count words
    int words = 1;
    // punctuation signs used to count sentences
    int sentences = 0;

    // iterate over each character in the user entry
    for (int i = 0; i < length; i++)
    {
        // char is alphanumeric
        if (isalpha(userInput[i]))
        {
            letters++;
        }
        // char is space
        else if (isspace(userInput[i]))
        {
            words++;
        }
        // char is punctuation that split sentence
        else if (isFinalPunctuation(userInput[i]) && !isFinalPunctuation(userInput[i - 1]))
        {
            sentences++;
        }
    }

    float grade = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;

    // check grade to print the expected result
    if (grade < 16 && grade > 1)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

bool isFinalPunctuation(char letter)
{
    return letter == '!' || letter == '.' || letter == '?';
}
