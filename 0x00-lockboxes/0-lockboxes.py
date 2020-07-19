#!/usr/bin/python3


def canUnlockAll(boxes):
    open = [False for i in range(len(boxes))]
    if len(boxes) == 0:
        return True
    open[0] = True
    l1 = [0]

    while len(l1) > 0:
        l2 = []
        for i in l1:
            for num in boxes[i]:
                if num < len(boxes) and not open[num]:
                    l2.append(num)
                    open[num] = True
        l1 = l2

    return all(open)
