from typing import List
data: List[str] = open('input.txt', 'r').read().strip().split('\n')
result: int = 0
paper: int = 0
slack: int = 0

for d in data:
	l, w, h = map(int, d.split('x'))
	slack += min(l*w, h*l, w*h)
	paper += 2 * (l*w + w*h + h*l) 

print (f'Part 1: {paper+slack}')

