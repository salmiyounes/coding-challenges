from typing import List, Dict

Data: List[str] = open('input.txt', 'r').read().split('\n')

def clean_data(data: List[str]) -> Dict[str, str] :
	result: Dict[str, str] = {}
	for string in data:
		if 'AND' in string:
			result[string.split()[-1]] = ' '.join(string.split()[:-1]).replace('AND', '&').replace('->', '').strip()
		elif 'OR' in string:
			result[string.split()[-1]] = ' '.join(string.split()[:-1]).replace('OR', '|').replace('->', '').strip()
		elif  'NOT' in string:
			result[string.split()[-1]] = ' '.join(string.split()[:-1]).replace('NOT', '~').replace('->', '').strip()
		elif 'LSHIFT' in string:
			result[string.split()[-1]] = ' '.join(string.split()[:-1]).replace('LSHIFT', '<<').replace('->', '').strip()
		elif 'RSHIFT' in string:
			result[string.split()[-1]] = ' '.join(string.split()[:-1]).replace('RSHIFT', '>>').replace('->', '').strip()
		else:
			result[string.split(' ')[-1]] = ' '.join(string.split()[:-1]).replace('->', '').strip()
	return result

result = clean_data(Data)
q = dict()

def solve(wire: str):
	if wire.isdigit():
		return int(wire)
	if wire in q:
		return q[wire]
	elif '&' in result[wire]:
		a, b = result[wire].split("&")[0].strip(), result[wire].split("&")[1].strip()
		q[wire] = solve(a) & solve(b)
	elif '|' in result[wire]:
		a, b = result[wire].split("|")[0].strip() ,  result[wire].split("|")[1].strip()
		q[wire] = solve(a) | solve(b)
	elif '~' in result[wire]:
		a = result[wire].replace("~", "").strip()
		q[wire] = ~ solve(a)
	elif '>>' in result[wire]:
		a, b = result[wire].split(">>")[0].strip(), result[wire].split(">>")[1].strip()
		q[wire] = solve(a) >> solve(b)
	elif '<<' in result[wire]:
		a, b = result[wire].split("<<")[0].strip(), result[wire].split("<<")[1].strip()
		q[wire] = solve(a) << solve(b)
	else:
		a = solve(result[wire].strip())
		q[wire] = a
	return q[wire]

print (solve('a'))
