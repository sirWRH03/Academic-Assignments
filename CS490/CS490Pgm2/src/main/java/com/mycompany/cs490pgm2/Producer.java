package com.mycompany.cs490pgm2;

public class Producer implements Runnable {
    // private member variables
    private final int sleepTime;
    private Heap heap; // reference to the heap
    private int processCount; // number of processes to be produced

    public Producer(Heap heap, int processCount, int sleepTime) {
        this.sleepTime = sleepTime; // set the sleep time for the producer thread
        this.heap = heap; // set the reference to the heap
        this.processCount = processCount; // set the number of processes to be produced
    }

    @Override
    public void run(){
        for (int i = 0; i < processCount; i++) {
            // sleep for the specified time
            try {
                Thread.sleep(sleepTime); // sleep for the specified time in milliseconds
            } catch (Exception e) {

            }

            // create a new process with random priority and time slice
            int processID = i; // process ID dependent on current iteration
            int processPriority = (int) (Math.random() * 10); // random priority between 0 and 9
            int processTimeSlice = (int) (Math.random() * 10000); // random time slice between 0 and 999
            
            Process process = new Process(processID, processPriority, processTimeSlice); // create a new process

            heap.insert(process); // insert the process into the heap
        }
    }
}
