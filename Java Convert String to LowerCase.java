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
		    char[] ar = str.toCharArray();
		    for(int iter = 0; iter < str.length(); iter++)
		    {
		        if(ar[iter] >= 'A' && ar[iter] <= 'Z')
		        {
		            ar[iter] = Character.toLowerCase(ar[iter]);
		        }
		    }
		    String s = new String(ar);
		    System.out.println(s);
		}
	}
}
