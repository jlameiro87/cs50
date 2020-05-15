from cs50 import get_float

# main function
def main():
    # initialize change to 0
    change = 0

    # keep asking for the change until a valid value is passed
    while change <= 0:
        change = get_float('Change owed: ')

    # rounding the user input
    cents = round(change * 100);

    # coins used to give a change
    coins = 0

    # while I can give change
    while cents > 0:
        if cents - 25 >= 0:
            cents -= 25
            coins += 1
        elif cents - 10 >= 0:
            cents -= 10
            coins += 1
        elif cents - 5 >= 0:
            cents -= 5
            coins += 1
        else:
            cents -= 1
            coins += 1

    print(coins)

main()
