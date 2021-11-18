/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 23.06.2020
 *
 * This class is a server in a TCP protocol
 */
import java.net.*;
import java.io.*;
import java.util.HashMap;

public class Server extends Thread {
    private ServerSocket serverSocket;
    private HashMap<Integer, String> getClient = new HashMap<>();

    public Server(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        serverSocket.setSoTimeout(10000);
    }

    public void run() {
        /**
         * Create a hashmap
         */
        getClient.put(1, "Number One");
        getClient.put(2, "Number Two");
        getClient.put(3, "Number Three");
        getClient.put(4, "Number Four");
        getClient.put(5, "Number Six");

        while(true) {
            try {
                /**
                 * Waiting for the client to connect
                 */
                System.out.println("Waiting for client on port " + serverSocket.getLocalPort() + "...");
                Socket server = serverSocket.accept();

                System.out.println("Just connected to " + server.getRemoteSocketAddress());
                DataInputStream in = new DataInputStream(server.getInputStream());

                /**
                 * Wait for the ID from the client and return the hashmap data if it is available
                 */
                int clientID = in.readInt();
                HashMap<Integer, String> sendClient = new HashMap<>();
                if(checkId(clientID)){
                    sendClient.put(clientID, getClient.get(clientID));
                }else{
                    sendClient.put(clientID, "ID is not available");
                }

                ObjectOutputStream out = new ObjectOutputStream(server.getOutputStream());
                out.writeObject(sendClient);
                server.close();

            } catch (SocketTimeoutException s) {
                System.out.println("Socket timed out!");
                break;
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
    }

    /**
     *
     * @param id
     * @return if the ID is available in the hashmap
     */
    private boolean checkId(int id){
        String testId = getClient.get(id);
        if(testId.isEmpty() || testId.isBlank()){
            return false;
        }else{
            return true;
        }
    }

    public static void main(String [] args) {
        int port = 6066;
        try {
            Thread t = new Server(port);
            t.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}