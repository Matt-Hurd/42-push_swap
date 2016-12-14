from random import shuffle
import os
import subprocess
import sys

t = 0
c = 0
m = -10000
mi = 10000000
while 1:
	l = range(100)
	c += 1
	shuffle(l)
	s = " ".join([str(x) for x in l])
	output = subprocess.check_output("./push_swap " + s + " | wc -l", shell=True)
	t += int(output)
	if int(output) > m:
		m = int(output)
	if int(output) < mi:
		mi = int(output)
	# print "avg: " + str(t / c) + " prev: " + str(int(output)) + " max: " + str(m) + " min: " + str(mi)
	sys.stdout.write("\ravg: " + str(t / c) + " prev: " + str(int(output)) + " max: " + str(m) + " min: " + str(mi))


# l = range(100)
# shuffle(l)
# print " ".join([str(x) for x in l])
# output = subprocess.check_output("./push_swap " + " ".join([str(x) for x in l]), shell=True)
# print output
# prev = ""
# pbc = 0
# for line in output.split("\n"):
# 	if line == 'pb':
# 		pbc += 1
# 	elif not line == 'pa':
# 		pbc = 0
# 	if line == 'pa' and pbc:
# 		print "bad"
# 		pbc -= 1
# 	prev = line
	# print line
