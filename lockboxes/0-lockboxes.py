#!/usr/bin/python3
"""Module checking if the boxes can all be unlocked"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes in a list of boxes can be unlocked.

    Args:
    - boxes (list): boxes and their keys

    Returns:
    - bool: True if all boxes can be unlocked, False otherwise
    """
    open_boxes = {0: True}
    for i in range(len(boxes)):
        if i not in open_boxes.keys():
            open_boxes.update({i: False})
        open_boxes = unlockBoxes(boxes, open_boxes, i)
    return len(set(open_boxes.values())) == 1


def unlockBoxes(boxes, open_boxes, index):
    """
    Recursively unlocks boxes in a list of boxes.

    Args:
    - boxes (list): all boxes and their keys
    - open_boxes (dict): state of each box
    - index (int): index of the box to be opened

    Returns:
    - dict: updated state of each box
    """

    if open_boxes.get(index):
        for key in boxes[index]:
            is_opened = open_boxes.get(key)
            if key < index and not is_opened:
                open_boxes.update({key: True})
                open_boxes = unlockBoxes(boxes, open_boxes, key)
            elif not is_opened:
                open_boxes.update({key: True})
    return open_boxes
