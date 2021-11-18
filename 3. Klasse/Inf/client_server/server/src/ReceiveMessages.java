/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 16.06.2020
 *
 * This class is a server that gets a message from a client and replies to the client with a random quote from a txt file
 */
import javax.json.bind.Jsonb;
import javax.json.bind.JsonbBuilder;
import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.time.LocalDateTime;
import java.util.Random;
import java.util.Scanner;

public class ReceiveMessages {
	private static final int BUFSIZE = 508;

	public static void main(String[] args) throws IOException {
		int port = 50000;
		int lines = zitateCount("C:\\Users\\valentin.adlgasser\\Documents\\LBS4\\Inf\\client_server\\zitate.txt");
		System.out.println(lines);
		String test;

		try (DatagramSocket socket = new DatagramSocket(port)) {
			DatagramPacket packet = new DatagramPacket(new byte[BUFSIZE], BUFSIZE);

			while (true) {
				socket.receive(packet);
				String data = new String(packet.getData(), 0, packet.getLength());
				/**
				 * This is how you get the address of the client
				 */
				InetAddress clientAddress = packet.getAddress();
				/**
				 * This is how you get the port of the client
				 */
				int clientPort = packet.getPort();
				/**
				 * Same stuff as in the SendMessage class
				 */
				packet = new DatagramPacket(new byte[BUFSIZE], BUFSIZE, clientAddress, clientPort);
				String clientMessage = createMessage();
				System.out.println(clientMessage);
				byte[] clientData = clientMessage.getBytes();
				packet.setData(clientData);
				packet.setLength(clientData.length);
				socket.send(packet);
			}
		} catch (IOException e) {
			System.err.println(e);
		}
	}

	private static String createMessage() throws FileNotFoundException {
		Message msg = new Message("LBS4-User", LocalDateTime.now(), choose(new File("C:\\Users\\valentin.adlgasser\\Documents\\LBS4\\Inf\\client_server\\zitate.txt")));
		Jsonb jsonb = JsonbBuilder.create();
		return jsonb.toJson(msg);
	}

	/**
	 * This method counts the lines of a text file
	 * @param file
	 * @return Amount of lines in a file
	 * @throws IOException
	 */
	private static int zitateCount(String file) throws IOException {
		int lines = 0;
		try {
			BufferedReader reader = new BufferedReader(new FileReader(file));
			while (reader.readLine() != null) lines++;
			reader.close();
		}catch(IOException e){
			return 0;
		}
		return lines;
	}

	/**
	 * This method chooses a random line from the text file
	 * @param f
	 * @return A random line
	 * @throws FileNotFoundException
	 */
	private static String choose(File f) throws FileNotFoundException {
		String result = null;
		Random rand = new Random();
		int n = 0;
		for(Scanner sc = new Scanner(f); sc.hasNext();){
			++n;
			String line = sc.nextLine();
			if(rand.nextInt(n) == 0){
				result = line;
			}
		}
		return result;
	}
}
