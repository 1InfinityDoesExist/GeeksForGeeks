/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args)  throws IOException{
		//code
		Scanner input = new Scanner(System.in);
		int testCase = input.nextInt();
		while(testCase-- > 0)
		{
		    String str = new String(input.next());
		    int left = input.nextInt();
		    int right = input.nextInt();

		    int len = (right-left);
		    if(left >= 0 && right+1 <= str.length())
		    {
		        System.out.println(str.substring(left, right+1));
		    }

		}
	}
}
