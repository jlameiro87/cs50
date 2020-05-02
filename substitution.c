#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool checkKey(string key);
bool checkRepeatedChar(string key);

int main(int argc, string argv[])
{
    // check for arguments number
    if (argc != 2)
    {
        printf("Only one command-line parameter is required\n");
        return 1;
    }

    // get entered key
    string key = argv[1];

    // check if entered key is valid
    if (!checkKey(key))
    {
        printf("The key you entered is invalid\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    int charCount = strlen(plainText);

    char cipherText[charCount];
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < charCount; i++)
    {
        // letter is uppercase
        if (isupper(plainText[i]))
        {
            // replace the character
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == tolower(plainText[i]))
                {
                    cipherText[i] = toupper(key[j]);
                    break;
                }
            }
        }
        // letter is lowercase
        else if (islower(plainText[i]))
        {
            // replace the character
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == plainText[i])
                {
                    cipherText[i] = tolower(key[j]);
                    break;
                }
            }
        }
        // non alpha characte, keep it same
        else
        {
            cipherText[i] = plainText[i];
        }
    }

    // fixed solution for single letters
    if (charCount == 1)
    {
        printf("ciphertext: %c\n", cipherText[0]);
    }
    else
    {
        printf("ciphertext: %s\n", cipherText);
    }

    return 0;
}

/*
 * Method to check the entered key
 *
 * As by not containing 26 characters, containing any character that is not an alphabetic character,
 * or not containing each letter exactly once
*/
bool checkKey(string key)
{
    int strLength = strlen(key);
    bool isValidKey = true;
    // check key length
    if (strLength != 26)
    {
        isValidKey = false;
    }
    // check key characters
    else
    {
        // check for invalid characters
        for (int i = 0; i < strLength; i++)
        {
            if (!isalpha(key[i]))
            {
                return false;
            }
        }

        // check for duplicated characters
        isValidKey = !checkRepeatedChar(key);
    }
    return isValidKey;
}

// method to check if a character is repeated
bool checkRepeatedChar(string key)
{
    bool repeated = false;
    int strLength = strlen(key);
    for (int i = 0; i < strLength; i++)
    {
        for (int j = i + 1; j < strLength; j++)
        {
            if (key[i] == key[j])
            {
                repeated = true;
                break;
            }
        }
        // check if any duplicated character was founded
        if (repeated)
        {
            break;
        }
    }
    return repeated;
}
