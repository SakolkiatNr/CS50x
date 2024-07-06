from cs50 import get_float

# Get non-negative value from user
while True:
    changes = get_float("Change: ")
    if changes >= 0:
        break


def cal_min_coins(n):
    # Track total coins
    coins = 0
    remain = int(n*100)

    while remain != 0:
        # quarters
        if remain >= 25:
            remain -= 25
            coins += 1
        # dimes
        elif remain >= 10:
            remain -= 10
            coins += 1
        # nickels
        elif remain >= 5:
            remain -= 5
            coins += 1
        # pennies
        else:
            remain -= 1
            coins += 1

    return coins


print(cal_min_coins(changes))
