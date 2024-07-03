#! /usr/bin/env python3

import random
import httpx
import base64
import subprocess
import re
import string
import time
import os

def get_img_string(text: str) -> str:
	regex = r'data:image/png;base64,(.*) /><br/><br/>'
	match = re.search(regex, text)
	return match.group(1) if match else None

def connect(url: str) -> str:
	req = httpx.get(url)
	return req.text
def bs64_to_img(data: str) -> None:
	fname = f'{"".join(random.choice(string.ascii_letters) for _ in range(5))}.png'
	with open(fname, 'wb') as f: f.write(base64.b64decode(data)); f.close()
	return None 



if __name__ == '__main__':
	url: str = 'http://challenge01.root-me.org/programmation/ch7/'
	text: str = connect(url)
	data: str = get_img_string(text)
	bs64_to_img(data)
