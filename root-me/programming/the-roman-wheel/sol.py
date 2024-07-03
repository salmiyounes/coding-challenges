#! /usr/bin/env python3

import socket, re, string

def clean_string(data: str) -> str:
	regex = r".*'(\w+)'.*$"
	match = re.search(regex, data)
	return match.group(1) if match else None

def make_conn(host: str, port: int) -> None:
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
		s.connect((host, port))
		data = s.recv(1024)
		if data:
			data  = data.decode('utf-8')
			print (data)
			rot13_string = rot13_decoding(clean_string(data))
			print (f'[*] Sending : {rot13_string}')
			rot13_string = rot13_string + '\n'
			s.sendall(rot13_string.encode())
			data: str = s.recv(1024)
			if data: print (data.decode('utf-8'))
	return None

def rot13_decoding(data: str) -> str:
	res: str = ''
	for char in data:
		if char in string.ascii_lowercase: 
			res += string.ascii_lowercase[(ord(char) - ord('a') - 13) % 26]
		elif char in string.ascii_uppercase: 
			res += string.ascii_uppercase[(ord(char) - ord('A') - 13) % 26]
		else: 
			res += char
	return res

if __name__ == '__main__':
	host: str = 'challenge01.root-me.org'
	port: int = 52021
	make_conn(host, port)