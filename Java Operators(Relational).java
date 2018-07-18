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
		    int x = input.nextInt();
		    int y = input.nextInt();
		    if(x > y)
		    {
		        System.out.println(x + " is greater than " + y);
		    }
		    else if(x < y)
		    {
		        System.out.println(x + " is less than " + y);
		    }
		    else
		    {
		        System.out.println(x + "A is equals to B" + y);
		    }
		}
	}
}
