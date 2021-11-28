# How I thought of everything

## Compiling for C++
You can change the dataset on __main__.cpp line 37.
make ; ./a.out | grep microseconds<br>
make ; ./a.out

## Compiling for Java
You can change the dataset on Main.java line 26.
javac Main.java<br>
java Main


At first, I implemented the most basic way to find a substring in a string
Which is the Naive Search Algorithm

For example :<br>
    Text[] = "AABBSAAAHWHWLLLLEEQAAAABBC";<br>
    Pattrn = "AAAA";<br>

I'm gonna check AAAA with AABB, if it's equal, then the string was found
else we increment the pointer by 1 and check again AAAA wiuth SAAA in our case
and so on.

This algorithm has an optimization which goes like :<br>
    When a mismatch occurs after j matches,
    we know that the first character of pattern will not match the j matched characters
    because all characters of pattern are different.
    So we can always slide the pattern by j without missing any valid shifts.


I also tried with the C++ find method and the Regex on Java.

I also tried with the Boyer-Moore algorithm which does preprocessing.
It processes the pattern and creates different arrays for each of the two heuristics.
At every step, it slides the pattern by the max of the slides suggested by each of the two heuristics.
So it uses greatest offset suggested by the two heuristics at every step. 
The Boyer Moore algorithm starts matching from the last character of the pattern.

I also wanted to use threads, but then I got mixed up and decided to stop because I have other deadlines.
    
