# Program to write 10^6 random letters (only A, B, C, D) to a file

import random

# Open file for writing
f = open("222.txt", "w")

# Write 10^6 random letters to file
for i in range(500000):
    f.write(random.choice("ABCD"))

# Close file
f.close()