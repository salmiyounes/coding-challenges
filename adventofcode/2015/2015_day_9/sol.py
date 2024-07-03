from typing import List
import time

data = open('input.txt', 'r').read().split('\n')

def clean_data() :
	res, m = {}, {}
	for string in data:
		try :
			pos1, pos2, dist = string.split(" ")[0].strip(), string.split(" ")[2].strip(), string.split(" ")[-1].strip()
			if pos1 in res:
				res[pos1].append(pos2)
			else:
				res[pos1] = [pos2]
			if pos2 in res:
				res[pos2].append(pos1)
			else :
				res[pos2] = [pos1]
			m[(pos1, pos2)] = int(dist)
			m[(pos2, pos1)] = int(dist)
		except IndexError as e:
			pass
	return res, m

def solve(start, num, count, result, data, res, string) :
	if count == len(res):
		result.append(num)
		return 
	for pos in 	res[start]:
		if pos not in string:
			solve(pos , num + data[(start, pos)], count + 1, result, data, res, string + [pos])
	return



res, data = clean_data()
result = []

for start in res.keys():
	solve(start, 0, 1, result, data, res, [start])


print (min(result), max(result))

