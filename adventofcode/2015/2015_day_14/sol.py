#! /usr/bin/env python3

from typing import List
import re

TOTAL: int = 2503

def parse_data(data: str) -> List[str] :
	regex: str = r'\d+'
	match = re.findall(regex, data)
	return match if match else None

def myFunc(name: str, fly_dist: int, stamina: int, rest: int) -> int:
	cycle_time: int = (stamina + rest)
	full_cycles: int = TOTAL // cycle_time
	remaining_time: int = TOTAL % cycle_time
	fly_time: int = full_cycles * stamina + min(remaining_time, stamina)
	distance: int = fly_time * fly_dist
	print (f'{name}: {distance}.', end='\n')
	return distance

if __name__ == '__main__':
	with open('input.txt', 'r') as f:
		data: List[str] = f.read().strip().split('\n')
		result: int = float('-inf')
		for d in data:
			fly_dist, stamina, rest = map(int, parse_data(d))
			name: str = d.split(' ')[0]
			result = max(result, myFunc(name, fly_dist, stamina, rest))
		print (f'Part 1 : {result}')
