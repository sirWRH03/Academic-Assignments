/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.progass1;

/**
 *
 * @author bhump
 */
public class MessageWriter implements Runnable {
    private final String myName; // used to distinguish threads
    private final int tDelay; // each thread will have its own delay
    
    public MessageWriter(String name, int delay) {
        // To do, any construction details that need to be performed before this code runs
        myName = name;
        tDelay = delay;
    }
    
    @Override
    public void run( ) {
        for(int i = 1; i <= 10; i++) {
            try {
                Thread.sleep(tDelay); // 1000 milliseconds is 1 second
            } catch (InterruptedException ex) {
                // TBD catch and deal with exception here
            }
            ProgAss1.msgCounter++;
            System.out.println(myName + " has woken up and this is message number " + ProgAss1.msgCounter);
        }
    }
}
 