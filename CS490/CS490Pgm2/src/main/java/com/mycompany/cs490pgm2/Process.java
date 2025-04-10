/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cs490pgm2;

/**
 *
 * @author bhump
 */
public class Process{

    // Private member variables
    private final int processID;
    private int processPriority;
    private int processTimeSlice;
    
    // Constructor
    public Process(int ID, int priority, int timeSlice){
        processID = ID;
        processPriority = priority;
        processTimeSlice = timeSlice;
    }

    // Observers for the private member variables
    public int getProcessID(){
        return processID;
    }

    public int getProcessPriority(){
        return processPriority;
    }

    public int getProcessTimeSlice(){
        return processTimeSlice;
    }
}
