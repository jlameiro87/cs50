#include <cs50.h>
#include <stdio.h>

int countDigits(long number);
bool isVisa(long number);
bool isMasterCard(long number);
bool isAmericanExpress(long number);
bool calculateChecksum(long number);

int main(void)
{
    // Get the card number to validate
    long number = get_long("Number: ");
    // Count the credit card digits number
    int digits = countDigits(number);

    // If checksum is valid verify cards
    if (calculateChecksum(number))
    {
        // Checking for VISA Card
        if (isVisa(number) && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }
        // Checking for American Express Card
        else if (isAmericanExpress(number) && digits == 15)
        {
            printf("AMEX\n");
        } 
        // Checking for MasterCard Card
        else if (isMasterCard(number) && digits == 16)
        {
            printf("MASTERCARD\n");
        }
        // Card number not matching any card pattern
        else
        {
            printf("INVALID\n");
        }
    }
    // Checksum don't pass
    else
    {
        printf("INVALID\n");
    }
}

// Method to count the digits in the number
int countDigits(long number)
{
    int count = 0;
    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}

// For VISA cards
bool isVisa(long number)
{
    int digits = countDigits(number);
    int start = 0;
    if (digits == 13)
    {
        start = number / 1000000000000;
    }
    else if (digits == 16)
    {
        start = number / 1000000000000000;
    }
    
    return start == 4;
}

// For MasterCard
bool isMasterCard(long number)
{
    int digits = countDigits(number);
    int start = number / 100000000000000;
    return start == 51 || start == 52 || start == 53 || start == 54 || start == 55;
}

// For AmericanExpress
bool isAmericanExpress(long number)
{
    int digits = countDigits(number);
    int start = number / 10000000000000;
    return start == 34 || start == 37;
}

// Method to calculate the checsum
bool calculateChecksum(long number)
{
    int sum = 0;
    long number1 = number;
    int digits = countDigits(number);

    bool analize = false;
    for (int i = 0; i < digits; i++)
    {
        // Get alternated numbers
        if (analize == true)
        {
            long num = number1 % 10;
            int multiplication = num * 2;
            // If the multiplication is greather than 10, sum the digits
            if (multiplication >= 10)
            {
                sum += multiplication % 10;
                multiplication = multiplication / 10;
                sum += multiplication;
            }
            else
            {
                sum += multiplication;
            }
        }
        number1 = number1 / 10;
        analize = !analize;
    }

    analize = true;
    number1 = number;
    for (int i = 0; i < digits; i++)
    {
        if (analize)
        {
            int num2 = number1 % 10;
            sum += num2;
        }

        number1 = number1 / 10;
        analize = !analize;
    }

    return sum % 10 == 0;
}
