package algorithms.RegexSearch;

import java.util.regex.*;

public class RegexSearch {
    
    public static void search( String txt, String pat )
    {
        Pattern pattern = Pattern.compile(pat);
        Matcher matcher = pattern.matcher(txt);
  
        if (matcher.find() == true) {
            System.out.println("This sentence contains the Keyword ---> " + txt);
        }
    }
}