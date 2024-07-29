#! /usr/bin/env python3 
import sys, os, time
import socket


def conct(host: str, port: int) -> None:
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
		s.connect((host, port))
		data = s.recv(1024)
		if data:
			data = data.decode('utf-8')
			print (data)
		return None

if __name__ == '__main__':
	host: str = 'challenge01.root-me.org'
	port: int = 52017
	conct(host, port)
