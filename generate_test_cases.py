from utils.CSVGenerator import write_csv
from utils.config import MY_CONFIG
import numpy as np
#from concurrent.futures import ThreadPoolExecutor


def x_generator(n = None):
	return MY_CONFIG.LOWER_BOUND + (MY_CONFIG.INTERVAL * n)

def y_generator(x):
	return np.sin(x)

@write_csv(x_generator, y_generator)
def write(file_name):
	return

'''
with ThreadPoolExecutor() as executer:
	file_name = 'testcase'
	for i in range(MY_CONFIG.NO_OF_FILES):
		executer.submit(write, f'testcase{i}.csv')
'''

if __name__ == '__main__':
	write('sample.csv')
