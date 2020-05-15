from sys import argv
from cs50 import SQL

def main():
    # validate entry input
    if len(argv) != 2:
        print("usage error, roster.py house")
        exit()

    # open the SQLite database
    db = SQL('sqlite:///students.db')

    # getting the results for the SQL query
    rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last ASC, first ASC", argv[1])

    # foreach row
    for row in rows:

        print(row['first'], end =" ")
        # check if student has middle name
        if row['middle'] is not None:
            print(row['middle'], end =" ")
        print(row['last'] + ', born ' + str(row['birth']))

main()
