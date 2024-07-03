
from typing import List, Tuple, Dict




robot_santa: str = ''
real_santa: str =  ''

for index, derection in enumerate(open('input.txt', 'r').read().strip(), start=1):
	if index & 1:
		real_santa += derection
	else:
		robot_santa += derection


point: Tuple[int, int] = (0, 0)
visited_1: Dict[Tuple[int, int], int] = {point: 1}

# part 2

def make_visit(data: str, visited: Dict[Tuple[int, int], int], state: Tuple[int, int]) -> int:
	for derection in data:
		if derection == '^':
			x, y = state
			y += 1
		elif derection == 'v':
			x, y = state
			y -= 1
		elif derection == '>':
			x, y = state
			x += 1
		elif derection == '<':
			x, y = state
			x -= 1
		state = (x, y)
		if state in visited:
			visited[state] += 1
		else:
			visited[state] = 1
	return len([num for _, num in visited.items() if num >= 1])

print (make_visit(robot_santa, visited_1, (0, 0)))
print(make_visit(real_santa, visited_1, (0, 0)))
