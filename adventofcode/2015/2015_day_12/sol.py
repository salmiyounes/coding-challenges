#! /usr/bin/env python3 
from typing import List, Dict
import json
from pprint import pprint


def solve(data, acom: List[int]) :
	if isinstance(data, int):
		acom.append(data)
		return 
	elif isinstance(data, list):
		for d in data:
			solve(d, acom)
	elif isinstance(data, dict) and not 'red' in data.values():
		for d in data.keys():
			solve(data[d], acom)
	else:
		return None
	return sum(acom)


if __name__ == '__main__':
	nums: List[str] = []
	with open('input.txt', 'r') as f:
		data = json.load(f)
	acom: List[int] = []
	result: int = solve(data, acom)
	print (result, end='\n')
