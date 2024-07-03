#! /usr/bin/env python3 
import sys, os, time
import socket


def conct(host: str, port: int) -> None:
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
		s.bind((host, port))
		s.listen(4)
		conn, addr = s.accept()
		with conn:
			print (f'Connected by {addr}')
			while True:
				data = conn.recv(1024)
				if not data : break
				print (data)
	return None

if __name__ == '__main__':
	host: str = '212.129.38.224'
	port: int = 52017
	conct(host, port)
