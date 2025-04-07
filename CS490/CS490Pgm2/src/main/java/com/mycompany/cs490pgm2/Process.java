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
    private final int processID;
    private int processPriority;
    private int processTimeSlice;
    
    public Process(int ID, int priority, int timeSlice){
        processID = ID;
        processPriority = priority;
        processTimeSlice = timeSlice;
    }
    
    public void priorityChange(int prio){
        processPriority = prio;
    }
    
    public void timeChange(int time){
        processTimeSlice = time;
    }
}
