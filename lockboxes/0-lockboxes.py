#!/usr/bin/python3
"""
    Determine if all locked boxes can be opened using provided keys.
"""
def canUnlockAll(boxes):
    """
    Determine if all locked boxes can be opened using provided keys.
    """

    n = len(boxes)  # Total number of boxes
    unlocked = [False] * n  # List to track whether each box is unlocked
    unlocked[0] = True  # The first box is unlocked by default
    stack = [0]  # Start with the first box

    while stack:
        current_box = stack.pop()
        for key in boxes[current_box]:
            if key < n and not unlocked[key]:
                unlocked[key] = True
                stack.append(key)

    return all(unlocked)    
