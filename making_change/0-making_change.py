#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.
    """
    coins.sort(reverse=True)
    numb_coins = 0

    for coin in coins:
        if total >= coin:
            numb_coins += total // coin
            total %= coin

    if total == 0:
        return numb_coins
    else:
        return -1
