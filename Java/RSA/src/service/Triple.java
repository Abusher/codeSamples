package service;

import java.math.BigInteger;

/**
 * Created by Abusher on 13.05.2017.
 */
public class Triple {

     private BigInteger x,y,z;

     Triple(BigInteger z,BigInteger x, BigInteger y)
     {
         this.x = x;
         this.y = y;
         this.z = z;
     }
     public BigInteger getX(){
         return x;
    }
    public BigInteger getY(){
        return y;
    }
    public BigInteger getZ(){
        return z;
    }
}
