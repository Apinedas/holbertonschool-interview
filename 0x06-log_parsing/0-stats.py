#!/usr/bin/python3
import re
import signal
import sys

ip = r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'
date = r'(\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.*\d*])'
getCode = r'("GET \/projects\/260 HTTP\/1.1")'
stat = r'(200|301|400|401|403|404|405|500)'
fileSize = r'(\d+)'

regexFormat = re.compile(
    '{} - {} {} {} {}'.format(ip, date, getCode, stat, fileSize))

statusCodes = {'200': 0,
               '301': 0,
               '400': 0,
               '401': 0,
               '403': 0,
               '404': 0,
               '405': 0,
               '500': 0}
counter = 0
totalSize = 0

def signalHandler(sig, frame):
    print('File size: {}'.format(totalSize))
    for code, count in statusCodes.items():
        print('{}: {}'.format(code, count))

signal.signal(signal.SIGINT, signalHandler)

for line in sys.stdin:
    if regexFormat.match(line) is not None:
        counter += 1
        splittedLine = line.split(' ')
        statusCodes[splittedLine[7]] += 1
        totalSize += int(splittedLine[-1])
        if counter == 10:
            print('File size: {}'.format(totalSize))
            counter = 0
            for code, count in statusCodes.items():
                print('{}: {}'.format(code, count))

