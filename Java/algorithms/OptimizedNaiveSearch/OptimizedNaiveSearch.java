package algorithms.OptimizedNaiveSearch;

public class OptimizedNaiveSearch {

    public static void search( String txt, String pat )
    {
        int M = pat.length();
        int N = txt.length();
        int i = 0;
        while (i <= N - M)
        {
            int j = 0;
            for (; j < M; j++)
                if (txt.charAt(i + j) != pat.charAt(j))
                    break;
            if (j == M)
            {
                System.out.println("This sentence contains the Keyword ---> " + txt);
                i = i + M;
            }
            else if (j == 0)
                i = i + 1;
            else
                i = i + j;
        }
    }
}