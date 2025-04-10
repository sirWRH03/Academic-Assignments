package com.mycompany.cs490pgm2;

public class Heap {
    // private member variables
    private Process[] heap; // Array to store the heap elements
    private int size; // Current size of the heap
    private int maxSize; // Maximum size of the heap - will be equal to the set number of processes

    // constructor
    public Heap(int maxSize) {
        this.maxSize = maxSize;
        this.size = 0;
        this.heap = new Process[maxSize];
    }

    // check for empty heap
    public boolean isEmpty() {
        return size == 0;
    }

    // observer for the parent node of a given node
    public int parent(int i) {
        return (i - 1) / 2;
    }

    // observer for the left child of a given node
    public int leftChild(int i) {
        return 2 * i + 1;
    }

    // observer for the right child of a given node
    public int rightChild(int i) {
        return 2 * i + 2;
    }

    // swap two nodes in the heap
    public void swap(int i, int j) {
        Process temp = heap[i]; // temp variable to store the value of heap[i]

        // swap the values of heap[i] and heap[j]
        heap[i] = heap[j]; 
        heap[j] = temp;
    }

    // heapify down the heap to maintain the min-heap property
    public void heapifyDown(int i) {
        int leftChild = leftChild(i); // get the left child of the current node
        int rightChild = rightChild(i); // get the right child of the current node
        int smallest = i; // assume the current node is the smallest

        // check if the left child is smaller than the current node
        if (leftChild < size && heap[leftChild].getProcessPriority() < heap[smallest].getProcessPriority()) {
            smallest = leftChild;
        }

        // check if the right child is smaller than the current node
        if (rightChild < size && heap[rightChild].getProcessPriority() < heap[smallest].getProcessPriority()) {
            smallest = rightChild;
        }

        // if the root is not the smallest, swap it with the smallest child and continue heapifying down
        if (smallest != i) {
            swap(i, smallest);
            heapifyDown(smallest);
        }
    }

    // heapify up the heap to maintain the min-heap property
    public void heapifyUp(int i) {
        // check if the current node is not the root and if it is smaller than its parent
        // if so, swap it with its parent and continue heapifying up
        while (i != 0 && heap[parent(i)].getProcessPriority() > heap[i].getProcessPriority()) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    // insert a new process into the heap
    // this method is synchronized to ensure threads can work simultaneously
    public synchronized void insert(Process process) {
        // check if the heap is full
        // if so, print an error message and return
        if (size == maxSize) {
            System.out.println("Heap is full. Cannot insert process.");
            return;
        }

        heap[size] = process; // insert the process at the end of the heap
        size++; // increment the size of the heap
        heapifyUp(size - 1); // heapify up the new process to maintain the min-heap property
    }

    // remove the process with the minimum priority from the heap
    // this method is synchronized to ensure threads can work simultaneously
    public synchronized Process removeMin() {
        // check if the heap is empty
        // if so, print an error message and return null
        if (isEmpty()) {
            System.out.println("Heap is empty. Cannot remove process.");
            return null;
        }

        Process minProcess = heap[0]; // store the minimum process (the root of the heap) in a temporary variable
        heap[0] = heap[size - 1]; // replace the root with the last process in the heap
        size--; // decrement the size of the heap
        heapifyDown(0); // heapify down the new root to maintain the min-heap property
        return minProcess; // return the minimum process
    }
}
