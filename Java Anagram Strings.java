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
    		String str1 = input.next();
    		String str2 = input.next();
            char[] ArrayTemp1 = str1.toCharArray();
            Arrays.sort(ArrayTemp1);
            String new_str1 = new String(ArrayTemp1);

            char[] ArrayTemp2 = str2.toCharArray();
            Arrays.sort(ArrayTemp2);
            String new_str2 = new String(ArrayTemp2);

            if(new_str1.equals(new_str2))
            {
                System.out.println('1');
            }
            else
            {
                System.out.println('0');
            }
		}
	}
}
