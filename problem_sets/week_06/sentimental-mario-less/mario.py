from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n <= 8:
        break


def print_row(n):
    for i in range(n):
        # blank
        print(" " * (n - i - 1), end="")
    # bricks
        print("#" * (i + 1))


print_row(n)
