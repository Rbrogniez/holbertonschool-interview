#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.
    """
    coins.sort(reverse=True)
    add_coins = 0
    numb_coins = 0
    for i in range(len(coins)):
        while add_coins + coins[i] <= total:
            add_coins += coins[i]
            numb_coins += 1

    if numb_coins == 0 or total < 0:
        return 0
    elif add_coins != total:
        return -1
    else:
        return numb_coins
