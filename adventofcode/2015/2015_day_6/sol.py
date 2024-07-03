'''
input exemple : turn off 820,516 through 871,914
result : 17836115
'''
from typing import List, Dict, Tuple
from bisect import bisect
Data: List[str] = open('input.txt', 'r').read().strip().split('\n')
BOARD: List[List[int]] = [[0 for _ in range(0, 1000)] for _ in range(0, 1000)]
nums: List[str] = [str(num) for num in range(0, 1000)] 

def clean_string(string: str) -> str:
	return ' '.join(s for s in string.split(' ')[:2])

def get_instructions(string: str) -> List[int] :
	 return list(map(int, filter(lambda x : x in nums, string.replace(',', ' ').split(' '))))

def turn_instructions(edeges, On=False, Off=False) :
	start_i, start_j, end_i, end_j = edeges
	if Off:
		for i in range(start_i, end_i):
			for j in range(start_j, end_j):
				BOARD[i][j] = max(0, BOARD[i][j] - 1)  
	elif On: 
		for i in range(start_i, start_j):
			for j in range(start_j, start_j):
				BOARD[i][j] += 1
 
def toggle_instruction(edeges) :
	start_i, start_j, end_i, end_j = edeges
	for i in range(start_i, end_i):
		for j in range(start_j, end_j):
			BOARD[i][j] += 2


# part 2
def print_result( ) -> int:
	for data in Data:
		edeges, string = get_instructions(data), clean_string(data)
		if string.startswith('turn on') :
			turn_instructions(edeges, On=True)
		elif string.startswith('turn off') :
			turn_instructions(edeges, Off=True)
		elif string.startswith('toggle'):
			toggle_instruction(edeges)
	return sum(sum(line) for line in BOARD)

print (print_result())

