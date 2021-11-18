/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 23.06.2020
 *
 * This class is a client in a TCP protocol
 */

import java.net.*;
import java.io.*;
import java.util.HashMap;

public class Client {

    public static void main(String [] args) {
        String serverName = "localhost";
        int port = 6066;
        try {
            /**
             * Print the server to connect to
             */
            System.out.println("Connecting to " + serverName + " on port " + port);
            Socket client = new Socket(serverName, port);
            /**
             * Print if you really got a connection
             */
            System.out.println("Just connected to " + client.getRemoteSocketAddress());
            OutputStream outToServer = client.getOutputStream();
            DataOutputStream out = new DataOutputStream(outToServer);

            /**
             * Send a packet and try to read the answer
             */
            int sentID = 1;
            out.writeInt(sentID);
            InputStream inFromServer = client.getInputStream();
            ObjectInputStream in = new ObjectInputStream(inFromServer);
            HashMap<Integer, String> getServer = (HashMap) in.readObject();

            System.out.println("Server says " + getServer.get(sentID));
            client.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        /**
         * Catch error if ID is not available in hashmap of Server
         */
        catch (ClassNotFoundException e) {
            System.out.println("ID not available");
            e.printStackTrace();
        }
    }
}