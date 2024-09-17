# Will Humphrey
# EGR 101
# Dr. English
# Exam Question 2

special1 = []
special2 = [] # initializing needed arrays for sorting
special3 = []

# words list from word_listFE.py
words = ['artisan', 'potato', 'ability', 'construction', 'impression', 'trainer',
'baseball', 'passion', 'competition',
'attitude', 'moment', 'woman', 'agency', 'grocery',
'platform', 'lake', 'examination', 'airport', 'decision', 'sister', 'art',
'supermarket', 'situation',
'speech', 'energy', 'audience', 'flight', 'opportunity', 'speaker',
'university', 'owner', 'interaction', 'math', 'ambition', 'priority',
'committee', 'media', 'pizza',
'emphasis', 'operation', 'replacement', 'understanding',
'menu', 'comparison', 'development', 'performance', 'freedom',
'conversation', 'virus', 'hotel']

for word in words: # parses through words list
    if 'e' in word and len(word) >= 8: # checking to see if the word contains letter 'e' and is 8 characters or more
        special1.append(word) # appending word if condition is fulfilled
    elif 'i' in word and len(word) < 6: # checking to see if the word contains letter 'i' and is less than 6 characters
        special2.append(word) # appending word if condition is fulfilled
    else: # all other words
        special3.append(word) # appending word if conditions are not fulfilled.

print(special1)
print(special2) # print statements
print(special3)