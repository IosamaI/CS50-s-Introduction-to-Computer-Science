from cs50 import get_string


def count_letters(text):
    return sum(1 for char in text if char.isalpha())


def count_words(text):
    return sum(1 for word in text.split())


def count_sentences(text):
    return sum(1 for char in text if char in ".!?")


# Get user input
text = get_string("Text: ")

# Calculate counts
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

# Calculate average number of letters and sentences per 100 words
L = (letters / words) * 100
S = (sentences / words) * 100

# Compute the Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Output the grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
