from encodings import utf_8
import os, pprint

t_base = []
with open('base.txt', 'r', encoding='utf') as base:
    t_base = base.readlines()

t_mex = []
with open('base_mex.txt', 'r', encoding='utf') as base:
    t_mex = base.readlines()

print(len(t_base))

for l in t_mex:
    c = t_base.count(l)
    if c == 1:
        n_base = []
        for t in t_base:
            if t == l:
                n_base.append('')
            else:
                n_base.append(t)
        t_base = n_base

print(len(t_base))

with open('base_dif.txt', 'w', encoding='utf') as base:
    base.writelines(t_base)