import math

# Create helpers


def get_letters(text):
    # Count letters
    letter_count = 0
    for l in text.lower():
        if l.isalnum() == True:
            letter_count += 1
    return letter_count


def get_words(text):
    # Count words
    word_count = 1
    for i in range(len(text)):
        if(text[i] == ' ' or text[i] == '\n' or text[i] == '\t'):
            word_count += 1
    return word_count


def get_sentences(text):
    # Count sentences
    sentence_count = 0
    for i in text:
        if i == '.' or i == '!' or i == '?':
            sentence_count += 1
    return sentence_count


def main():
    while True:
        # Ask for user input
        user_input = input("Enter text: ")

        # Call helper functions and pass same text to each
        letters = get_letters(user_input)
        words = get_words(user_input)
        sentences = get_sentences(user_input)

        # Calculate the letters and sentences per 100 words of the text with floats once helpers are done 100 * the variable / words
        L = letters / words * 100
        S = sentences / words * 100

        # Coleman-Liau index
        index = 0.0588 * L - 0.296 * S - 15.8
        floating_index = float(index)
        print(floating_index)

        # Round floating_index for final grade
        final_grade = round(floating_index)

        if final_grade < 1:
            return(print('Before Grade 1'))
        elif final_grade >= 16:
            return(print('Grade 16+'))
        else:
            return(print(f'Grade {final_grade}'))


# Call main function
main()
