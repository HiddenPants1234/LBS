/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 26.05.2020
 *
 * This programm creates a snake and shows all methods
 */
package Valentin.Adlgasser;

public class Main {
    public static void main(String[] args) {
        Snake snake = new Snake("Snake");
        snake.makeSound();
        snake.showLegs();
        snake.displayCreature();
    }
}
