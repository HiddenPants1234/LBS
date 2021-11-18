package Valentin.Adlgasser;

/**
 * This class extends the Vehicle
 */
public class SUV extends Vehicle {
    private int occupants;
    private int safetyRating;

    /**
     * Standard constructor
     */
    public SUV(double price, String colour, double weight, int warranty, int horsepowers, int gears, boolean automatic, int occupants, int safetyRating) {
        super(price, colour, weight, warranty, horsepowers, gears, automatic);
        this.occupants = occupants;
        this.safetyRating = safetyRating;
    }

    /**
     * Getters and setters
     */
    public int getOccupants() {
        return occupants;
    }

    public void setOccupants(int occupants) {
        this.occupants = occupants;
    }

    public int getSafetyRating() {
        return safetyRating;
    }

    public void setSafetyRating(int safetyRating) {
        this.safetyRating = safetyRating;
    }

}
