# Author - Ritesh Saha

import csv
from utils.config import MY_CONFIG


# Custom decorator for returning a function which creates csv files.
def write_csv(x_generator, y_generator):
	def decorate(writer):
		def write(file_name):
			with open(f'{MY_CONFIG.ROOT}/{file_name}', 'w', newline='') as csv_file:
				writer = csv.DictWriter(csv_file, fieldnames=MY_CONFIG.FIELD_NAMES)
				writer.writeheader()
				buffer = {}
				for i in range(MY_CONFIG.NO_OF_COORDINATES):
					buffer[MY_CONFIG.FIELD_NAMES[0]] = x_generator(n=i)
					buffer[MY_CONFIG.FIELD_NAMES[1]] = y_generator(buffer[MY_CONFIG.FIELD_NAMES[0]]) 
					writer.writerow(buffer)
		return write
	return decorate