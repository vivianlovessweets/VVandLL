import sys
import time
import os
import md5

# result list to be judged
resultList = []
# target list to be compared with
targetList = []

# result file name
RESULT_FILE = "outputs.out"
# target file name
TARGET_FILE = "output.txt"

# current dir
prefix = os.path.abspath(os.curdir) + '\\'

def compareFile(fa, fb):
	filea = open(fa, 'r')
	fileb = open(fb, 'r')
	
	keya = md5.new(filea.read()).hexdigest()
	keyb = md5.new(fileb.read()).hexdigest()
	
	if keya == keyb:
		print "AC"
	else:
		print "WA"

def judgeResult():
	compareFile(prefix + RESULT_FILE, prefix + TARGET_FILE)

def main():
	if len(sys.argv) < 2:
		print 'number of args invalid'
		sys.exit()
		
	start = time.clock()
	
	os.system(prefix + sys.argv[1])
	
	elapsed = (time.clock() - start)
	print("Time used:",elapsed)
	
	judgeResult()
	

if __name__ == '__main__':
  main()