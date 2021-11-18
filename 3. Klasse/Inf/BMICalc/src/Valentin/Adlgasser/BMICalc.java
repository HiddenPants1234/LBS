/**
 * @Version 1.0
 * @Author Valentin Adlgasser
 * @Date 11.05.2020
 *
 * This class takes two inputs and calculates your BMI out of them
 */
package Valentin.Adlgasser;

public class BMICalc {
    private String bmi;
    private float weight;
    private float height;

    /**Geters and Setter for this class*/
    public void setWeight(float NewWeight){
        this.weight = NewWeight;
    }
    public void setHeight(float NewHeight){
        this.height = NewHeight;
    }
    public String getBmi(){
        bmi = bmiText(weight, height);
        return(bmi);
    }


    private float bmiCalc(float weight, float height){
        /**It's not best practis to override variables, but I wanted to try it (First time working with Java)*/
          float bmi = weight / (height * height);
          return(bmi);
    }

    private String bmiText(float weight, float height){
        float bmi = bmiCalc(weight, height);

        if(bmi <= 16){
            return("CRITICALLY UNDERWEIGHT");
        }
        else if(bmi > 16 && bmi < 20){
            return("UNDERWEIGHT");
        }
        else if(bmi >= 20 && bmi < 25){
            return("NORMAL WEIGHT");
        }
        else if(bmi >= 25 && bmi < 35){
            return("OBESE GRADE I");
        }
        else if(bmi >= 35 && bmi < 40){
            return("OBESE GRADE II");
        }
        else if(bmi >= 40){
            return("OBESE GRADE III");
        }
        return("0");
    }
}
