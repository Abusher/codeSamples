package service;

import javafx.util.Pair;
import sysprogrammingalgorithm.Main;

import java.math.BigInteger;

/**
 * Created by Abusher on 18.05.2017.
 */
public class Procedures {

    private Numbers rand = new Numbers();
    private BigInteger p1;
    private BigInteger q1;
    private BigInteger p2;
    private BigInteger q2;

    public Pair<BigInteger,BigInteger> ProcedureAlpha(BigInteger v, BigInteger c)
    {

        System.out.println();
        System.out.println("Alpha procedure by leader: ");
        long s = System.currentTimeMillis();



        do
        {
            p1 = rand.genPrime();
            p1 = p1.mod(v);
            p1 = p1.nextProbablePrime();
        }while(p1.compareTo(v)!=-1 || !rand.isprime(p1));


        System.out.println("p1 = " + p1);


       do
        {
            q1 = rand.genPrime();
            q1 = q1.mod(v);
            q1 = q1.nextProbablePrime();

        }while(q1.compareTo(v)!=-1 || !rand.isprime(q1));

        System.out.println("q1 = " + q1);

        BigInteger Vsquared = BigInteger.valueOf(2).multiply(v.pow(2));

        do
        {
            p2 = rand.genPrime();
            p2 = p2.add(v.pow(2)).nextProbablePrime();

        }
        while(p2.compareTo(Vsquared)!=-1 || !rand.isprime(p2));

        System.out.println("p2 = " + p2);

       System.out.println(p2.compareTo(v.multiply(v)));
       System.out.println(p2.compareTo(v.pow(2).multiply(BigInteger.valueOf(2))));
        BigInteger ci=rand.find_reverse(c,v);
        BigInteger p2i=rand.find_reverse(p2,v);

        BigInteger q1i=rand.find_reverse(q1,v);


        BigInteger r = ci.multiply(p2i.multiply(q1i));
        if(r.mod(BigInteger.valueOf(2))==BigInteger.ZERO) r = r.add(v);

        //System.out.println(r.multiply(c.multiply(p2.multiply(q1))).mod(v));
        q2 = r;
        int l=1;
        do {
            q2 = q2.add(v).add(v);
            l++;

        }while( !q2.isProbablePrime(1));
       // System.out.println(l);
        //System.out.println(rand.isprime(q2));
        System.out.println("q2 = " + q2);


        BigInteger n1 = p1.multiply(q1);
        BigInteger n2 = p2.multiply(q2);

        BigInteger N = n1.multiply(n2);
        long e = System.currentTimeMillis();

        System.out.println(e-s);

    return new Pair<>(N,n1);
    }

   public BigInteger ProcedureBeta(BigInteger N,BigInteger v,BigInteger c)
   {

       BigInteger p = c.multiply(N).mod(v);

       return p;
   }

   public BigInteger GetP()
   {
       return p1;
   }
   public BigInteger GetQ(){
        return q1;
   }



}
