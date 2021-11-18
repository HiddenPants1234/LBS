import java.io.File;
import java.io.IOException;

public class LogFile {
    public void createFile(){
        try{
            File myFile = new File("Protocol.txt");
            if(myFile.createNewFile()){
                System.out.println("File created: " + myFile.getName());
            }
            else{
                System.out.println("File already exists");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}
