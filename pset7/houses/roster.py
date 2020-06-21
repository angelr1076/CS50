from cs50 import SQL
import sys
from sys import argv, exit
import csv
# python roster.py <then name of house> in command line
# to test and query the db, run sqlite3 students.db


def main():

    # check command line arguments
    if len(argv) != 2:
        print("Please enter the name of the house you'd like a printed roster for after import.py")
        exit(1)

    # set db variable
    db = SQL("sqlite:///students.db")

    # set argv 1 as a variable for house name
    house_name = sys.argv[1]

    # use db.execute to SELECT rows from the table
    # students should be sorted alphabetically by last name, then first name
    # return value will be a list of Python dicts, where each dict represents a row in the table
    roster_query = db.execute(
        "SELECT first, middle, last, birth FROM students WHERE house=? ORDER BY last, first ASC ", (house_name))

    for row in roster_query:
        # remember to check for NULL values for middle names (check if None, continue)
        if row['middle'] == None:
            print(f"{row['first']} {row['last']}, born {row['birth']}")
        # print out each student's full name and birth year
        else:
            print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")


# call main function
if __name__ == '__main__':
    main()
