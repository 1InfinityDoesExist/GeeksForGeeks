/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner input = new Scanner(System.in);
		int testCase = input.nextInt();
		while(testCase-- > 0)
		{
		    String str = input.next();
		    char[] array = str.toCharArray();
		    ArrayList<Character> ac = new ArrayList<Character>();
		    for(char c : array)
		    {
		        ac.add(c);
		    }
		    Collections.reverse(ac);
		    ListIterator iter = ac.listIterator();
		    while(iter.hasNext())
		    {
		        System.out.print(iter.next());
		    }
		    System.out.println();
		}
	}
}
