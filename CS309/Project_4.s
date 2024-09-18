@ File: Project_4.s
@ Author: Will Humphrey
@ Purpose: The objective of this assignment is to get the students to learn the basics
@       of ARM Assembly. This includes: output, input, comparisons, basic arithmetic, and 
@       loop controls. Students need to properly document their code and demonstrate they 
@       know how to use the GNU debugger. 
@
@ Use these commands to assemble, link, run, and debug the program
@
@ as -o p4.o Project_4.s
@ gcc -o p4 p4.o
@ ./p4 ;echo $?
@ gdb --args ./helloworld

.equ READERROR, 0

.global main
main:

prompt:

    ldr r0, =strInputPrompt @Put the address of the input prompt into r0
    bl printf               @Call printf to display input prompt

get_input:

    ldr r0, =numInputPattern    @ load input pattern
    ldr r1, =intInput           @ load r1 with address of where input will be stored

    bl scanf                    @ scan the keyboard
    cmp r0, #READERROR          @ check for read error
    beq readerror               @ if there was go handle it

    ldr r1, =intInput           @ reload r1
    ldr r1, [r1]                @ read the contents of intInput and store in r1 for printing

    cmp r1,#100                 @ compare input with 100
    bgt readerror               @ if greater handle the error
    cmp r1,#1                   @ compare input with 1
    blt readerror               @ if less handle the error
    
    mov r4,r1                   @ copy r1 to r4 for logic

    ldr r0, =strInputConfirm    @ load the input confirmation
    bl  printf                  @ print

print_even:

    ldr r0, =strEvenOut @ load string for even prints
    mov r1,r4           @ copy r4 to r1 for printing
    bl  printf          @ print

    mov r5,#2           @ move 2 into r5
    mov r6,#2           @ move 2 into r6
    mov r1,r5           @ copy r5 into r1
    ldr r0,=strNumOut   @ print the number out
    bl  printf          @ print

on:

    cmp r4,r5           @ compare the input
    ble out             @ if r4 is less than move on from even
    mov r7,r5           @ move r5 to r7
    add r7,r7,#2        @ add 2 to r7
    cmp r4,r7           @ compare r4 and r7
    blt out             @ if less than move on from even
    add r5,r5,#2        @ add 2 to r5
    mov r1,r5           @ copy r5 into r1 for printing
    ldr r0,=strNumOut   @ print the number out
    bl  printf          @ print
    add r6,r6,r5        @ add r5 to r6
    b on                @ loop

out:

    mov r1,r6           @ copy r6 to r1
    ldr r0,=strEvenSum  @ print the sum out
    bl  printf          @ print

print_odd:

    ldr r0, =strOddOut  @ load string for odd prints
    mov r1,r4           @ copy r4 to r1 for printing
    bl  printf          @ print

    mov r5,#1           @ move 1 into r5
    mov r6,#1           @ move 1 into r6
    mov r1,r5           @ copy r5 into r1
    ldr r0,=strNumOut   @ print the number out
    bl  printf          @ print

go:

    cmp r4,r5           @ compare the input
    ble free            @ if r4 is less than move on from even
    mov r7,r5           @ move r5 to r7
    add r7,r7,#2        @ add 2 to r7
    cmp r4,r7           @ compare r4 and r7
    blt free            @ if less than move on from odd
    add r5,r5,#2        @ add 2 to r5
    mov r1,r5           @ copy r5 into r1 for printing
    ldr r0,=strNumOut   @ print the number out
    bl  printf          @ print
    add r6,r6,r5        @ add r5 to r6
    b go                @ loop

free:

    mov r1,r6           @ copy r6 to r1
    ldr r0,=strOddSum   @ print the sum out
    bl  printf          @ print
    b   myexit          @ exit the program

readerror:

    ldr r0, =strErrorMessage    @ load error message
    bl  printf                  @ print message
    b   myexit                  @ exit the program

myexit:

    mov r7, #0x01   @ SVC call to exit
    svc 0           @ make the system call

.data

@ Declare the strings and data needed

.balign 4
strInputPrompt: .asciz "Input an integer between 1 and 100: \n"

.balign 4
strInputConfirm: .asciz "You entered %d. \n"

.balign 4
strEvenOut: .asciz "The even numbers from 1 to %d are: \n"

.balign 4
strOddOut: .asciz "The odd numbers from 1 to %d are: \n"

.balign 4
strEvenSum: .asciz "The even sum is: %d \n"

.balign 4
strOddSum: .asciz "The odd sum is: %d \n"

.balign 4
strNumOut: .asciz "%d \n"

.balign 4
strErrorMessage: .asciz "Invalid input entered. Terminating Program... \n"

@ format pattern for scanf call

@ integer format for read
.balign 4
numInputPattern: .asciz "%d"
@ Location used to store the user input
.balign 4
intInput: .word 0

@ Tell assembler to know the C library functions:

.global printf
.global scanf
