package algorithms.NaiveSearch;

public class NaiveSearch {
    
    public static void search( String txt, String pat )
    {
        int M = pat.length();
        int N = txt.length();
        for (int i = 0; i <= N - M; i++) {
            int j = 0;
            for (; j < M; j++)
                if (txt.charAt(i + j) != pat.charAt(j))
                    break ;
            if (j == M)
                System.out.println("This sentence contains the Keyword ---> " + txt);
        }
    }
}