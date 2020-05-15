from cs50 import SQL

# open the SQLite database
db = SQL('sqlite:///students.db')

# empty database
db.execute('DELETE FROM students')
