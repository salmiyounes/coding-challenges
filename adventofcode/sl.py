FILE = open('input.txt', 'r')
DATA = FILE.read().split('\n')

class Num(object):
	def __init__(self, data):
		self.data = data
	def __repr__(self):
		return f'{self.data}'
	def __pow__(self, other):
		return Num(self.data + other.data)
	def __add__(self, other):
		return Num(self.data + other.data)
	def __mul__(self, other):
		return Num(self.data * other.data)


def my_eval(x):
	s = ""
	flag = False

	for m in x :
		if m in '0123456789' and not flag :
			s += 'Num('
			flag = True
		if flag and m not in '0123456789':
			s += ')'
			flag = False
		s += m
	if flag:
		s += ')'
	print(s)
	return eval(s)
res = Num(0)
for d in DATA:
	res = my_eval(d.replace('+', '**')) + res
print (res)
