package com.mycompany.cs490pgm2;

public class Consumer implements Runnable {
    // private member variables
    private final Heap heap; // reference to the heap
    private int iterator;

    // constructor
    public Consumer(Heap heap, int iterator) {
        this.iterator = iterator; // set the iterator for the consumer thread
        this.heap = heap;
    }

    // method to consume a process from the heap
    @Override
    public void run() {
        int maxProcesses = heap.getMaxSize(); // get the maximum size of the heap

        // loop until all processes are consumed
        while (iterator < maxProcesses/2) {
            // check if the heap is empty
            if (heap.isEmpty()) {
                System.out.println("Heap is empty. Consumer thread is waiting...");
                try {
                    Thread.sleep(1000); // sleep for 1 second before checking again
                } catch (Exception e) {
                    
                }
            } else {
                // consume the process from the heap
                Process process = heap.removeMin(); // get the process at the root of the heap
                try {
                    Thread.sleep(process.getProcessTimeSlice()); // simulate the time slice for the process
                } catch (Exception e) {

                }

                // increment iterator
                iterator++;

                // print the process details
                System.out.println("Consumer thread consumed process with ID: " + process.getProcessID() + ", Priority: " + process.getProcessPriority() + ", Time Slice: " + process.getProcessTimeSlice());
            }
        }
    }   
}
