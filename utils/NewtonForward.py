# Author: Ritesh Saha

from utils.config import MY_CONFIG


def forward_difference(y):
	vector = []
	for i in range(len(y)-1):
		vector.append(y[i + 1] - y[i])
	return vector


def generate_table(y):
	table = {}
	buff = forward_difference(y)
	table['d0'] = buff
	i = 1
	while len(buff) != 1:
	    buff = forward_difference(buff)
	    table[f'd{i}'] = buff
	    i += 1
	return table


def create_csv(data_frame, tab, file_name):
	for key in tab:
		data_frame.loc[range(len(tab[key])), key] = tab[key]
	data_frame.to_csv(f'{MY_CONFIG.ROOT}/{file_name}')