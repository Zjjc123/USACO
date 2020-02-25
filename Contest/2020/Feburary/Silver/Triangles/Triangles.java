/*
ID: zjjc123
LANG: JAVA
TASK: Triangles
*/

import java.util.*;
import java.io.*;
import javafx.util.Pair;

public class Triangles
{
    public static void main(String[] args) throws IOException
    {
        HashSet<Pair<Integer, Integer>> points = new HashSet<Pair<Integer, Integer>>();
        
        BufferedReader f = new BufferedReader(new FileReader("triangles.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));
        
        StringTokenizer st = new StringTokenizer(f.readLine());
        int N = Integer.parseInt(st.nextToken());

        int sum = 0;
        int max = (int)Math.pow(10, 9) + 7;
        for (int i = 0; i < N; i++)
        {
            st = new StringTokenizer(f.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());


            for (Pair<Integer, Integer> p : points)
            {
                Pair<Integer, Integer> p1 = new Pair(p.getKey(), y);
                Pair<Integer, Integer> p2 = new Pair(x, p.getValue());
                                        
                if (points.contains(p1))
                {
                    int add = (p1.getValue() - p.getValue()) * (p1.getKey() - x);
                    sum += Math.abs(add);
                }

                if (points.contains(p2))
                {
                    int add = (p2.getKey() - p.getKey()) * (p2.getValue() - y);
                    sum += Math.abs(add);
                }
                sum = sum % max;
            }
            points.add(new Pair(x, y));
        }
       
        out.println(sum);
        out.close();
    }
}