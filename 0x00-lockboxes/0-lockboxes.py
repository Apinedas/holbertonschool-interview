#!/usr/bin/python3

def canUnlockAll(boxes):
    '''canUnlockAll: Checks if a set of boxes (represented as a list of lists) can be opened'''
    got_keys = [0]
    total_boxes = list(range(0, len(boxes)))
    for i in got_keys:
        box = boxes[i]
        for key in box:
            if key not in got_keys:
                got_keys.append(key)
        box.clear()
    for box in total_boxes:
        if box not in got_keys:
            return False
    return True
