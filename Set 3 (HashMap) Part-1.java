/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		HashMap<String, Integer> mp = new HashMap<String, Integer>();
		Scanner input = new Scanner(System.in);
		int testCase = input.nextInt();
		while(testCase-- > 0)
		{
		    int num = input.nextInt();
		    for(int iter = 0; iter < num; iter++)
		    {
		        String key = input.next();
		        int value = input.nextInt();
		        mp.put(key, value);
		    }
		    String s = input.next();
		    if(mp.containsKey(s))
		    {
		        System.out.println(mp.get(s));
		    }
		    else
		    {
		        System.out.println("-1");
		    }
		}
	}
}
