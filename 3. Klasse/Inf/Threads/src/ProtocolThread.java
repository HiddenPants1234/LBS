/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 25.06.2020
 *
 * This class is an extended class of the class Thread
 * This class expects an input message and writes the message + the current timestamp to a file
 */
import java.io.FileWriter;
import java.io.IOException;

public class ProtocolThread extends Thread{
    private String message;
    private LogFile File = new LogFile();

    public ProtocolThread(String message) {
        this.message = message;
    }

    public void run(){
        File.createFile();
        for(int i = 0; i < 5; i++){
            try {
                FileWriter myWriter = new FileWriter("Protocol.txt", true);
                myWriter.write(message + " " + java.time.LocalDateTime.now() + System.getProperty("line.separator"));
                myWriter.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
