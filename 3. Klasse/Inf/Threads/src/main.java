/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 25.06.2020
 *
 * This program tests some thread functions
*/
public class main {
    public static void main(String[] args) {
        /**
         * This part works with the extended class
         */
        Lbs4Ableitung t1Extended = new Lbs4Ableitung("LBS", 1000);
        Lbs4Ableitung t2Extended = new Lbs4Ableitung("vier", 500);
        t1Extended.start();
        t2Extended.start();
        /**
         * This part works with the implemented class
         */
        Thread t1Implemented = new Thread(new Lbs4Implementierung("LBS", 1000));
        Thread t2Implemented = new Thread(new Lbs4Implementierung("vier", 600));
        t1Implemented.start();
        t2Implemented.start();
        /**
         * This part writes to a file with two different threads
         */
        ProtocolThread t1Protocol = new ProtocolThread("This is a message");
        ProtocolThread t2Protocol = new ProtocolThread("This is a message from another thread");
        t1Protocol.start();
        t2Protocol.start();

    }
}
