package service;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Abusher on 11.04.2017.
 */
public class Numbers {

    private static ArrayList<Integer> primes = new ArrayList<>();
    private int size;
    private static int k=0;

    public Numbers(int n)
    {
        this.size = n;

        if(k==0) sieve();
        k++;
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


        }
        return number;
    }



    private boolean isprime(BigInteger prime)
    {

        if(prime.mod(BigInteger.valueOf(2))==BigInteger.ZERO) return false;
        BigInteger d = prime.subtract(BigInteger.ONE);
        int s = 0;
        for (Integer p :primes) {
            BigInteger remainder = prime.mod(BigInteger.valueOf(p));
            if(remainder.equals(BigInteger.ZERO)) return false;
        }

        do
        {
            s++;
            d=d.divide(BigInteger.valueOf(2));

        }while(d.mod(BigInteger.valueOf(2))== BigInteger.ZERO);

        outer: for (int i=0;i<10;i++)
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
    private void sieve()
    {
        boolean p[] = new boolean[2001];

        for (int i = 0; i < p.length; i++) {
            p[i]=true;
        }

        primes.add(2);
        for(int j=4;j<p.length;j+=2) p[j]=false;

        for(int i=3;i<p.length;i+=2)
        {
            if(p[i]==false) {}
            else
            {
                primes.add(i);
                for(int j=i*2;j<p.length;j+=i) p[j]=false;
            }
        }


    }
}
