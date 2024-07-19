from cython.cimports.libc.string import memset
from libc.stdlib cimport malloc, free
from libc.stdio cimport printf
from libcpp cimport bool

def calc(double a, int b, double c, int d, double e) :
	cdef double z = e
	for i in range(d): 
		if b == 0:
			z = a + z + i * c 
		else :
			z = a + z - i * c
	return z
