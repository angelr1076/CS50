import csv
import sys
from sys import argv, exit


# separate function for final comparison between csv file and dna text
def compare_seq(dna_csv, string):
#for each row in the data, check if each STR count matches. If so, print out the person's name
    for row in dna_csv:
        # define the name column
        name = row[0]
        # skip the name column, start at 1st character in each list [1:] and convert each character str to an int
        dna_count = [int(count)for count in row[1:]]
        # compare the dna_count list with the str_list
        if dna_count == string:
            print(name)
            return
    # If STR counts do not match exactly with any individuals in .csv, program should print() "No Match"
    print("No match")


def main():
    # Print error message if the incorrect number of arguments are entered, with print()
    if (len(argv) != 3):
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    # First command-line arg is name of .csv containing STR counts for list of ppl
    # Second command-line arg is name of text file containing the DNA sequence to identify
    csv_arg = sys.argv[1]
    txt_arg = sys.argv[2]

    # program should open the .csv file and read its contents into memory
    # read .csv file
    with open(csv_arg, mode='r') as csv_file:
        # convert the .csv to a list and save to memory
        csv_list = list(csv.reader(csv_file))

        # create empty list for each row of csv
        people_dna = []
        for i in range(1, len(csv_list)):
            # Push the entire csv list into people_dna excluding the first row
            people_dna.append(csv_list[i])

        # save the first row, genome names from the csv file to a variable
        genomes_row = csv_list[0]
        # and remove 'name' from the row
        genomes_row.remove('name')

# open DNA sequence and read into memory (DNA sequence/.txt file)
    with open(txt_arg, 'r') as text_file:

        # READ TXT FILE AS A STRING
        dna_sequence = text_file.read()

    # DICT OF THE ROW HEADER OF THE CSV FILE, SET ALL VALUES TO 0, {'AGATC': 0, 'TTTTTTCT': 0, 'AATG': 0, 'TCTAG': 0, 'GATA': 0, 'TATC': 0, 'GAAA': 0, 'TCTG': 0}
    genomes_dict = dict.fromkeys(genomes_row, 0)

    # count_STRs(genomes_dict, dna_sequence)

    # go through all the short tandem repeats in genomes_dict
    str_list = []
    for keys in genomes_dict:
        # counters
        curr_count = 0
        max_found = 0
        # set the length of each dict key for count sequence
        size = len(keys)
        # index
        i = 0

        # stay within dna_sequence length without segfaulting
        while i < len(dna_sequence):
            capture = dna_sequence[i:(i + size)]
            if capture == keys:
                curr_count += 1
                if ((i + size) <= len(dna_sequence)):
                    i = i + size
                continue
            else:
                if curr_count > max_found:
                    max_found = curr_count
                    curr_count = 0
                else:
                    curr_count = 0
            i += 1
        genomes_dict[keys] = max_found
        # Save STR counts into a list
        str_list.append(genomes_dict[keys])

    compare_seq(people_dna, str_list)


# Call main function
main()