# Demonstrates while loop

i = 0
while i < 3:
    print("meow")
    i += 1

# Better design
for i in range(3):
    print("meow)

# Abstraction with parameterization
def main():
    meow(3)

# Meow some number of times
def meow(n):
    for i in range(n):
        print("meow")

main()
