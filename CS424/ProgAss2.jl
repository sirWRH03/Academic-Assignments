using Printf
using Statistics

println("Welcome to the player statistics calculator test program. \nI am giong to read players from an input data file. \nYou will tell me the name of your input file. \nI will store all of the players in a list, compute each player's averages, and then write the resulting team report to the screen.")
print("\nPlease enter the name of your input file: ")
filename = readline()


file = try open(filename, r)
catch error
    println("\nUnable to open the file: $filename")
    println("Due to error: $error")
    exit()
end

