#!/usr/bin/python3
""" 0-minoperations file """


def minOperations(n):
    """ write a method that calculates the fewest num
    of operations needed to result in exactly n H characters """
    commands = 0

    if n <= 1 or not isinstance(n, int):
        return 0

    for i in range(2, n + 1):
        if i > n:
            break
        while n % i == 0:
            commands += i
            n /= i
    return commands
