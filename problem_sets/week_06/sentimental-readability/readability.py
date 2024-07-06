# Import get_string from cs50 library
from cs50 import get_string


def compute_index(text):
    # Tracking
    letters = sum(1 for letter in text if letter.isalpha())
    words = len(text.split())
    sentences = sum(1 for punct in text if punct in '.!?')

    # Apply Coleman-Liau index
    index = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)

    if index < 1:
        return print('Before Grade 1')
    elif 1 <= index <= 16:
        return print(f'Grade {index}')
    else:
        return print('Grade 16+')


text = get_string("Text: ")
compute_index(text)
