#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool checkIfKeyCotainsChars(string keyStr);

int main(int argc, string argv[])
{
    // check for arguments number
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }

    // get entered key
    string keyStr = argv[1];

    // convert key to int
    int key = atoi(keyStr);

    // check entered key
    if (key < 0 || checkIfKeyCotainsChars(keyStr))
    {
        printf("Nope\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        int length = strlen(plaintext);

        printf("ciphertext: ");
        for (int i = 0; i < length; i++)
        {
            // cipher uppercase letter
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
            // cipher lowercase letter
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            // return other letters
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");

        return 0;
    }
}

// method to check if the user enter in the key any non numeric character
bool checkIfKeyCotainsChars(string keyStr)
{
    bool cotainsChar = false;
    int strLength = strlen(keyStr);

    for (int i = 0; i < strLength; i++)
    {
        if (isalpha(keyStr[i]))
        {
            cotainsChar = true;
            break;
        }
    }

    return cotainsChar;
}
