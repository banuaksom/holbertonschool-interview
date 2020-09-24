#!/usr/bin/python3
'''
Determines if a given data set represents a valid UTF-8 encoding
'''


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    """
    valid = []
    for i in data:
        if (i >= 0 and i < 256):
            valid.append(True)
        else:
            valid.append(False)
    return (all(valid))
