#! /usr/bin/env python3 
from typing import List, Dict
import sys

#sys.setrecursionlimit(10**5)
'''
def look_and_say(num: str, curr: str, res: str, count: int, index: int) -> str:
    if index == len(num):
        return res + str(count) + curr
    if num[index] == curr:
        return look_and_say(num, curr, res, count+1, index+1)
    if num[index] != curr:
        return look_and_say(num, num[index], res + str(count) + curr, 1, index+1)
    return ""
'''

def look_and_say(num: str) -> str:
	result: str = ''
	index: int = 0
	curr: str = num[0]
	count: int = 0
	while index < len(num):
		if num[index] == curr:
			count += 1
			index += 1
		else:
			result += str(count) + curr
			curr = num[index]
			count = 1
			index += 1
	return result + str(count) + curr


if __name__ == '__main__':
    num: str = '3113322113'
    for _ in range(50):
   	 	num = look_and_say(num)
    print(len(num))
