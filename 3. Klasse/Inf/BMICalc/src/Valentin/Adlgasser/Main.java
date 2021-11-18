/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 11.05.2020
 *
 * This program takes two inputs and uses a class to calculate your BMI<
 */
package Valentin.Adlgasser;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BMICalc bmiObject = new BMICalc();
        Scanner scan = new Scanner(System.in);

        System.out.println("Please insert your weight in kg:");
        /**Try block to make sure that an int or a float is inserted*/
        try{
            float weight = scan.nextFloat();
            bmiObject.setWeight(weight);
        }catch(Exception e){
            System.out.println("No weight inserted!!");
        }finally{
            System.exit(0);
        }

        System.out.println("Please insert your height in meters:");
        /**Try block to make sure that an int or a float is inserted*/
        try{
            float height = scan.nextFloat();
            bmiObject.setHeight(height);
        }catch(Exception e){
            System.out.println("No height inserted!!");
        }finally{
            System.exit(0);
        }

        System.out.println("According to your BMI your are " + bmiObject.getBmi());
    }
}
