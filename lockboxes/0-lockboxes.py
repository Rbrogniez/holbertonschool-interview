def canUnlockAll(boxes):
    keys = set([0])

    open_boxes = set([0])

    while open_boxes:
        box = open_boxes.pop()
        for key in boxes[box]:
            if key < len(boxes) and key not in keys:
                keys.add(key)
                open_boxes.add(key)

    return len(keys) == len(boxes)
