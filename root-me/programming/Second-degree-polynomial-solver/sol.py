#!/usr/bin/env python3

from typing import List
import sys, socket, re
import numpy as np

Host: str = 'challenge01.root-me.org'
Port: int = 52018

def parse_data(data: str) -> List[str]:
    regex = r'(-?\d+\.?x²)\s*([+-]?\s*\d+\.?x¹)\s*([+-]?\s*\d+)\s*=\s*(-?\d+)'
    match = re.search(regex, data)
    return match.groups() if match else None

def clean(string: str) -> str:
    return string.strip().replace('.x²', '').replace('.x¹', '')

def solve_eq(expr: List[str]) -> str:
    expr = [clean(x) for x in expr]
    coeff = [eval(expr[0]), eval(expr[1]), eval(expr[2]) - eval(expr[3])]
    roots = np.roots(coeff)
    return roots

def connect(host: str, port: int):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        data = s.recv(1024).decode('utf-8')
        for _ in range(25):
            if data:
                parsed_data = parse_data(data)
                if parsed_data:
                    solve = solve_eq(parsed_data)
                    result = ''
                    if all(isinstance(num, np.complex128) for num in solve):
                        result = 'Not possible\n'
                    elif all(isinstance(num, np.float64) for num in solve):
                        result = f'x1: {round(solve[0], 3)} ; x2: {round(solve[1], 3)}\n'
                    else:
                        for num in solve:
                            if isinstance(num, np.float64):
                                result = f'x: {round(num, 3)}\n'
                    print(data, result)
                  
                    # send data 
                    s.sendall(result.encode())
                  
                    # recv data
                    data = s.recv(1024).decode('utf-8')
                    if data != '[!] Wrong answer!':
                        print(data)
                    else:
                        break
                else:
                    print("Failed to parse data:", data)
                    break
            else:
                break

if __name__ == '__main__':
    try:
        connect(Host, Port)
    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit()
