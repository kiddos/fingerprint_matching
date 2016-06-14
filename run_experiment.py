#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append('data')
import distortion as d
import create_list as cl
import subprocess
import os

DIR = './data'
NUM = 10

def run():
    query_path = os.path.join(DIR, d.QUERY)
    reference_path = os.path.join(DIR, d.REFERENCE)
    cl.create_order_list(reference_path)

    for dis in range(1, 11):
        print 'distortion: ', dis

        d.distort_reference_set(reference_path, query_path, dis)
        cl.create_random_list(query_path, NUM)

        p = subprocess.Popen('./test/fingerprintset_test', shell=True,
                             stdout=subprocess.PIPE)
        result = p.stdout.read()
        print result

if __name__ == '__main__':
    run()
