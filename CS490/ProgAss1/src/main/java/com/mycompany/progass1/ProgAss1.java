/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.progass1;


/**
 *
 * @author Will Humphrey
 */
public class ProgAss1 {
    public static int msgCounter = 0;
    
    public static void main(String[] args) {
        int msgCounter = 0;
        MessageWriter msgThread = new MessageWriter("One", 500); // create the thread
        MessageWriter msgThread2 = new MessageWriter("Two", 1000); // create the second thread
        Thread threadOne = new Thread(msgThread); // create a thread that can run the object msgThread
        Thread threadTwo = new Thread(msgThread2); // create a second thread that can run the object msgThread2
        threadOne.start();
        threadTwo.start();
        
        try {
            threadOne.join(); // wait for my thread to complete
            threadTwo.join(); // wait for my second thread to complete
        } catch (Exception e) {
            // TO DO handle system error here
        }
        
        
        System.out.println("\nmain program execution at end");
        System.exit(0);
    }
}
