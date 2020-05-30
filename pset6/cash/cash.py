from cs50 import get_float


def user_input():
    while True:
        # Ask for user input
        dollars_owed = get_float("Change owed: ")

        # Break if user enters 0 or negative number
        if dollars_owed >= 0:
            break

    # Round cents to the nearest penny two decimal spaces to the right
    cents_owed = round(dollars_owed * 100, 2)
    # Init coins to 0
    total_coins = 0

    # Set while loops for each coin group starting with the highest
    while cents_owed >= 25:
        cents_owed -= 25
        total_coins += 1

    while cents_owed >= 10:
        cents_owed -= 10
        total_coins += 1

    while cents_owed >= 5:
        cents_owed -= 5
        total_coins += 1

    while cents_owed >= 1:
        cents_owed -= 1
        total_coins += 1

    # Print total coins
    return print(total_coins)


# Call main function
user_input()