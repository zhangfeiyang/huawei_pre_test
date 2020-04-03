#!/usr/bin/python3


chains = []

file = open('test_data.txt','r')
lines = file.readlines()

l1_chains = []
for line in lines:
    datas = [int(x) for x in line.strip().split(',')]
    l1_chains.append(datas) 

N = len(l1_chains)
l2_chains = []
for i in range(N):
    for j in range(i+1):
        if l1_chains[i][1] == l1_chains[j][0]:
            l2_chains.append(l1_chains[i][0:2]+[l1_chains[j][1]])

        if l1_chains[i][0] == l1_chains[j][1]:
            l2_chains.append(l1_chains[j][0:2]+[l1_chains[i][1]])
N = len(l2_chains)
i = 0
for j in range(N):
    if l2_chains[i][0] == l2_chains[i][-1]:
        l2_chains.remove(l2_chains[i])
    else:
        i = i + 1

N =len(l2_chains)
l3_chains = []
for i in range(N):
    for j in range(i+1):
        if l2_chains[i][1:] == l2_chains[j][0:-1]:
            l3_chains.append(l2_chains[i]+[l2_chains[j][-1]])

        if l2_chains[i][0:2] == l2_chains[j][1:]:
            l3_chains.append(l2_chains[j]+[l2_chains[i][-1]])

loopchains = []
N = len(l3_chains)
i = 0
for j in range(N):
    if l3_chains[i][0] == l3_chains[i][-1]:
        loopchains.append(l3_chains[i])
        l3_chains.remove(l3_chains[i])
    else:
        i = i + 1

N =len(l3_chains)
l4_chains = []
for i in range(N):
    for j in range(i+1):
        if l3_chains[i][1:] == l3_chains[j][0:-1]:
            l4_chains.append(l3_chains[i]+[l3_chains[j][-1]])

        if l3_chains[i][0:-1] == l3_chains[j][1:]:
            l4_chains.append(l3_chains[j]+[l3_chains[i][-1]])

N = len(l4_chains)
i = 0
for j in range(N):
    if l4_chains[i][0] == l4_chains[i][-1]:
        loopchains.append(l4_chains[i])
        l4_chains.remove(l4_chains[i])
    else:
        i = i + 1

N =len(l4_chains)
l5_chains = []
for i in range(N):
    for j in range(i+1):
        if l4_chains[i][1:] == l4_chains[j][0:-1]:
            l5_chains.append(l4_chains[i]+[l4_chains[j][-1]])

        if l4_chains[i][0:-1] == l4_chains[j][1:]:
            l5_chains.append(l4_chains[j]+[l4_chains[i][-1]])
N = len(l5_chains)
i = 0
for j in range(N):
    if l5_chains[i][0] == l5_chains[i][-1]:
        loopchains.append(l5_chains[i])
        l5_chains.remove(l5_chains[i])
    else:
        i = i + 1


N =len(l5_chains)
l6_chains = []
for i in range(N):
    for j in range(i+1):
        if l5_chains[i][1:] == l5_chains[j][0:-1]:
            l6_chains.append(l5_chains[i]+[l5_chains[j][-1]])

        if l5_chains[i][0:-1] == l5_chains[j][1:]:
            l6_chains.append(l5_chains[j]+[l5_chains[i][-1]])

N = len(l6_chains)
i = 0
for j in range(N):
    if l6_chains[i][0] == l6_chains[i][-1]:
        loopchains.append(l6_chains[i])
        l6_chains.remove(l6_chains[i])
    else:
        i = i + 1

N =len(l6_chains)
l7_chains = []
for i in range(N):
    for j in range(i+1):
        if l6_chains[i][1:] == l6_chains[j][0:-1]:
            l7_chains.append(l6_chains[i]+[l6_chains[j][-1]])

        if l6_chains[i][0:-1] == l6_chains[j][1:]:
            l7_chains.append(l6_chains[j]+[l6_chains[i][-1]])

N = len(l7_chains)
i = 0
for j in range(N):
    if l7_chains[i][0] == l7_chains[i][-1]:
        loopchains.append(l7_chains[i])
        l7_chains.remove(l7_chains[i])
    else:
        i = i + 1

file_debug = open("debug",'w')
chains = loopchains
loopchains = []

for chain in chains:
    #file_debug.write(str(chain)+'\n')
    #if not chain[0] == chain[-1]:
    #    continue
    chain = chain[0:-1]
    minindex = chain.index(min(chain))
    chain = chain[minindex:] + chain[:minindex]
    N1 = len(chain)
    N2 = len(loopchains)
    if N2 == 0:
        loopchains.append(chain)
    for i in range(N2):
        if N1 < len(loopchains[i]):
            loopchains.insert(i,chain)
            break
        if N1 == len(loopchains[i]):
            if chain[0] < loopchains[i][0]:
                loopchains.insert(i,chain)
                break

        if i == N2 -1:
            loopchains.append(chain)

#loopchains = [tuple(x) for x in loopchains]
#loopchains = list(set(loopchains))
loopchains2 = []
for loopchain in loopchains:
    if not loopchain in loopchains2:
        loopchains2.append(loopchain)

file_res = open('result2.txt','w')
N = len(loopchains2)
file_res.write(str(N)+"\n")
for i in range(0,N):
    file_res.write(','.join([str(x) for x in loopchains2[i]])+'\n')
