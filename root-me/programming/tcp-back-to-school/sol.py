from typing import List
import socket
import math, re, os

def parse(data: str) -> List[str]:
	regex: str = r'\d+'
	match: List[str] = re.findall(regex, data)
	return map(int, match) if match else None

def calc(num1: int, num2: int) -> int:
	return round(math.sqrt(num1) * num2, 2) 

def make_con(host: str, port: int) -> None:
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
		s.connect((host, port))
		data = s.recv(1024).decode('utf-8')
		print (data)
		if data:
			nums = list(parse(data))
			result = str(calc(nums[1], nums[2])) + '\n'
			s.sendall(result.encode())
			print (s.recv(1024).decode('utf-8'))
	return None

if __name__ == '__main__' :
	host: str = 'challenge01.root-me.org'
	port: int = 52002
	make_con(host, port)
