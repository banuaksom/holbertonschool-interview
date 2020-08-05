def minOperations(n):
    commands = 0

    if n == 1:
        return commands

    for i in range(2, n + 1):
        while n % i == 0:
            commands += i
            n /= i
    return commands
