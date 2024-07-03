from typing import List
FILE: str = open('input.txt', 'r')
DATA: str = FILE.read().split()[0]
stack : List[str] = []
count = 0
for index, char in enumerate(DATA,start=1):
	if char == '(':
		stack.append(char)
	elif char == ')':
		if stack:
			stack.pop()
		else:
			count -= 1
	if (len(stack) + count) == -1 : print (index)

