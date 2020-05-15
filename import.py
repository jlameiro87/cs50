from cs50 import SQL
from csv import reader
from sys import argv

def main():
    # validate entry input
    if len(argv) != 2:
        print("usage error, import.py characters.csv")
        exit()

    # open the SQLite database
    db = SQL('sqlite:///students.db')

    # open the csv file and copy the content to a list
    with open(argv[1], newline='') as charactersFile:
        # read the characters
        characters = reader(charactersFile)
        # for each character
        for character in characters:
            # check for empty names
            if character[0] == 'name':
                continue

            # split the full name into first, last and middle name as required
            fullName = character[0].split()

            # character dictionary
            charDictionary = {
                'first': fullName[0],
                'middle': fullName[1] if len(fullName) > 2 else None,
                'last': fullName[2] if len(fullName) > 2 else fullName[1],
                'house': character[1],
                'birth': character[2]
            }

            # insert the character into the database
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                charDictionary['first'], charDictionary['middle'], charDictionary['last'], charDictionary['house'], charDictionary['birth'])

main()
