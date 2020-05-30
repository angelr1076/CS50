from cs50 import get_int


# Create helpers to call in main for spaces and hashes
def print_spaces(num):
    for i in range(num):
        print(" ", end="")


def print_hashes(num):
    for i in range(num):
        print("#", end="")


def print_tiles():
    while True:
        # Ask for user input
        height = get_int("Height: ")
        # If height is between 0 and 8, stop asking for input
        if height > 0 and height <= 8:
            break

    # Set spaces and hash nums outside of for loop
    spaces = height - 1
    hashes = 1

    for i in range(1, height + 1):
        print_spaces(spaces)
        print_hashes(hashes)
        print("  ", end="")
        print_hashes(hashes)
        print("\n", end="")
        spaces -= 1
        hashes += 1


# Call main function
print_tiles()