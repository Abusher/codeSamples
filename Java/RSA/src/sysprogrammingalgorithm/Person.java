package sysprogrammingalgorithm;

import javafx.util.Pair;
import service.Numbers;
import service.Procedures;

import java.math.BigInteger;

/**
 * Created by Abusher on 20.05.2017.
 */
public class Person {

    private static BigInteger N;

    private static BigInteger n1;

    private static BigInteger v;
    private static BigInteger c;
    private static int k=0;
    private Procedures proc = new Procedures();

    public  Person()
    {
        if(k==0)
        {
            Numbers p = new Numbers();
            System.out.println("Generated secret key :");
            v = p.genPrime();

            System.out.println("v = " + v);
            c = p.genPrime();

            System.out.println("c = " + c);
            GenerateN();
        }
        k++;
    }

    public void GenerateN()
    {


        Pair<BigInteger,BigInteger> alpha = proc.ProcedureAlpha(this.v,this.c);

        N = alpha.getKey();
        n1 = alpha.getValue();
    }

    public boolean Authentication()
    {
        long s = System.currentTimeMillis();
        System.out.println();
        BigInteger p = proc.ProcedureBeta(this.N, this.v,this.c);
        System.out.println("Beta procedure by user: \n p1 = " + p);
        System.out.println();
        System.out.print("Beta procedure time: ");
        System.out.println(System.currentTimeMillis()-s);
        if(p.equals(proc.GetP())) return true;
        return false;

    }



}
