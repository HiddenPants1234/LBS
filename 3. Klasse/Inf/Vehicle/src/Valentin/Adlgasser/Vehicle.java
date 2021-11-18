package Valentin.Adlgasser;

/**
 * This class creates a Vehicle
 */
public class Vehicle {
    private double price;
    private String colour;
    private double weight;
    private int warranty;
    private Motor horsepower;
    private Gearbox gearbox;

    /**
     * Standard constructor
     */
    public Vehicle(double price, String colour, double weight, int warranty, int horsepowers, int gears, boolean automatic) {
        this.price = price;
        this.colour = colour;
        this.weight = weight;
        this.warranty = warranty;
        this.horsepower = new Motor();
        horsepower.setHorsepower(horsepowers);
        this.gearbox = new Gearbox(gears, automatic);
    }

    /**
     * Getters and setters for this class
     */
    public void setHorsepower(int horsepowers) {
        horsepower.setHorsepower(horsepowers);
    }

    public int getHorsepower() {
        return horsepower.getHorsepower();
    }

    public int getWarranty() {
        return warranty;
    }

    public void setWarranty(int warranty) {
        this.warranty = warranty;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public String getColour() {
        return colour;
    }

    public void setColour(String colour) {
        this.colour = colour;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    /**
     * @param vat
     * Returns the price + VAT
     */
    public double priceAndVAT(double vat){

        return(this.price + (this.price*(vat/100)));
    }

    /**
     * @param warrantyYears
     * Adds more years to the warranty
     */
    void extendWarranty(int warrantyYears) {

        warranty += warrantyYears;
    }

    /**
     * Outputs the Stats of the vehicle
     */
    void showStats(){
        System.out.println("Price: " + price + "€\r\nColour: " + colour + "\r\nWeight: " + weight + "kg\r\nWarranty: " + warranty + "Years\r\nHorsepower: " + horsepower.getHorsepower() + "\r\n" + gearbox.outputGearbox());
    }
}
