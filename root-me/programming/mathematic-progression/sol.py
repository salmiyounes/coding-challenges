from typing import List
import httpx 
import re

def make_req(url: str, client) -> str:
	req = client.get(url)
	return req.text

def get_first_expr(data: str) -> str:
	regex: str = r'] (\D) (\D) [a-z] (\D) (\D)?(\d)+ .'
	match = re.search(regex, data)
	return match.group() if match else None

def get_second_expr(data: str) -> str:
	regex: str = r'= (\D) (\D)?(\d)+ (\D) '
	match = re.search(regex, data)
	return match.group() if match else None

def get_end_limit(data: str) -> List[str]:
	regex: str = r'<sub>\d+<\/sub>'
	match = re.findall(regex, data)
	return match if match else None
def get_u0_number(data: str) -> str:
	regex: str = r' \= \d+'
	match = re.search(regex, data)
	return match.group() if match else None

def solve(a: str, b: str, c: str, d: str) -> int:
	memo = [0] * (int(c) + 1)
	memo[0] = int(d)
	for n in range(0, int(c)):
		memo[n+1] = eval(a + f'{memo[n-1]}') + eval(b)
	return memo[-1]

def send_res(result, url, client) -> str:
	req = client.get(f'{url}{result}')
	return req.text

if __name__ == '__main__':
	with httpx.Client() as client:
		url: str = 'http://challenge01.root-me.org/programmation/ch1/'
		data = make_req(url, client)
		clean = lambda x: x.replace(']', '').replace('[', '').replace('=', '').replace(' ', '')
		a, b, c, d = clean(get_second_expr(data)), clean(get_first_expr(data)), get_end_limit(data)[-1].replace('>', ' ').replace('<', ' ').split()[1], get_u0_number(data).split()[-1]
		result: int = solve(a, b, c,d)
		url: str = 'http://challenge01.root-me.org/programmation/ch1/ep1_v.php?result='
		print (result)
		print (send_res(result, url, client))


