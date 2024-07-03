#! /usr/bin/env python3

import random
import httpx
import base64
import subprocess
import re
import string
import time
import os

regex = r'data:image/png;base64,(.*)" /><br><br>'

def decod_data(data: str) -> bytes:
    return base64.b64decode(data)

def print_result(session: httpx.Client, url: str) -> (str, str):
    req = session.get(url)
    bs64data = re.search(regex, req.text).group(1)
    fname = ''.join(random.choice(string.ascii_lowercase) for _ in range(5))
    with open(f'{fname}.png', 'wb') as f:
        f.write(decod_data(bs64data))
    result = subprocess.Popen(['gocr', '-i', f'{fname}.png'], stdout=subprocess.PIPE).communicate()[0]
    return result.decode('utf-8').strip(), f'{fname}.png'

def post_data(session: httpx.Client, url: str, data: str) -> str:
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.6422.112 Safari/537.36',
        'Accept-Language': 'en-US,en;q=0.9',
        'Connection': 'keep-alive',
    }
    req = session.post(url, data={'cametu': data}, headers=headers)
    return req.text

if __name__ == '__main__':
    url = 'http://challenge01.root-me.org/programmation/ch8/'
    print(f'Making request to {url} ..........')
    
    with httpx.Client() as session:
        while True:
            data, fname = print_result(session, url)
            start = time.monotonic()
            print(f'Captcha solved in {time.monotonic() - start:.4} seconds. Data: {data}')
            result = post_data(session, url, data)
            if 'Failed' not in result:
                print(f'{re.findall("the flag ?+", result)}')
                break
            os.remove(f'{fname}')
