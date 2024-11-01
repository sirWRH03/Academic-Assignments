using Printf
using Statistics

function computeBatAvg(singles, doubles, triples, hrs, atBats)
    return (singles + doubles + triples + hrs)/atBats
end

function computeSlugPct(singles, doubles, triples, homeRuns, atBats)
    return (singles + (2*doubles) + (3*triples) + (4*homeRuns))/atBats
end

function computeObp(singles, doubles, triples, homeRuns, walks, hitbypitch, appearances)
    return (singles + doubles + triples + homeRuns + walks + hitbypitch)/appearances
end

println("Welcome to the player statistics calculator test program. \nI am giong to read players from an input data file. \nYou will tell me the name of your input file. \nI will store all of the players in a list, compute each player's averages, and then write the resulting team report to the screen.")
print("\nPlease enter the name of your input file: \n")
filename = readline()

file = try 
    open(filename, "r")
catch error
    println("\nUnable to open the file: $filename")
    println("Due to error: $error")
    println("Exiting the program\n")
    exit()
end

lines = readlines(file)
playerNum = length(lines)
players = Matrix{Any}(undef, playerNum, 5)

for line in (eachindex(lines))
    player = split(lines[line])

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

    global players[line, 1] = firstName
    global players[line, 2] = lastName
    global players[line, 3] = computeBatAvg(singles, doubles, triples, hrs, atBats)
    global players[line, 4] = computeSlugPct(singles, doubles, triples, hrs, atBats)
    global players[line, 5] = computeObp(singles, doubles, triples, hrs, walks, hbp, appearances)
end

close(file)

# Print player stats
println("\nBASEBALL STATS REPORT --- $playerNum PLAYER(S) FOUND IN FILE\n")
println("ORDERD BY SLUGGING PERCENTAGE\n")
println("    PLAYER NAME      :    AVERAGE  SLUGGING   ONBASE%\n")
println("--------------------------------------------------------------\n")

players = players[sortperm(players[:, 4], rev=true), :]
for player in 1:playerNum
    @printf("%10s, %8s : %8.3f %9.3f %9.3f\n", players[player, 2], players[player, 1], players[player, 3], players[player, 4], players[player, 5])
end

println("ORDERD BY LAST NAME\n")
println("    PLAYER NAME      :    AVERAGE  SLUGGING   ONBASE%\n")
println("--------------------------------------------------------------\n")

players = sortslices(players, dims = 1, by = players -> (players[2], players[1]))
for player in 1:playerNum
    @printf("%10s, %8s : %8.3f %9.3f %9.3f\n", players[player, 2], players[player, 1], players[player, 3], players[player, 4], players[player, 5])
end