
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		ArrayList<Integer> ai = new ArrayList<Integer>();
		ArrayList<Integer> aii = new ArrayList<Integer>();
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		while(n-- > 0)
		{
    		int num = input.nextInt();
    		int MaxNumber = input.nextInt();
    		for(int iter = 0; iter < num; iter++)
    		{
    		    ai.add(input.nextInt());
    		}
    	   /* for(int iter = 0; iter < ai.size(); iter++)
    	    {
    	       int value = ai.get(iter);
    	       if(value >= MaxNumber)
    	       {
    	           aii.add(value);
    	       }
    	    }
    	    Collections.sort(aii);*/
    	    ListIterator<Integer> iter = ai.listIterator();
    	    while(iter.hasNext())
    	    {
    	        int x = (Integer)iter.next();
    	        if(x < MaxNumber)
    	        {
    	            iter.remove();
    	        }
    	    }
    	    Collections.sort(ai);
    		System.out.println(ai);
    		aii.clear();
    		ai.clear();
		}
	}
}
