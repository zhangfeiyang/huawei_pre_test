#!/usr/bin/python

a = [1,2,3,4,5,6]

for b in a:
    print(b)
    if b == 3:
        a.remove(b)
print(a)
