@ File: Project_5.s
@ Author: Will Humphrey
@ Purpose: This is a continuation of project 4 in a sense in order to get students familiar with the stack as well as assembly in general. 
@
@ Use these commands to assemble, link, run, and debug the program
@
@ as -o p4.o Project_4.s
@ gcc -o p4 p4.o
@ ./p4 ;echo $?
@ gdb --args ./helloworld
.equ READERROR,0

.global main
main:
    mov r4,#0           @ number of boards cut so far
    mov r5,#0           @ length of boards cut so far
    mov r6,#144         @ board 1
    mov r7,#144         @ board 2
    mov r8,#144         @ board 3
    ldr r0,=strWelcome  @ load welcome message
    bl  printf          @ print
    ldr r0,=strTitle    @ load title message
    bl  printf          @ print

print:

    ldr r0,=strTotals   @ load totals message
    mov r1,r4           @ move length of boards to r1
    mov r2,r5           @ move length cut so far to r2
    bl  printf          @ print
    ldr r0,=strBoards   @ load boards message
    mov r1,r6           @ move board 1 to r1
    mov r2,r7           @ move board 2 to r2    
    mov r3,r8           @ move board 3 to r3
    bl  printf          @ print
    b   board_check_one @ check the boards

prompt:

    ldr r0,=strInputPrompt @ input prompt
    bl  printf             @ print

    ldr r0,=numInputPattern @ prime for 1 integer input
    ldr r1,=intInput        @ load r1 with adress of where value is stored
    bl  scanf               @ scan the keyboard

    cmp r0,#READERROR       @ check for read error
    beq readerror           @ send for read error

    ldr r1,=intInput    @ reload r1
    ldr r1,[r1]         @ read the contents and store in r1 for printing
    
    cmp r1,#6       @ compare input with 6
    blt readerror   @ if less branch to read error
    cmp r1,#144     @ compare input with 144
    bgt readerror   @ if grater branch to read error
    
    b   board_one   @ branch to board 1

board_one:

    cmp r1,r6       @ compare input with board 1
    bgt board_two   @ if greater branch to barod 2

    add r4,r4,#1    @ add 1 to num of boards cut
    add r5,r5,r1    @ add input to total sum
    sub r6,r6,r1    @ subtract input from board 1
    b   print       @ branch to print

board_two:

    cmp r1,r7       @ compare input with board 2
    bgt board_three @ if greater branch to board 3

    add r4,r4,#1    @ add 1 to num of boards cut
    add r5,r5,r1    @ add input to total sum
    sub r7,r7,r1    @ subtract input from board 2
    b   print       @ branch to print

board_three:

    cmp r1,r8       @ compare input with board 3
    bgt try_again   @ if greater branch to try again

    add r4,r4,#1    @ add 1 to num of boards cut
    add r5,r5,r1    @ add input to total sum
    sub r8,r8,r1    @ subtract input from board 3
    b   print       @ print
    
try_again:

    ldr r0,=strTooBig   @ print too big message
    bl  printf          @ print
    b   prompt          @ branch to prompt

board_check_one:

    cmp r6,#6           @ compare r6 with 6 for length check
    blt board_check_two @ if less branch to second board check

    b   prompt          @ branch to prompt

board_check_two:

    cmp r7,#6               @ compare r7 with 6 for length check
    blt board_check_three   @ if less branch to last board check

    b   prompt              @ branch to prompt

board_check_three:

    cmp r8,#6       @ compare r8 with 6 for length check
    blt terminate   @ if less branch to terminate

    b   prompt      @ branch to prompt

terminate:

    ldr r0,=strTerminate    @ print termination message
    add r1,r6,r7            @ add r8 to r1
    add r1,r1,r8            @ add r8 to r1
    bl  printf              @ print
    b   myexit              @ exit the program

readerror:

    ldr r0,=strErrorWarning @ print error message
    bl  printf              @ print
    ldr r0,=strInputPattern @ load string pattern
    ldr r1,=strInputError   @ put address into r1 for read
    bl  scanf               @ scan the keyboard
    b   prompt              @ re-prompt

myexit:

    mov r7, #0x01   @ SVC call to exit
    svc 0           @ Make the system call

.data

.balign 4
strTitle: .asciz "Cut-It-Up Saw \n"

.balign 4
strWelcome: .asciz "Welcome to the Furniture Factory. \nThere are 3 144 inch boards you can cut from. \n"

.balign 4
strInputPrompt: .asciz "Enter the length of board to cut in inches (at least 6 and no more than 144): \n"

.balign 4
strTotals: .asciz "Boards cut so far: %d \nLiner length of boards cut so far: %d inches \n"

.balign 4
strBoards: .asciz "Current Board Lengths: \nOne:   %d inches \nTwo:   %d inches \nThree: %d inches \n"

.balign 4
strErrorWarning: .asciz "Invalid input detected. Please try again. \n"

.balign 4
strTooBig: .asciz "Not enough inventory to perform cut. Enter new smaller length. \n"

.balign 4
strTerminate: .asciz "\nCurrent inventory depleted. Program is shutting down. \nWaste is %d inches. \n"

@ format pattern for scanf call
@ integer format for read
.balign 4
numInputPattern: .asciz "%d"
@ used to clear the input buffer for invalid input
.balign 4
strInputPattern: .asciz "%[^\n]"
@ used to clear the input buffer for invalid input
.balign 4
strInputError: .skip 100*4
@ location used to store the user input
.balign 4
intInput: .word 0

@ let the assembler know these are the C library functions

.global printf
.global scanf
