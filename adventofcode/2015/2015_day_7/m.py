known = dict()

def solvecircuit(circuit, val):
    if val.isdigit():
        return int(val)

    if val in known:
        return known[val]
    print (known)
    operator = circuit[val]
    if len(operator) == 1:
        known[val] = solvecircuit(circuit, operator[0])
    elif 'NOT' in operator:
        known[val] = ~ solvecircuit(circuit, operator[1]) % 65536
    elif 'AND' in operator:
        known[val] = solvecircuit(circuit, operator[0]) & solvecircuit(circuit, operator[2]) % 65536
    elif 'OR' in operator:
        known[val] = solvecircuit(circuit, operator[0]) | solvecircuit(circuit, operator[2]) % 65536
    elif 'LSHIFT' in operator:
        known[val] = solvecircuit(circuit, operator[0]) << solvecircuit(circuit, operator[2]) % 65536
    elif 'RSHIFT' in operator:
        known[val] = solvecircuit(circuit, operator[0]) >> solvecircuit(circuit, operator[2]) % 65536
    else:
        print ('unknown operator: ')
        print (operator)
        return
    return known[val]

circuit = dict()

with open('input.txt', 'r') as f:
    for line in f:
        operation = line.strip().split()
        circuit[operation[-1]] = operation[0:len(operation)-2]
    print(solvecircuit(circuit, 'a'))
