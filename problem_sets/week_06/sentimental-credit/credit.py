# from cs50 import get_int,get_string
from cs50 import get_string
# import regex module
import re

# validate card


def check_valid(digits):
    checksum = 0
    length = len(digits)

    # Apply Luhn algorithm
    for i in range(length):
        digit = int(digits[length - 1 - i])
        # multiply digit
        if i % 2 != 0:
            digit *= 2
            if digit > 9:
                digit -= 9
        checksum += digit

    # check validity
    if checksum % 10 == 0:
        if digits[0] == '3' and (digits[1] in '47'):
            if length == 15:
                return print('AMEX')
        elif digits[0] == '5' and (digits[1] in '12345'):
            if length == 16:
                return print('MASTERCARD')
        elif digits[0] == '4' and length in [13, 16]:
            return print('VISA')
        else:
            return print('INVALID')
    else:
        return print('INVALID')


while True:
    card_digits = get_string("Number: ")
    # check prefix digit and lenth
    # prefix are 3, 4, 5
    # string length is betweeen 13-16
    # contain numeric only
    valid = re.fullmatch(r'^[3-5]\d{12,15}$', card_digits)
    if valid:
        check_valid(card_digits)
        break
    else:
        print('INVALID')
        break
