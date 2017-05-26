package service;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Abusher on 11.04.2017.
 */
public class Numbers {

    private static ArrayList<Integer> primes = new ArrayList<>();
    private static int size=0;

    public static int N=0;


    public Numbers()
    {
        if(size==0)
        {
            Scanner in = new Scanner(System.in);
            size = in.nextInt();
            System.out.println(size);
        }



    }
    public int getSize()
    {
        return this.size;
    }

    public BigInteger genPrime()
    {

        Random rnd = new Random();
        BigInteger number = new BigInteger(size,rnd);

        while(!this.isprime(number))
        {
            number = new BigInteger(size,rnd);

            if(number.bitLength()<=size) number = number.shiftLeft(size-number.bitLength());
            number = number.nextProbablePrime();

        }
        return number;
    }



    public boolean isprime(BigInteger prime)
    {

        if(prime.mod(BigInteger.valueOf(2))==BigInteger.ZERO) return false;
        BigInteger d = prime.subtract(BigInteger.ONE);
        int s = 0;


        do
        {
            s++;
            d=d.divide(BigInteger.valueOf(2));

        }while(d.mod(BigInteger.valueOf(2))== BigInteger.ZERO);

        outer: for (int i=0;i<2;i++)
        {
            Random rnd = new Random();
            BigInteger a = new BigInteger(size,rnd).
                    mod(prime.subtract(BigInteger.valueOf(3)));
            a = a.add(BigInteger.valueOf(2));

            BigInteger x = a.modPow(d,prime);
            if(x.equals(BigInteger.ONE)
                    || x.equals(prime.subtract(BigInteger.ONE))) {}
            else
            {
                for(int j=1; j<s;j++)
                {
                    x=x.modPow(BigInteger.valueOf(2),prime);
                    if(x.equals(BigInteger.ONE)) return false;
                    else if(x.equals(prime.subtract(BigInteger.ONE))) continue outer;

                }
                return false;
            }
        }


        return true;
    }

    public BigInteger find_reverse(BigInteger p, BigInteger module)
    {
        BigInteger reverse = BigInteger.ZERO;
        BigInteger coef = BigInteger.ZERO;

        Triple d = Extended_gcd(p,module);
        if(d.getX().compareTo(BigInteger.ZERO)==-1) return module.add(d.getX());
        else return d.getX();
    }
    private Triple Extended_gcd(BigInteger a, BigInteger  b)
    {
        BigInteger reverse;
        BigInteger coef;
        if(a.equals(BigInteger.ZERO))
        {
            reverse= BigInteger.ZERO;
            coef = BigInteger.ONE;
            return new Triple(b,reverse,coef);
        }

        Triple d = Extended_gcd(b.mod(a),a);

        BigInteger x1 = d.getX();
        BigInteger y1 = d.getY();

        reverse = y1.subtract(b.divide(a).multiply(x1));
        coef = x1;

        return new Triple(d.getZ(),reverse,coef);
    }

}
