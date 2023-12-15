#!/usr/bin/python3
"""
Module to calculate the amount of rainwater retained between walls.
"""

def rain(walls):
    """
    Calculate the amount of rainwater retained between walls.

    Args:
        walls (List[int]): List of non-negative integers representing wall heights.

    Returns:
        int: Total amount of rainwater retained.

    Raises:
        ValueError: If the input list is empty or has less than 3 elements.
    """
    if not walls or len(walls) < 3:
        raise ValueError("Input list must contain at least 3 elements.")

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    total_water = 0
    for i in range(1, n - 1):
        min_height = min(left_max[i], right_max[i])
        if min_height > walls[i]:
            total_water += min_height - walls[i]
#!/usr/bin/python3
"""
Module to calculate the amount of rainwater retained between walls.
"""

def rain(walls):
    """
    Calculate the amount of rainwater retained between walls.

    Args:
        walls (List[int]): List of non-negative integers representing wall heights.

    Returns:
        int: Total amount of rainwater retained.

    Raises:
        ValueError: If the input list has less than 3 elements.
    """
    if len(walls) < 3:
        raise ValueError("Input list must contain at least 3 elements.")

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    total_water = 0
    for i in range(1, n - 1):
        min_height = min(left_max[i], right_max[i])
        if min_height > walls[i]:
            total_water += min_height - walls[i]

    return total_water
