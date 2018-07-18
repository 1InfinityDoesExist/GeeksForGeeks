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
		    StringBuilder str = new StringBuilder(input.next());
		    int number = input.nextInt();
		    System.out.println("The input string :"+str);
		    System.out.println("The input integer :"+number);
		}
	}
}
