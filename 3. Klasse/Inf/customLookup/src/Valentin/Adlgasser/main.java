/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 15.06.2020
 *
 * This program tries to replicate the nslookup command from Windows
 */
package Valentin.Adlgasser;

import org.junit.Test;

import java.net.UnknownHostException;

public class main {
    public static void main(String[] args) throws UnknownHostException {
        customLookup customLookup = new customLookup();
        customLookup.lookup("100.100.100.1000");
    }
    @Test
    void ipTest(){
        customLookup lookupTest = new customLookup();

    }
}


