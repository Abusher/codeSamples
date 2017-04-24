package com.company;

import java.lang.*;
import java.lang.String;
import java.util.Collection;
import java.util.Set;
import java.util.Collections;
import java.util.HashSet;
import java.util.Vector;
import java.io.*;


public class Main {

    public static void main(String[] args) throws Throwable {
	// write your code here


        Automat a1 = new Automat("C:\\Users\\Еф\\Desktop\\file2.txt");
        Automat a2 = new Automat("C:\\Users\\Еф\\Desktop\\file.txt");
        if(a1.Equal(a2)) System.out.println("Automats are equal");
        else System.out.println("Not equal");


    }
}
