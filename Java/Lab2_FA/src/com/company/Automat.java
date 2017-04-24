package com.company;


import com.sun.corba.se.impl.oa.poa.ActiveObjectMap;
import com.sun.org.apache.xpath.internal.SourceTree;

import java.awt.print.Paper;
import java.lang.*;
import java.lang.String;

import java.util.*;
import java.io.*;
import javafx.util.Pair;
import java.util.Set;
/**
 * Created by Еф on 30.10.2016.
 */
public class Automat {

    private Set Alpha = new HashSet();

    private int S, n;
    private String s = "", numb[];
    private int s0, k;
    private Set<Integer> F = new HashSet();
    private File file;
    private BufferedReader in;
    ArrayList<Pair<Pair<Integer, String>, Integer>> f = new ArrayList<>();
    int used[][];
    int us = 0;
    int states[];

    public int graph[][];

    public Automat(String path) throws Throwable {
        file = new File(path);

        try {
            in = new BufferedReader(new FileReader(file));
            init();

        } catch (FileNotFoundException f) {
            System.out.println(f);
        }
    }


    private void init() throws Throwable {
        n = Integer.parseInt(s = in.readLine());
        S = Integer.parseInt(s = in.readLine());
        s0 = Integer.parseInt(s = in.readLine());

        numb = in.readLine().split(" ");
        for (String s : numb) {
            F.add(Integer.parseInt(s));
        }
        while ((s = in.readLine()) != null) {
            numb = s.split(" ");
            Pair b = new Pair(numb[0], numb[1]);
            Pair k = new Pair(b, numb[2]);
            Alpha.add(numb[1]);
            f.add(k);

        }
        used = new int[S][2];
        for (int i = 0; i < used.length; i++) {
            used[i][0] = -1;
            used[i][1] = 0;
        }

        miniz();
    }

    private void miniz() throws Throwable {

        f = Delete_Tupic();

    }

    private void Delete_Unreachable() {
        Set<Integer> can = new HashSet<>();
        for (Pair pair : f) {


            can.add(Integer.parseInt((String) pair.getValue()));


        }

        Set<Integer> not = new HashSet<>();
        for (int i = 0; i < S; i++) {

            boolean b = false;
            for (int i1 : can) {
                if (i == i1) b = true;
            }
            if (!b) not.add(i);

        }
        for (int i : not) {
            if (i != s0) S--;


        }


    }

    public ArrayList<Pair<Pair<Integer, String>, Integer>> Delete_Tupic() throws Throwable {
        graph = new int[S][];
        ArrayList<Pair<Pair<Integer, String>, Integer>> newf = new ArrayList<>();
        for (int i = 0; i < S; i++) {
            List<Integer> a = new ArrayList<>();
            int k = 0;
            for (Pair pair : f) {
                Pair p1 = (Pair) pair.getKey();
                if (Integer.parseInt((String) p1.getKey()) == i) {
                    k++;
                    a.add(Integer.parseInt((String) pair.getValue()));
                }


            }
            graph[i] = new int[k];
            for (int j = 0; j < k; j++) {
                graph[i][j] = a.get(j);

            }
        }
        dfs(s0);


        for (int i = 0; i < used.length; i++) {

            if (used[i][0] == -1) S--;
            else if (used[i][1] == 0) {
                boolean b = false;
                for (int i1 : F) {
                    if (i1 == i) b = true;

                }

                if (!b) {
                    S--;
                    int n = 0;
                    for (Pair pair : f) {

                        int a = Integer.parseInt((String) pair.getValue());
                        if (a != i) newf.add(pair);
                        n++;
                    }

                }
            }


        }
        if (newf.size() == 0) return f;
        return newf;
    }

    public int dfs(int pos) {

        us++;
        int k = 0;
        used[pos][0] = us;
        for (int next : graph[pos]) {
            if (used[next][0] < 0) {
                k += dfs(next);
                k++;
            }
        }
        used[pos][1] += k;
        us--;

        return k;
    }

    public boolean Equal(Automat a1) {


        System.out.println("Automat 1 f: " + this.f);
        System.out.println("Automat 2 f: "+ a1.f);

        if (this.S != a1.S) return false;
        if (this.f.size() != a1.f.size()) return false;
        int k1 = 0;
        int k2 = 0;
        for (Object o : this.Alpha) {
            k1++;
            for (Object o1 : a1.Alpha) {
                if (o.equals(o1)) k2++;
            }

        }
        if (k1 != k2) return false;
        int k = 1;

        states=new int [S];
        for (int i = 0; i < this.S; i++) {

                states[i]= -1;


        }
        states[this.s0]= a1.s0;
        while(k<S) {
            for (Pair pair : this.f) {
                Pair p1 = (Pair) pair.getKey();
                int i = Integer.parseInt((String) p1.getKey());
                if (states[i] >= 0) {

                    int i1 = Integer.parseInt((String) pair.getValue());
                    states[i1] = a1.Vertex(states[i], p1.getValue().toString());
                    if (states[i1] > -1) k++;

                }
            }
        }

        for (int i = 0; i < states.length; i++)
        {
            System.out.println(i+" = " + states[i]);
            boolean b1 = false;
            boolean b2 = false;
            for (int i1:this.F)
            {
               if ( i == i1) b1=true;
            }
            for (int i1 : a1.F)
            {
                if(states[i]==i1) b2=true;
            }
            if(b1!=b2) return false;

        }

    return true;
    }
    private int Vertex(int s, String c)
    {
        System.out.println(s +" "+c);
        for (Pair pair : f) {
            Pair p = (Pair)pair.getKey();
            if(s == Integer.parseInt((String)p.getKey()) && c.equals(p.getValue())) return Integer.parseInt((String)pair.getValue());
        }

        return -1;

    }
}
