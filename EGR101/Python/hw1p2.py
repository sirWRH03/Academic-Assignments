## Will Humphrey
# EGR 101
# Dr. English
# HW1 Problem 2

import string

lcLetters = string.ascii_lowercase
ucLetters = string.ascii_uppercase
numbers = string.digits
punctuation = '$#@&*!'

usernames = ['jme2000', 'EEs_rock', 'TAsRcool']
passwords = []
userSatisfied = 0
passSatisfied = 0

while userSatisfied == 0:
    username = input('What is the username you would like to use? ')
    if username in usernames:
        print('That username is taken. Please enter another username')
    elif len(username) < 6:
        print('That username is not long enough. Please enter another username.')
    else:
        usernames.append(username)
        print('Thank you, we can move onto your password now.')
        userSatisfied = 1

while passSatisfied == 0:
    password = input('What is the password you would like to use?\nKeep in mind you must meet the following requirements:'+'\n At least 1 letter between [a-z] and 1 letter between [A-Z]'+'\n At least 1 number between [0-9]'+'\n At lealt 1 of the following characters [$ # @ & * !]'+'\n Minimum length 6 characters'+'\n Maximum length 16 characters\n')
    if (password.find(ucLetters) == True) and (password.find(lcLetters) == True) and (password.find(numbers) != -1) and (password.find(punctuation) != -1) and (len(password) < 16) and (len(password) > 6):
        passwords.append(password)
        print("Thank you. We'll keep your username and password in a safe place for whenever you need to log in.")
        passSatisfied = 1
    else:
        print('Please enter a valid password. Keep in mind the requirements.')
