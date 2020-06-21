from cs50 import SQL
import sys
from sys import argv, exit
import csv


def main():
    # If the incorrect number of command-line arguments are provided, the program should print an error and exit.
    if len(argv) != 2:
        print("Please enter the name of your csv file after import.py")
        exit(1)

    # set db variable
    db = SQL("sqlite:///students.db")

    # set argv 1 as a variable
    csv_arg = sys.argv[1]

    with open(csv_arg, mode="r") as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            # for each row, parse name - use split method on strings to split into words
            student_name = row["name"].split()
            house_name = row["house"]
            birthdate = row["birth"]

            if len(student_name) == 3:
                first = student_name[0]
                middle = student_name[1]
                last = student_name[2]
            else:
                first = student_name[0]
                # use None for student's middle name if they don't have one
                middle = None
                last = student_name[1]

            # insert each student into the students table of the students.db
            # use db.execute to INSERT a row into the table
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       first, middle, last, house_name, birthdate)


# call main function
if __name__ == '__main__':
    main()
