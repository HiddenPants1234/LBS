/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 26.05.2020
 *
 * This is an abstract class that simply builds a creature
 */
package Valentin.Adlgasser;

public abstract class Creature {
    public String name;

    public Creature(String name) {
        this.name = name;
    }

    /**
     * Show what kind of creature it is
     */
    public void displayCreature(){
        System.out.println("Hello, I'm a " + name);
    }

    public abstract void displayLegs(int legs);
}
