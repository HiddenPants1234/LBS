package Valentin.Adlgasser;

/**
 * This class adds a gearbox to the vehicle
 */
public class Gearbox {
    private int numOfGears;
    private boolean automatic;

    /**
     * Standard Constructor
     */
    public Gearbox(int numOfGears, boolean automatic) {
        this.numOfGears = numOfGears;
        this.automatic = automatic;
    }

    public String outputGearbox(){
        return("Number of Gears: " + numOfGears + "\r\nIs it automatic: " + automatic);
    }
}
