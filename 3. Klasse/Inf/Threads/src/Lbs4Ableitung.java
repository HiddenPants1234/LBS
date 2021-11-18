/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 25.06.2020
 *
 * This class is an extended class of the class Thread
 * The class expects an input of a String and an Integer and it simply prints the string
 */
public class Lbs4Ableitung extends Thread{
    private String name = getName();
    private String printWord;
    private int timer;

    public Lbs4Ableitung(String printWord, int timer) {
        this.printWord = printWord;
        this.timer = timer;
    }

    public void run(){
        while(1==1){
            try {
                Thread.sleep(timer);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(name + ": " + printWord);
        }
    }
}
