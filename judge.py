import sys
import time
import os

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

def readFileToList(fileName, list):
	f = file(fileName)
	while True:
		line = f.readline()
		if len(line) == 0:
			break
	f.close()

def compareLists():
	rlen = len(resultList)
	tlen = len(targetList)
	if rlen != tlen:
		print 'number of outputs invalid'
		sys.exit()
	for i in range(0, rlen):
		if resultList[i] != targetList[i]:
			print 'WA'
			sys.exit()
	print 'AC'

def judgeResult():
	readFileToList(prefix + RESULT_FILE, resultList)
	readFileToList(prefix + TARGET_FILE, targetList)
	compareLists()

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