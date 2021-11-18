package Valentin.Adlgasser;

public class Main {
    public static void main(String[] args){
        SUV suv = new SUV(60000, "Red", 2500, 3, 250, 7, true, 5, 2);
        suv.showStats();
        suv.extendWarranty(3);
        System.out.println(suv.priceAndVAT(25));
    }
}
