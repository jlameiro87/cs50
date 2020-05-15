from cs50 import get_int

# main function
def main():
    # get the card number to validate
    number = get_int("Number: ")

    # count the credit card digits number
    digits = countDigits(number)

    # if checksum is valid verify cards
    if calculateChecksum(number):
        # checking for VISA Card
        if isVisa(number) and (digits == 13 or digits == 16):
            print("VISA")
        # Checking for American Express Card
        elif isAmericanExpress(number) and digits == 15:
            print("AMEX")
        # Checking for MasterCard Card
        elif isMasterCard(number) and digits == 16:
            print("MASTERCARD")
        # Card number not matching any card pattern
        else:
            print("INVALID")
    # Checksum don't pass
    else:
        print("INVALID")


# method to count number of digits in the credit card number
def countDigits(number):
    count = 0

    while number != 0:
        number = number // 10
        count += 1

    return count

# method to calculate the checsum
def calculateChecksum(number):
    # initialize the variables to be used
    sum = 0
    number1 = number
    digits = countDigits(number)
    analize = False

    for i in range(digits):
        # get alternated numbers
        if analize:
            num = number1 % 10
            multiplication = num * 2

            # if the multiplication is greather than 10, sum the digits
            if multiplication >= 10:
                sum += multiplication % 10
                multiplication = multiplication // 10
                sum += multiplication
            else:
                sum += multiplication;

        number1 = number1 // 10
        analize = not analize

    analize = True
    number1 = number

    for i in range(digits):
        if analize:
            num2 = number1 % 10
            sum += num2

        number1 = number1 // 10
        analize = not analize

    return sum % 10 == 0

# For VISA cards
def isVisa(number):
    digits = countDigits(number)
    start = 0
    if digits == 13:
        start = number // 1000000000000
    elif digits == 16:
        start = number // 1000000000000000

    return start == 4

# For AmericanExpress
def isAmericanExpress(number):
    digits = countDigits(number)
    start = number // 10000000000000
    values = [34, 37]
    return start in values

# For MasterCard
def isMasterCard(number):
    digits = countDigits(number)
    start = number // 100000000000000
    values = [51, 52, 53, 54, 55]
    return start in values


main()
