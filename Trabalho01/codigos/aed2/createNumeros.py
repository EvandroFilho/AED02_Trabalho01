import random

f = open("aleatorio.txt", "w")
for i in range(100000, 0, -1):
    f.write(str(random.randint(0, 100000)) + "\n")
f.close()