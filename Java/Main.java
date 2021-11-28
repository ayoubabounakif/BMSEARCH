import java.util.*;

import algorithms.NaiveSearch.*;
import algorithms.OptimizedNaiveSearch.*;
import algorithms.RegexSearch.*;
import algorithms.BoyerMooreSearch.*;
import utils.*;

import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

/*
    javac Main.java
    java Main
*/

public class Main {

    public static void main( String[] args )
    {
        long start;
        String pat = "ATTTGACGCG";
        List<String> txt = new ArrayList<String>();
        try {
            File myFile = new File("files/BIG_DNA_sequence.txt");
            Scanner myReader = new Scanner(myFile);
            while (myReader.hasNextLine()) {
                txt.add(myReader.nextLine());
            }
            myReader.close();
        } catch ( FileNotFoundException e ) {
            System.out.println("An error occured.");
            e.printStackTrace();
        }


        start = System.currentTimeMillis();
        for (String line : txt) {
            NaiveSearch.search(line, pat);
        }
        TimeCalculator.algorithmTimeDifference("Naive Search           || ", start);


        start = System.currentTimeMillis();
        for (String line : txt) {
            OptimizedNaiveSearch.search(line, pat);
        }
        TimeCalculator.algorithmTimeDifference("Optimized Naive Search || ", start);


        start = System.currentTimeMillis();
        for (String line : txt) {
            RegexSearch.search(line, pat);
        }
        TimeCalculator.algorithmTimeDifference("Regex                  || ", start);


        start = System.currentTimeMillis();
        for (String line : txt) {
            BoyerMooreSearch.search(line, pat);
        }
        TimeCalculator.algorithmTimeDifference("Boyer-Moore            || ", start);      

    }
}