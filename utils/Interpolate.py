import pandas as pd
from utils.config import MY_CONFIG
from utils.NewtonForward import generate_table, create_csv
from ctypes import *


INTER = CDLL('./lib/libinterpol.so')


def get_forward_table(file_name):
	df = pd.read_csv(f'{MY_CONFIG.ROOT}/{file_name}')
	tab = generate_table(df['f(x)'])
	create_csv(df, tab, f'NF_{file_name}')
	val = df.iloc[0]
	args = []
	for key in val:
		args.append(key)
	return args


def newton_forward(args, h, x):
	c_args = (c_double * len(args))(*args)
	INTER.newton_forward.argtypes = [ARRAY(c_double, len(args)), c_int, c_double, c_double]
	INTER.newton_forward.restype = c_double
	return INTER.newton_forward(c_args, c_int(len(args)), c_double(h), c_double(x))
