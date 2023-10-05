#!/usr/bin/python3
"""Module for parse log"""

import sys
import fileinput

status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                "405": 0, "500": 0}
file_size = 0
nbline = 1

try:
    for line in fileinput.input():
        check_format = line.split()
        check_nb = len(check_format)
        if check_nb == 7:
            file_size += 1000
            status_code = line.split('"')[2].split()[0]
            for key, value in status_codes.items():
                if status_code == key:
                    status_codes[key] = value + 1
        elif check_nb == 9:
            status_code = line.split('"')[2].split()[0]
            file_size += int(line.split('"')[2].split()[1])
            for key, value in status_codes.items():
                if status_code == key:
                    status_codes[key] = value + 1
            if nbline % 10 == 0 and nbline != 0:
                print("File size: {}".format(file_size))
                for key in sorted(status_codes.keys()):
                    if status_codes[key] > 0:
                        print("{}: {}".format(key, status_codes[key]))
            nbline = nbline + 1
        else:
            pass
except KeyboardInterrupt:
    pass
print("File size: {}".format(file_size))
for key in sorted(status_codes.keys()):
    if status_codes[key] > 0:
        print("{}: {}".format(key, status_codes[key]))
