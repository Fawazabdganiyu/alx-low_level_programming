#!/usr/bin/python3
"""From:
uncompyle6 version 3.9.0
"""
#pwd = input('Password: ')
ok = 'Zen of Python'
ok = ok + ' C'
ok = ok[1:3] + ok[3] + ok[14] + ok[3] + ok[7:9] + ok[:6][::-1]
#if pwd == ok:
#    print('OK')
#else:
#    print('KO')
print(ok)
