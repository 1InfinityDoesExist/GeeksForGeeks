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
		    String str = new String(input.next());
		    char[] charArray = str.toCharArray();
		    StringBuilder sbr = new StringBuilder();

		    for(int iter = 0; iter < str.length(); iter++)
		    {
		       if(iter %2 == 0)
		       {
		           sbr.append(charArray[iter]);
		       }
		       else
		       {
		           continue;
		       }
		    }
		    System.out.println(sbr);
		}
	}
}
