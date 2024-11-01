using Printf
using Statistics
#Function declarations
function computeBatAvg(singles, doubles, triples, hrs, atBats)
    #=
        Function that calculates the batting average

        Parameters: 
            singles, doubles, triples, hrs, atBats

        Return Values:
            Calculated batting average
    =#
    return (singles + doubles + triples + hrs)/atBats
end

function computeSlugPct(singles, doubles, triples, homeRuns, atBats)
    #=
        Function that calculates the slugging percentage

        Parameters: 
            singles, doubles, triples, homeRuns, atBats

        Return Values:
            Calculated slugging percentage
    =#
    return (singles + (2*doubles) + (3*triples) + (4*homeRuns))/atBats
end

function computeObp(singles, doubles, triples, homeRuns, walks, hitbypitch, appearances)
    #=
        Function that calculates the on base percentage

        Parameters: 
            singles, doubles, triples, homeRuns, walks, hitbypitch, appearances

        Return Values:
            Calculated on base percentage
    =#
    return (singles + doubles + triples + homeRuns + walks + hitbypitch)/appearances
end

println("Welcome to the player statistics calculator test program. \nI am giong to read players from an input data file. \nYou will tell me the name of your input file. \nI will store all of the players in a list, compute each player's averages, and then write the resulting team report to the screen.")
print("\nPlease enter the name of your input file: \n")
filename = readline() # Get the filename from the user

# Try-Catch statement for opening file. If file cannot be opened, exit program.
file = try 
    open(filename, "r")
catch error
    println("\nUnable to open the file: $filename")
    println("Due to error: $error")
    println("Exiting the program\n")
    exit()
end

lines = readlines(file) # Read the lines of the file
playerNum = length(lines) # Get the number of players in the file
players = Matrix{Any}(undef, playerNum, 5) # Create a matrix to store player stats

# For loop to iterate through the lines of the file
for line in (eachindex(lines))
    player = split(lines[line]) # Split the line into an array of player stats

    # Assign player stats to variables
    firstName = player[1]
    lastName = player[2]
    appearances = parse(Float64, player[3])
    atBats = parse(Float64, player[4])
    singles = parse(Float64, player[5])
    doubles = parse(Float64, player[6])
    triples = parse(Float64, player[7])
    hrs = parse(Float64, player[8])
    walks = parse(Float64, player[9])
    hbp = parse(Float64, player[10])

    # Assign player stats to the players matrix, only includes the player's name and calculated stats
    global players[line, 1] = firstName
    global players[line, 2] = lastName
    global players[line, 3] = computeBatAvg(singles, doubles, triples, hrs, atBats)
    global players[line, 4] = computeSlugPct(singles, doubles, triples, hrs, atBats)
    global players[line, 5] = computeObp(singles, doubles, triples, hrs, walks, hbp, appearances)
end

close(file)

# Print player stats
println("\nBASEBALL STATS REPORT --- $playerNum PLAYER(S) FOUND IN FILE")
println("ORDERD BY SLUGGING PERCENTAGE\n")
println("    PLAYER NAME      :    AVERAGE  SLUGGING   ONBASE%")
println("--------------------------------------------------------------")

players = players[sortperm(players[:, 4], rev=true), :] # Sort players by slugging percentage
for player in 1:playerNum
    @printf("%10s, %8s : %8.3f %9.3f %9.3f\n", players[player, 2], players[player, 1], players[player, 3], players[player, 4], players[player, 5])
end

println("\nORDERD BY LAST NAME")
println("    PLAYER NAME      :    AVERAGE  SLUGGING   ONBASE%")
println("--------------------------------------------------------------")

players = sortslices(players, dims = 1, by = players -> (players[2], players[1])) # Sort players by last name
for player in 1:playerNum
    @printf("%10s, %8s : %8.3f %9.3f %9.3f\n", players[player, 2], players[player, 1], players[player, 3], players[player, 4], players[player, 5])
end