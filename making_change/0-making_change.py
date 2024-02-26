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

    if add_coins != total:
        return -1
    elif numb_coins == 0:
        return 0
    else:
        return numb_coins
