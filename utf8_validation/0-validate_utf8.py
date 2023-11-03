def validUTF8(data):
    # Helper function to check if a byte is a valid UTF-8 start byte
    def is_start_byte(byte):
        return (byte & 0b10000000) == 0b0

    # Helper function to check if a byte is a valid UTF-8 continuation byte
    def is_continuation_byte(byte):
        return (byte & 0b11000000) == 0b10000000

    # Initialize a count to keep track of expected continuation bytes
    count = 0

    for byte in data:
        if count == 0:
            if is_start_byte(byte):
                # Determine the number of continuation bytes based on the start byte
                if (byte & 0b11100000) == 0b11000000:
                    count = 1
                elif (byte & 0b11110000) == 0b11100000:
                    count = 2
                elif (byte & 0b11111000) == 0b11110000:
                    count = 3
                else:
                    # Invalid start byte
                    return False
            else:
                # Invalid start byte
                return False
        else:
            if is_continuation_byte(byte):
                count -= 1
            else:
                # Invalid continuation byte
                return False

    # Check if all expected continuation bytes are present
    return count == 0

# Test cases
data1 = [197, 130, 1]  # Represents the valid UTF-8 character 'Ç' (U+00C7)
data2 = [235, 140, 4]  # Invalid UTF-8 data
print(validUTF8(data1))  # Output: True
print(validUTF8(data2))  # Output: False
