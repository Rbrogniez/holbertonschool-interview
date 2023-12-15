def rain(walls):
    if not walls:
        return 0

    n = len(walls)
    left_max, right_max = [0] * n, [0] * n
    left_max[0] = walls[0]
    right_max[n - 1] = walls[n - 1]

    # Calculate the maximum height from the left for each position
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Calculate the maximum height from the right for each position
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    total_water = 0

    # Calculate the amount of water that can be retained at each position
    for i in range(n):
        water_at_position = min(left_max[i], right_max[i]) - walls[i]
        total_water += max(water_at_position, 0)

    return total_water
