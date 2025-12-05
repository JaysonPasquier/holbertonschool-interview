#!/usr/bin/python3
def canUnlockAll(boxes):
    """Determine if all boxes can be opened."""
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    opened = set([0])
    keys = list(boxes[0])

    while keys:
        key = keys.pop()

        if key < n and key not in opened:
            opened.add(key)
            for new_key in boxes[key]:
                if new_key not in opened:
                    keys.append(new_key)

    return len(opened) == n
