#! /usr/bin/env python3

from typing import List, Dict, Set
import re

def lose_units(string: str) -> bool:
	return 'lose' in set(string.split(' '))

def gain_units(string: str) -> bool:
	return 'gain' in set(string.split(' '))

def get_happiness_units(string: str) -> str:
	regex: str = r'\d+'
	match = re.search(regex, string)
	return match.group() if match else None

def make_the_arrangement(string: str) -> str:
	return f"{string.split(' ')[0]}->{string.replace('.', '').split(' ')[-1]}"

def count_family(data: List[str]) -> int:
	count: int = 0
	isHere: Set[str] = set()
	for d in data:
		name: str = d.split(' ')[0]
		if name not in isHere:
			count += 1
			isHere.add(name)
		else:
			continue
	return count

def myFunc(name: str, data: List[str]) -> List[str]:
	result: List[str] = []
	for d in data:
		if name in d.split(' '):
			result.append(d.replace('.', '').split(' ')[-1])
		else:
			continue
	return result

def solve(arrang: List[str], data: List[str], myDict: Dict, res: int, fMembers: int, memo: List[int]) -> int:
	if len(arrang) == fMembers:
		memo.append(res + myDict[f'{arrang[0]}->{arrang[-1]}'] + myDict[f'{arrang[-1]}->{arrang[0]}'])
		return
	for nie in myFunc(arrang[-1], data):
		if nie not in arrang:
			solve(arrang + [nie], data, myDict, res + myDict[f'{arrang[-1]}->{nie}'] + myDict[f'{nie}->{arrang[-1]}'], fMembers, memo)
	return max(memo)

if __name__ == '__main__':
	file: str = 'input.txt'
	myDict: Dict[str, int] = {}
	with open(file, 'r') as f:
		data: List[str] = f.read().split('\n')
		for d in data:
			seat: str = make_the_arrangement(d)
			if lose_units(d):
				units: int = -1 * int(get_happiness_units(d))
			elif gain_units(d):
				units: int = int(get_happiness_units(d))
			myDict[seat] = units
		fMem: int = count_family(data) - 1
		memo: List[int] = []
		result: int = solve(['Alice'], data, myDict, 0, fMem, memo)
		print (result)

