#!/usr/bin/python3
""" 0-minoperations file """


def minOperations(n):
    """ write a method that calculates the fewest num
    of operations needed to result in exactly n H characters """
    commands = 0

    if n <= 1:
        return 0

    i = 2
    while i * i <= n:
        while n % i == 0:
            commands += i
            n = n // i
    if n > 1:
        commands += n

    return commands
