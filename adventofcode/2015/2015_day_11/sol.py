#! /usr/bin/env python3
from typing import List
import string, re 

# You should respect the rules man
rule1 = lambda x: any(s in x for s in ["abc", "bcd", "cde", "def", "efg", "fgh", "pqr", "qrs", "rst", "stu", "tuv", "uvw", "vwx", "wxy", "xyz"])
rule2 = lambda x: any(s in x for s in {'i', 'o', 'l'})
rule3 = lambda x: sum(s*2 in x for s in set(x))

letters = string.ascii_lowercase




def count_letters(password: str) -> str:
	while True:
		if not rule2(''.join(password)) and rule1(''.join(password)) and rule3(''.join(password)) >= 2:
			return ''.join(password)
		if password[-1] == 'z' :
			password[-1] = 'a'
			flag = True
			index = len(password) - 2
			while index >= 0 and flag:
				if flag:
					if password[index] != 'z':
						password[index] = letters[ord(password[index]) - ord('a') +1]
						flag = False
					elif password[index] == 'z':
						password[index] = 'a'
				index -= 1
		else:
			password[-1] = letters[ord(password[-1]) - ord('a') + 1]
	return None
if __name__ == '__main__':
	res: List[str] = []
	newpass = count_letters(list('hxbxxzaa'))
	print (newpass)
