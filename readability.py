from cs50 import get_string

# main function
def main():
    user_input = get_string("Text: ")
    # get user entry length
    length = len(user_input)

    # letters to be counted
    letters = 0
    # spaces are used to count words
    words = 1
    # punctuation signs used to count sentences
    sentences = 0

    # iterate over each character in the user entry
    for i in range(length):
        # counts letters using ascii code
        if (ord(user_input[i]) >= 65 and ord(user_input[i]) <= 122):
            letters += 1

        # counts words by reading spaces
        elif (user_input[i].isspace()) == True:
            words += 1

        # counts sentences by finding dots, exclamation marks and interrogatives
        elif isFinalPunctuation(user_input[i]) and not isFinalPunctuation(user_input[i - 1]):
            sentences += 1

    print(f"letters {letters}")
    print(f"sentences {sentences}")
    print(f"words {words}")

    L = letters * 100 / words
    S = sentences * 100 / words
    # calculating Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # check grade to print the expected result
    if (index < 1):
        print("Before Grade 1")
    elif (index >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {index}")

# method to check final punctuations characters
def isFinalPunctuation(letter):
    return ord(letter) == 33 or ord(letter) == 46 or ord(letter) == 63

main()
