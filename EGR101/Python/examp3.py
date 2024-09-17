# Will Humphrey
# EGR 101
# Dr. English
# Final Exam Question 3

num = int(input('Please input a number between 1 and 12: ')) # gathering input for the number that the user chooses

print('Chosen number is', num) # print statement for before the table is displayed
for i in range (13): # loop to print out the table
    print('%5g X %1g = %4.0f' % (i, num, (i*num))) # print statement for the table.

