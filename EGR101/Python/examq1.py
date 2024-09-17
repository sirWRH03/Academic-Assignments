# Will Humphrey
# EGR101
# Dr. English
# Exam Question 1

import random # importing needed libraries

file = open('hot_100.txt', 'r') # opening hot_100 file

song_numbers = []
songs = []
nums_chosen = []
playlist_songs = [] # establishing needed variables
playlist_nums = list(range(1, 26))
music = {}
my_play_list = {}

for line in file: # for loop that separates the top 100 into two lists
    line = line.strip()
    parts = line.split('-')
    song_numbers.append(int(parts[0]))
    songs.append(parts[1])

music = dict(zip(song_numbers, songs)) # creating a dictionary of the top 100 songs

print(music) # print statement

while len(nums_chosen) < 25: # while loop that goes until 25 songs are chosen.
    random_num = random.randint(1, 100) # getting a random number 1-100
    if random_num not in nums_chosen: # if statement for if the number chosen hasn't already been chosen before
        nums_chosen.append(random_num) # appending chosen number to a list so it wont be used again.
        playlist_songs.append(music[random_num]) # appending the song to a list

my_play_list = dict(zip(playlist_nums, playlist_songs)) # creating a playlist for the dictionary

file.close() # closing the top_100.txt file

file = open('play_list.txt', 'w+') # creating a new file to write to

for i in range(1, 25): # for loop
    file.write('%s**%s\n' % (playlist_nums[i], my_play_list[i])) # writing the playlist to the file

file.close() # closing the play_list.txt file