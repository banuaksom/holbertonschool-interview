#!/usr/bin/python3


def validUTF8(data):
    valid = []
    for i in data:
        if (i >= 0 and i < 256):
            valid.append(True)
        else:
            valid.append(False)
    return all(valid)