package main

// imports
import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// player type definition, holds player stats
type Player struct {
	firstname   string
	lastname    string
	appearances int
	atbats      int
	singles     int
	doubles     int
	triples     int
	homeruns    int
	walks       int
	hbp         int
	batavg      float64
	slugpct     float64
	obp         float64
}

// error player type definition, holds error player name, reason, and line number
type ErrorPlayer struct {
	firstname string
	lastname  string
	errreason string
	linenum   int
}

// main function
func main() {
	// pre-declared variables
	var (
		filename    string
		players     []Player
		errorInputs []ErrorPlayer
		keyboard    *bufio.Scanner
	)

	// keyboard to read the input file name
	keyboard = bufio.NewScanner(os.Stdin)

	// prompt the user for the input file name
	fmt.Println("Welcome to the player statistics calculator test program. \nI am giong to read players from an input data file. \nYou will tell me the name of your input file. \nI will store all of the players in a list, compute each player's averages, and then write the resulting team report to the screen.")
	fmt.Printf("\nEnter the name of your input file: ")

	// read the input file name
	keyboard.Scan()
	filename = keyboard.Text()

	// function call to obtain data from the file
	players, errorInputs = readData(filename)

	// function call to output the data to terminal
	outputData(players, errorInputs)
}

func readData(filename string) ([]Player, []ErrorPlayer) {
	/*
		Function that reads in the data using a buffered input scanner.

		Parameters:
			filename (string): The name of the file to read in.

		Return Values:
			players ([]Player): A slice of Player structs that contain the player data.
			errorInputs ([]ErrorPlayer): A slice of ErrorPlayer structs that contain the error data.

		This function iterates through the file line by line, and splits the line into words. From there it does checks to
		ensure that the line has the correct number of data points, and that they are valid. If they are, ir creates a player
		object and appends it to the players slice. If they are not, it creates an error object and appends it to the errorInputs slice.
	*/

	// pre-declared variables
	var (
		players     []Player      // slice to hold the player data
		errorInputs []ErrorPlayer // slice to hold the error inputs
		stats       [8]int        // array to hold the player stats
		errBool     bool          // boolean to know wether to ignore the line if there is an error
	)

	// file opening and error checking
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println("Error reading file:", err)
		return nil, nil
	}
	defer file.Close()

	// buffered input scanner
	scanner := bufio.NewScanner(file)
	itr := 1 // line counter
	for scanner.Scan() {
		line := scanner.Text()        // read the line
		words := strings.Fields(line) // split the line into words

		if len(words) > 10 { // check for too many data points
			errPlayer := ErrorPlayer{words[0], words[1], "Line contains too much data.", itr}
			errorInputs = append(errorInputs, errPlayer)
		} else if len(words) < 10 { // check for too little data points
			errPlayer := ErrorPlayer{words[0], words[1], "Line contains not enough data.", itr}
			errorInputs = append(errorInputs, errPlayer)
		} else {
			for i := 2; i < 10; i++ { // for loop to convert the string data to interger data
				stats[i-2], err = strconv.Atoi(words[i])
				if err != nil { // check for invalid data
					errPlayer := ErrorPlayer{words[0], words[1], "Line contains invalid data.", itr}
					errorInputs = append(errorInputs, errPlayer)
					errBool = true
					break
				} else if stats[i-2] < 0 { // check for negative data
					errPlayer := ErrorPlayer{words[0], words[1], "Line contains negative data.", itr}
					errorInputs = append(errorInputs, errPlayer)
					errBool = true
					break
				}
			}

			// if there is an error, skip the line
			if errBool {
				errBool = false
				continue

				// if there is no error, create a player object and append it to the players slice
			} else {
				// batavg, slugpct, obp are set to 0 initially, to allow for the calculation after creating the player due to the need of
				// the other stats and the fact that the calculations are methods of the player struct
				player := Player{words[0], words[1], stats[0], stats[1], stats[2], stats[3], stats[4], stats[5], stats[6], stats[7], 0, 0, 0}
				player.batavg = player.computeBatAvg()
				player.slugpct = player.computeSlugPct()
				player.obp = player.computeObp()
				players = append(players, player)
			}
		}
		itr++ // increment the line counter
	}
	// return the players and errorInputsS
	return players, errorInputs
}

func (player Player) computeBatAvg() float64 {
	batavg := float64(player.singles+player.doubles+player.triples+player.homeruns) / float64(player.atbats)
	return batavg
}

func (player Player) computeSlugPct() float64 {
	slugpct := float64((player.singles + (2 * player.doubles) + (3 * player.triples) + (4 * player.homeruns))) / float64(player.atbats)
	return slugpct
}

func (player Player) computeObp() float64 {
	obp := float64((player.singles + player.doubles + player.triples + player.homeruns + player.walks + player.hbp)) / float64(player.appearances)
	return obp
}

func outputData(players []Player, errorInputs []ErrorPlayer) {
	/*
		Function that prints the data to the terminal

		Parameters:
			players ([]Player): A slice of Player structs that contain the player data.
			errorInputs ([]ErrorPlayer): A slice of ErrorPlayer structs that contain the error data.

		This function sorts the players by slugpct, and then prints the player and error data to the terminal.
	*/

	// sort the players by slugpct
	sort.Slice(players, func(i, j int) bool {
		return players[i].slugpct > players[j].slugpct
	})

	// print the player header
	fmt.Printf("\nBASEBALL STATS REPORT --- %d PLAYERS FOUND IN FILE\n", len(players))
	fmt.Println("    PLAYER NAME      :    AVERAGE  SLUGGING   ONBASE%")
	fmt.Println("--------------------------------------------------------------")

	// print the player stats
	// print the player stats
	for i := 0; i < len(players); i++ {
		fmt.Printf("%10s, %8s : %8.3f %9.3f %9.3f\n", players[i].lastname, players[i].firstname, players[i].batavg, players[i].slugpct, players[i].obp)
	}

	// print the error header
	fmt.Println("\nERROR LINES FOUND IN INPUT DATA")
	fmt.Println("--------------------------------------------------------------")

	// print the error lines
	for i := 0; i < len(errorInputs); i++ {
		fmt.Printf("line  %d : %s, %s : %s\n", errorInputs[i].linenum, errorInputs[i].lastname, errorInputs[i].firstname, errorInputs[i].errreason)
	}
	fmt.Println("")
}
