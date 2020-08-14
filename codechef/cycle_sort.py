def key(element):
    return element

def find_cycles(l):
    seen = set()
    cycles = []
    for i in range(len(l)):
        if i != key(l[i]) and not i in seen:
            cycle = []
            n = i
            while 1: 
                cycle.append(n)
                n = key(l[n])
                if n == i:
                    break
            seen = seen.union(set(cycle))
            cycles.append(list(reversed(cycle)))
    return cycles
print(find_cycles([4,3,2,1,0]))
