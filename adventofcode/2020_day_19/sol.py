from typing import List, Dict

FILE = open('input.txt', 'r')
COUNT: int = 0
result: Dict[str, List[str]] = {}
alpha_char: Dict[str, str] = {}
messages: List[str] = []
count = 0
unsolved: Dict[str, List[str]] = {}
res: List[str] = []
m = []
def make_change(data: str) -> None :
	key: str = data.split(':')[0]
	values: str = data.split(':')[1].split('|')
	#print (values)
	if len(values) == 1 :
		if 'a' in list(map(str, values[0])):
			result[key] = 'a'
		elif 'b' in list(map(str, values[0])):
			result[key] = 'b'
		else:
			result[key] = values[0].strip().split(' ')
	else:
		result[key] = [values[0].strip().split(' '), values[1].strip().split(' ')]
	return None

def decrypt_message(rule, insolved) :
	insolved[rule] = []

	for sublrul in result[rule]:


	pass


with FILE as f:
	nums: List[str] = []
	data: List[str] = []
	for line in f.readlines():
		if line.strip() and line.strip()[0].isdigit():
			make_change(line.strip())
		elif line.strip() == '':
			continue
		else:
			data.append(line.strip())

print (result)
#print (result, alpha_char, data, end='\n\n\n')
