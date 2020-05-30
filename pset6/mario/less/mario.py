from cs50 import get_int


def print_tiles():
    while True:
        # Ask user for input
        height = get_int("Height: ")
        # Set width variable equal to height - used in for loop
        width = height
        # If height is between 0 and 8, stop asking for input
        if height > 0 and height <= 8:
            break

    for i in range(1, height + 1):
        hashes = i
        spaces = width - hashes
        print(" " * spaces, end="")
        print("#" * hashes, end="\n")


# Call main function
print_tiles()
