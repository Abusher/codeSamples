package sysprogrammingalgorithm;

import java.math.BigInteger;
import java.util.Random;
import service.*;

public class Main {

    public static BigInteger AlphaProcedure()
    {

        Random rnd = new Random();
        BigInteger p1= new BigInteger(10,rnd);
        return p1;
    }
    public static void main(String[] args) {
	// write your code here

        Numbers p = new Numbers(512);

            BigInteger a = p.genPrime();
            System.out.println(a);
        System.out.println(a.isProbablePrime(10));

        a = a.nextProbablePrime();
        System.out.println(a);



    }
}
