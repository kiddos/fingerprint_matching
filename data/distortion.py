#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import re
import os
import random
import sys

QUERY = 'query'
REFERENCE = 'reference'

def distort_reference_set(input_path, output_path, distortion):
    if not os.path.exists(output_path):
        os.mkdir(output_path)

    minutia_files = os.listdir(input_path)

    for minutia_file in minutia_files:
        input_full_path = os.path.join(input_path, minutia_file)
        output_full_path = os.path.join(output_path, minutia_file)

        if not minutia_file.endswith('.txt'):
            continue

        mf = open(input_full_path, "r")
        distorted_file = open(output_full_path, "w")

        print 'distorting ', input_full_path, ' ...'
        num = -1
        for line in mf:
            if not line.startswith('--') and \
                    line.replace('\r', '\n').replace('\n', '') != '':
                if num < 0:
                    num = int(line)
                    distorted_file.write(str(num))
                else:
                    pattern = r'p([0-9]+) = \(([0-9]+),([0-9]+)\)'
                    query = re.findall(pattern, line)

                    mnum = int(query[0][0])
                    x = int(query[0][1])
                    y = int(query[0][2])

                    distortx = random.randrange(distortion * 2) - distortion
                    distorty = random.randrange(distortion * 2) - distortion
                    x += distortx
                    y += distorty

                    if x < 0: x = 0
                    if y < 0: y = 0

                    distorted_file.write('p' + str(mnum) + ' = (')
                    distorted_file.write(str(x) + ',' + str(y) + ')\n')
            else:
                distorted_file.write(line.replace('\r', ''))

        mf.close()
        distorted_file.close()

if __name__ == '__main__':
    try:
        direct = sys.argv[1]
        distortion = int(sys.argv[2])
        input_path = os.path.join(direct, REFERENCE)
        output_path = os.path.join(direct, QUERY)
        distort_reference_set(input_path, output_path, distortion)
    except:
        print 'usage: ./distortion.py <directory> <distortion amount>'

