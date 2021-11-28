package utils;

public class TimeCalculator {

    public static void algorithmTimeDifference( String algorithmName, long start ) {
        long end = System.currentTimeMillis();
        System.out.println(algorithmName + "Elapsed Time in milliseconds: " + (end - start));
    }

}