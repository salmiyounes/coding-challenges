#! /usr/bin/env python3
from typing import List
import re 

def get_data(data: str) -> List[int]:
	regex: str = r'\-?\d'
	match = re.findall(regex, data)
	return map(int, match) if match else None

if __name__ == '__main__':
	data: List[str] = open("input.txt", "r").read().strip().split('\n')
	for d in data: print (list(get_data(d)))
