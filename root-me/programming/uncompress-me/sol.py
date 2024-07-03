#! /usr/bin/env python3

import sys, socket, re, zlib, base64



def clean_string(data: str) -> str:
	regex: str = r"[\w\s]+"
	match = re.findall(regex, data)
	return match if match else None
def dcomp(data: str) -> str:
	data = data.encode()
	return zlib.decompress(base64.b64decode(data)) + '\n'.encode()
def make_conn(host: str, port: int) -> None:
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
		s.connect((host, port))
		data: str = s.recv(1024).decode('utf-8')
		if data:	
			print (data)
			string: str = clean_string(data)
			print (string)
			'''string: str = dcomp(string)
			s.sendall(string)
			data: str = s.recv(1024).decode('utf-8')
			print (data)'''

if __name__ == '__main__':
 	host: str = 'challenge01.root-me.org'
 	port: int = 52022
 	make_conn(host, port)
