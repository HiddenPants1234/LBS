/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 26.05.2020
 *
 * This class creates an animal
 */
package Valentin.Adlgasser;

public class Animal extends Creature implements Behaviorable{

    public Animal(String name) {
        super(name);
    }

    @Override
    public void displayLegs(int legs) {
        System.out.println("This Animal has " + legs + " legs");
    }

    @Override
    public void animalSound(String sound) {
        System.out.println(sound);
    }
}
