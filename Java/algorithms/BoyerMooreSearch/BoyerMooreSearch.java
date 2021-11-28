package algorithms.BoyerMooreSearch;

public class BoyerMooreSearch {
      
    public static void  search(String T, String P)
    {
        int i = P.length() -1;
        int j = P.length() -1;
        do {
            if (P.charAt(j) == T.charAt(i))
            {
                if (j == 0)
                {
                    System.out.println("This sentence contains the Keyword ---> " + T);
                    return ;
                }
                else {
                    i--;
                    j--;
                }
            }
            else
            {
                i = i + P.length() - min(j, 1+last(T.charAt(i), P));    
                j = P.length()-1;
            }
        }
        while (i <= T.length()-1);
    }

    public static int last(char c, String P)
    {
        for (int i=P.length()-1; i>=0; i--)
        {
            if (P.charAt(i) == c)
                return i;
        }
        return -1;
    }

    public static int min(int a, int b)
    {
        if (a < b)
            return a;
        else if (b < a)
            return b;
        else 
            return a;
    }
}