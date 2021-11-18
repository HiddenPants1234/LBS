/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 16.06.2020
 *
 * This class is there to create a message to send
 */
import java.time.LocalDateTime;

public class Message {
	private String user;
	private LocalDateTime timestamp;
	private String message;

	public Message() {
	}

	public Message(String user, LocalDateTime timestamp, String message) {
		this.user = user;
		this.timestamp = timestamp;
		this.message = message;
	}

	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}

	public LocalDateTime getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(LocalDateTime timestamp) {
		this.timestamp = timestamp;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	@Override
	public String toString() {
		return "Message{" +
				"user='" + user + '\'' +
				", timestamp=" + timestamp +
				", message='" + message + '\'' +
				'}';
	}
}
