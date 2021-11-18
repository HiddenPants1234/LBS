/**
 * @version 1.0
 * @author Valentin Adlgasser
 * @date 15.06.2020
 *
 * This class tries to replicate nslookup from the Windows command line
 */
package Valentin.Adlgasser;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class customLookup {
    public String lookup(String host){
        InetAddress address = null;
        InetAddress[] multipleAddresses = new InetAddress[0];
        String returnThis = "nothing";
        try{
            address = InetAddress.getByName(host);
            multipleAddresses = InetAddress.getAllByName(host);

        }catch(UnknownHostException e){
            System.out.println("Cannot resolve host " + host);
        }
        if(isHostname(host)){
            for(InetAddress myHost:multipleAddresses){
                returnThis = myHost.getHostAddress();
            }
        }
        else if(address == null){
        }else {
            /**
             * Do this, if it is an IP-Address
             */
            returnThis = address.getHostName();
        }
        return returnThis;
    }

    private static boolean isHostname(String host){
        char[] ca = host.toCharArray();
        /**
         * If there are other chars than a dot or a number, I'm pretty sure it is a hostname
         */
        for(int i=0; i<ca.length; i++){
            if(!Character.isDigit(ca[i])){
                if(ca[i] != '.') return true;
            }
        }
        /**
         * If everything is a digit or a dot, then it is an IP Address
         */
        return false;
    }
}
