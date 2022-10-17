#!/usr/bin/python3
'''UTF8 Validator'''


def validUTF8(data):
    '''Validates UTF-8 Through binary conversion'''
    i = 0
    while i < len(data):
        binary_byte = bin(data[i]).split('b')[1]
        while len(binary_byte) < 8:
            binary_byte = '0' + binary_byte
        else:
            binary_byte = binary_byte[-8:]
        total_ones_in_a_row = 0
        if binary_byte[0] == '0':
            i += 1
            continue

        for j in range(0, 4):
            if binary_byte[j] == '1':
                total_ones_in_a_row += 1
            else:
                break

        if total_ones_in_a_row < 2:
            return False

        for j in range(i + 1, i + total_ones_in_a_row):
            try:
                actual_binary_byte = bin(data[j]).split('b')[1]
            except Exception:
                return False
            if actual_binary_byte[0:2] != '10':
                return False
            i += 1

        i += 1

    return True
