package Valentin.Adlgasser;

/**
 * This class extends the Vehicle class
 */
public class PKW extends Vehicle{
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
    public PKW(double price, String colour, double weight, int warranty, int horsepowers, int gears, boolean automatic) {
        super(price, colour, weight, warranty, horsepowers, gears, automatic);
    }
}
