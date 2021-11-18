/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 16.06.2020
 *
 * This class is a client, it send a message to the server and gets a random quote returned.
 * It outputs the quote afterwards
 */
import javax.json.bind.Jsonb;
import javax.json.bind.JsonbBuilder;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.time.LocalDateTime;

public class SendMessage {
	private static final int BUFSIZE = 508;


	public static void main(String[] args) throws Exception {
		DatagramPacket serverPacket = new DatagramPacket(new byte[BUFSIZE], BUFSIZE);
		String host = "localhost";
		int port = 50000;

		String message = createMessage();

		try (DatagramSocket socket = new DatagramSocket()) {
			InetAddress addr = InetAddress.getByName(host);
			DatagramPacket packet = new DatagramPacket(new byte[BUFSIZE], BUFSIZE, addr, port);
			byte[] data = message.getBytes();
			packet.setData(data);
			packet.setLength(data.length);
			socket.send(packet);
			/**
			 * This part works the same as the receiving part in the receiveMessage did
			 */
			socket.receive(serverPacket);
			String serverData = new String(serverPacket.getData(), 0, serverPacket.getLength());
			Message serverMessage = deserialize(serverData);
			System.out.println(serverMessage);
		}
	}

	private static String createMessage() {
		Message msg = new Message("LBS4-User", LocalDateTime.now(), "Das ist ein Test.");
		Jsonb jsonb = JsonbBuilder.create();
		return jsonb.toJson(msg);
	}

	private static Message deserialize(String data) {
		Jsonb jsonb = JsonbBuilder.create();
		return jsonb.fromJson(data, Message.class);
	}
}
