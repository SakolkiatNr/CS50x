from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n <= 8:
        break


def print_pyramid(n):
    for i in range(n):
        # Blank space
        print(" " * (n - i - 1), end="")
        print(("#" * (i+1)) + "  " + ("#" * (i+1)))


print_pyramid(n)
