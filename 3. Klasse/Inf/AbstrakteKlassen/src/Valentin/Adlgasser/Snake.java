/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 26.05.2020
 *
 * This class creates a snake
 */
package Valentin.Adlgasser;

public class Snake extends Animal{

    public Snake(String name) {
        super(name);
    }

    public void makeSound(){
        animalSound("Tzzzzz");
    }
    public void showLegs(){
        displayLegs(0);
    }

}
