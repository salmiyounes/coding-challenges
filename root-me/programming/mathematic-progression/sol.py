from typing import List
import httpx 
from foo import calc
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
	url = f'{url}{result}'
	print (url)
	req = client.get(url)
	return req.text

if __name__ == '__main__':
	with httpx.Client() as client:
		url: str = 'http://challenge01.root-me.org/programmation/ch1/'
		data = make_req(url, client)
		expr: List[str] = []
		a, b, c, d, e = int(get_second_expr(data).split()[2]), 0 if get_first_expr(data).split()[1] == '+' else 1, int(get_first_expr(data).split()[5]), int(re.search(r'\d+', get_end_limit(data)[1]).group()), int(get_u0_number(data).split()[-1])
		res = int(calc(a, b, c, d, e))
		print (int(res))
		url: str = 'http://challenge01.root-me.org/programmation/ch1/ep1_v.php?result='
		print (send_res(res, url, client))

