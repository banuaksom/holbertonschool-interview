#!/usr/bin/python3


def canUnlockAll(boxes):
    open = [False for i in range(len(boxes))]
    open[0] = True
    l1 = [x for x in boxes[0]]
    while len(l1) > 0:
        l2 = []
        for i in l1:
            open[i] = True
            for num in boxes[i]:
                if not open[num]:
                    l2.append(num)
        l1 = l2
    for i in open:
        if not i:
            return False

    return True
