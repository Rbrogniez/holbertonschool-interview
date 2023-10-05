#!/usr/bin/python3
"""
Module that reads stdin line by line and computes metrics
"""
import sys
import signal


status_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
count = 0
size = 0


def signal_handler(sig, frame):
    """Handle when CTRL + C is pressed"""
    print_stats()


def print_stats():
    """Print the stats obtained from the file"""
    print("File size: {}".format(size))
    for k, v in sorted(status_code.items()):
        if (v != 0):
            print("{:s}: {:d}".format(k, v))


signal.signal(signal.SIGINT, signal_handler)
for line in sys.stdin:
    line_split = line.split()
    len_line = len(line_split)
    if (len_line == 1):
        continue
    count += 1
    size += int(line_split[len_line - 1])
    if (line_split[len_line - 2] not in status_code.keys()):
        continue
    status_code[line_split[len_line - 2]] += 1

    if (count % 10 == 0):
        print_stats()
print_stats()
