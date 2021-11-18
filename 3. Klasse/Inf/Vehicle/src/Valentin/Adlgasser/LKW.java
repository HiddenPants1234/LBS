package Valentin.Adlgasser;

/**
 * This class extends the vehicle class
 */
public class LKW extends Vehicle {
    /**
     * Standard constructor
     *
     * @param price
     * @param colour
     * @param weight
     * @param warranty
     * @param horsepowers
     * @param gears
     * @param automatic
     */
    public LKW(double price, String colour, double weight, int warranty, int horsepowers, int gears, boolean automatic) {
        super(price, colour, weight, warranty, horsepowers, gears, automatic);
    }
}
