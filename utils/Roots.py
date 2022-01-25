from ctypes import *
import csv


ROOTS = CDLL('./lib/libroots.so')
C_FUNC = CFUNCTYPE(c_double, c_double)

ROOTS.bisection.argtypes = [c_double, c_double, C_FUNC, c_double]
ROOTS.bisection.restype = c_double

ROOTS.newton_rhapson.argtypes = [c_double, C_FUNC, C_FUNC, c_double]
ROOTS.newton_rhapson.restype = c_double

ROOTS.regula_falsi.argtypes = [c_double, c_double, C_FUNC, c_double]
ROOTS.regula_falsi.restype = c_double

ROOTS.secant.argtypes = [c_double, c_double, C_FUNC, c_double]
ROOTS.secant.restype = c_double

ROOTS.csv_bisection.argtypes = [POINTER(c_double), POINTER(c_double), C_FUNC, c_double, POINTER(c_double), POINTER(c_double)]
ROOTS.csv_bisection.restype = c_bool

ROOTS.csv_newton_rhapson.argtypes = [POINTER(c_double), C_FUNC, C_FUNC, c_double, POINTER(c_double)]
ROOTS.csv_newton_rhapson.restype = c_bool

ROOTS.csv_regula_falsi.argtypes = [POINTER(c_double), POINTER(c_double), C_FUNC, c_double, POINTER(c_double), POINTER(c_double)]
ROOTS.csv_regula_falsi.restype = c_bool

ROOTS.csv_secant.argtypes = [POINTER(c_double), POINTER(c_double), C_FUNC, c_double, POINTER(c_double), POINTER(c_double)]
ROOTS.csv_secant.restype = c_bool

def bisection(x0, x1, func, epsilon):
	return ROOTS.bisection(c_double(x0), c_double(x1), C_FUNC(func), c_double(epsilon))


def newton_rhapson(x0, func, derivative, epsilon):
	return ROOTS.newton_rhapson(c_double(x0), C_FUNC(func), C_FUNC(derivative), c_double(epsilon))


def regula_falsi(x0, x1, func, epsilon):
	return ROOTS.regula_falsi(c_double(x0), c_double(x1), C_FUNC(func), c_double(epsilon))


def secant(x0, x1, func, epsilon):
	return ROOTS.secant(c_double(x0), c_double(x1), C_FUNC(func), c_double(epsilon))


def csv_bisection(x0, x1, func, epsilon, file_name, new_approximation=0.0, prev_approximation=0.0):
	x0 = pointer(c_double(x0))
	x1 = pointer(c_double(x1))
	new_approximation = pointer(c_double(new_approximation))
	prev_approximation = pointer(c_double(prev_approximation))
	func = C_FUNC(func)
	epsilon = c_double(epsilon)
	with open(f'./test_cases/{file_name}', 'w', newline='') as csv_file:
		fieldnames = ['start_interval', 'end_interval', 'new_approximation', 'prev_approximation']
		writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
		writer.writeheader()
		while not ROOTS.csv_bisection(x0, x1, func, epsilon, new_approximation, prev_approximation):
			writer.writerow({'start_interval': x0.contents.value, 'end_interval': x1.contents.value, 'new_approximation': new_approximation.contents.value, 'prev_approximation': prev_approximation.contents.value})
		writer.writerow({'start_interval': x0.contents.value, 'end_interval': x1.contents.value, 'new_approximation': new_approximation.contents.value, 'prev_approximation': prev_approximation.contents.value})



def csv_newton_rhapson(x0, func, d_func, epsilon, file_name, approximation=0.0):
	x0 = pointer(c_double(x0))
	func = C_FUNC(func)
	d_func = C_FUNC(d_func)
	approximation = pointer(c_double(approximation))
	epsilon = c_double(epsilon)
	with open(f'./test_cases/{file_name}', 'w', newline='') as csv_file:
		fieldnames = ['new_approximation', 'prev_approximation']
		writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
		writer.writeheader()
		while not ROOTS.csv_newton_rhapson(x0, func, d_func, epsilon, approximation):
			writer.writerow({'new_approximation': x0.contents.value, 'prev_approximation': approximation.contents.value})
		writer.writerow({'new_approximation': x0.contents.value, 'prev_approximation': approximation.contents.value})	


def csv_regula_falsi(x0, x1, func, epsilon, file_name, new_approximation=0.0, prev_approximation=0.0):
	x0 = pointer(c_double(x0))
	x1 = pointer(c_double(x1))
	new_approximation = pointer(c_double(new_approximation))
	prev_approximation = pointer(c_double(prev_approximation))
	func = C_FUNC(func)
	epsilon = c_double(epsilon)
	with open(f'./test_cases/{file_name}', 'w', newline='') as csv_file:
		fieldnames = ['start_interval', 'end_interval', 'new_approximation', 'prev_approximation']
		writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
		writer.writeheader()
		while not ROOTS.csv_regula_falsi(x0, x1, func, epsilon, new_approximation, prev_approximation):
			writer.writerow({'start_interval': x0.contents.value, 'end_interval': x1.contents.value, 'new_approximation': new_approximation.contents.value, 'prev_approximation': prev_approximation.contents.value})
		writer.writerow({'start_interval': x0.contents.value, 'end_interval': x1.contents.value, 'new_approximation': new_approximation.contents.value, 'prev_approximation': prev_approximation.contents.value})	


def csv_secant(x0, x1, func, epsilon, file_name, new_approximation=0.0, prev_approximation=0.0):
	x0 = pointer(c_double(x0))
	x1 = pointer(c_double(x1))
	new_approximation = pointer(c_double(new_approximation))
	prev_approximation = pointer(c_double(prev_approximation))
	func = C_FUNC(func)
	epsilon = c_double(epsilon)
	with open(f'./test_cases/{file_name}', 'w', newline='') as csv_file:
		fieldnames = ['start_interval', 'end_interval', 'new_approximation', 'prev_approximation']
		writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
		writer.writeheader()
		while not ROOTS.csv_regula_falsi(x0, x1, func, epsilon, new_approximation, prev_approximation):
			writer.writerow({'start_interval': x0.contents.value, 'end_interval': x1.contents.value, 'new_approximation': new_approximation.contents.value, 'prev_approximation': prev_approximation.contents.value})
		writer.writerow({'start_interval': x0.contents.value, 'end_interval': x1.contents.value, 'new_approximation': new_approximation.contents.value, 'prev_approximation': prev_approximation.contents.value})	
