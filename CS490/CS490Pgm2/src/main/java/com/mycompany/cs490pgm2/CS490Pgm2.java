/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.cs490pgm2;

/**
 *
 * @author bhump
 */
public class CS490Pgm2 {

    public static void main(String[] args) {
        int processCount = 20;
        int iterator = 0;

        // create heap
        Heap heap = new Heap(processCount);

        // create consumer thread one
        Consumer consumer1 = new Consumer(heap, iterator);
        Thread consumerThread1 = new Thread(consumer1);

        // create consumer thread two
        Consumer consumer2 = new Consumer(heap, iterator);
        Thread consumerThread2 = new Thread(consumer2);

        // create producer thread
        Producer producer = new Producer(heap, processCount, 500);
        Thread producerThread = new Thread(producer);

        // start threads
        producerThread.start(); // start the producer thread
        consumerThread1.start(); // start the first consumer thread
        consumerThread2.start(); // start the second consumer thread

        // join threads
        try {
            producerThread.join(); // wait for the producer thread to finish
            consumerThread1.join(); // wait for the first consumer thread to finish
            consumerThread2.join(); // wait for the second consumer thread to finish
        } catch (Exception e) {

        }

        // Print statements before exiting the program
        System.out.println("All processes have completed and queue is empty.");
        System.out.println("Exiting program...");

        System.exit(0); // exit the program
    }
}
