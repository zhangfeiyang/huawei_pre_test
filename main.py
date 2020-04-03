#!/usr/bin/python3

chains = []

file = open('test_data.txt','r')
lines = file.readlines()

for line in lines:
    datas = [int(x) for x in line.strip().split(',')]
  
    N = len(chains)
    for i in range(N):
        if chains[i][0] == chains[i][-1]:
            continue
        if datas[0] == chains[i][-1]:
            chains.append(chains[i]+[datas[1]])
        #if datas[1] == chains[i][0]:
        #    chains.append([datas[0]]+chains[i])
    chains.append(datas[0:2])

for line in lines:
    datas = [int(x) for x in line.strip().split(',')]
  
    N = len(chains)
    for i in range(N):
        if chains[i][0] == chains[i][-1]:
            continue
        if datas[0] == chains[i][-1]:
            chains.append(chains[i]+[datas[1]])
        #if datas[1] == chains[i][0]:
        #    chains.append([datas[0]]+chains[i])
    chains.append(datas[0:2])

loopchains = []

file_debug = open("debug",'w')

for chain in chains:
    file_debug.write(str(chain)+'\n')
    if not chain[0] == chain[-1]:
        continue
    chain = chain[0:-1]
    minindex = chain.index(min(chain))
    chain = chain[minindex:] + chain[:minindex]
    N1 = len(chain)
    if N1 < 3 or N1 > 7:
        continue
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

N = len(loopchains)

file_res = open('result2.txt','w')
for i in range(0,N):
    file_res.write(','.join([str(x) for x in loopchains[i]])+'\n')
