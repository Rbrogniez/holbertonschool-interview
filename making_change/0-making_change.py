#!/usr/bin/python3
"""
Making change function
"""


def makeChange(coins, total):
    coins.sort(reverse=True)
    add_coins = 0
    numb_coins = 0
    for i in range(len(coins)):
        while add_coins + coins[i] <= total:
            add_coins += coins[i]
            numb_coins += 1

    if add_coins != total:
        return -1
    elif numb_coins == 0:
        return 0
    else:
        return numb_coins
