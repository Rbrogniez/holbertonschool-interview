#!/usr/bin/python3

def validUTF8(data):
    # Helper function to check if a given byte is a valid UTF-8 continuation byte
    def is_continuation(byte):
        return (byte & 0b11000000) == 0b10000000

    # Initialize the number of expected continuation bytes to 0
    expected_continuations = 0

    for byte in data:
        # Keep only the 8 least significant bits of the byte
        byte = byte & 0b11111111

        if expected_continuations > 0:
            # If we are expecting continuation bytes, the current byte must be a continuation byte
            if not is_continuation(byte):
                return False
            expected_continuations -= 1
        else:
            if (byte & 0b10000000) == 0:
                # If the byte starts with '0', it's a single-byte character
                continue
            elif (byte & 0b11100000) == 0b11000000:
                # If the byte starts with '110', it's a two-byte character
                expected_continuations = 1
            elif (byte & 0b11110000) == 0b11100000:
                # If the byte starts with '1110', it's a three-byte character
                expected_continuations = 2
            elif (byte & 0b11111000) == 0b11110000:
                # If the byte starts with '11110', it's a four-byte character
                expected_continuations = 3
            else:
                # Invalid starting byte for UTF-8 character
                return False

    # If there are still expected continuations, it means the input is incomplete
    return expected_continuations == 0
