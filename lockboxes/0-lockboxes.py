#!/usr/bin/python3
"""
Module: 0-lockboxes
Determines if all boxes in a list can be unlocked.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    Args:
        boxes (list of lists): A list where each index represents a box,
        and each box contains a list of keys.

    Returns:
        bool: True if all boxes can be opened, otherwise False.
    """
    if not isinstance(boxes, list) or len(boxes) == 0:
        return False

    opened = set([0])        # Box 0 is unlocked
    keys = set(boxes[0])     # Keys found in box 0

    while keys:
        key = keys.pop()

        if key < len(boxes) and key not in opened:
            opened.add(key)
            # Add all new keys found in this newly opened box
            for k in boxes[key]:
                if k not in opened:
                    keys.add(k)

    return len(opened) == len(boxes)
