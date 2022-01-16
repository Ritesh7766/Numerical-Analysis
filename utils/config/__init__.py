# Author - Ritesh Saha

class Config:
	def __init__(self):
		self.NO_OF_FILES = 10
		self.NO_OF_COORDINATES = 100
		self.ROOT = './test_cases'
		self.FIELD_NAMES = ['x', 'f(x)']
		self.LOWER_BOUND = -100000.0
		self.UPPER_BOUND = 100000.0
		self.INTERVAL = 2000.0


MY_CONFIG = Config()