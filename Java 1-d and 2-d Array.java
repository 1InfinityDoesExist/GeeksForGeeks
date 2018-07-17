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
		    int n = input.nextInt();
		    int [][]table = new int[n][n];
		    ArrayList<Integer> ai = new ArrayList<Integer>();
		    int dia = 0;
		    int maxi = 0;
		    for(int iter = 0; iter < n; iter++)
		    {
		        for(int jter = 0; jter < n; jter++)
		        {
		            table[iter][jter] = input.nextInt();
		        }
		    }
		    for(int iter = 0; iter < n; iter++)
		    {
		        ai.add(input.nextInt());
		    }
		    //finding the diagonal sum...
		    for(int iter = 0; iter < n; iter++)
		    {
		        for(int jter = 0; jter < n; jter++)
		        {
		            if(iter == jter)
		            {
		                dia = dia + table[iter][jter];
		            }
		        }
		    }
		    //finding the max sum...
		    for(int iter = 0; iter < n; iter++)
		    {
		        int data = ai.get(iter);
		        if(data > maxi)
		        {
		            maxi = data;
		        }
		    }
		    System.out.println(dia + " "+ maxi);
		}
	}
}
