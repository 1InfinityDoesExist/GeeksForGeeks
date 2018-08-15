import java.io.*;
import java.lang.*;
import java.util.*;

public class Triangle
{
	public int countTriangle(ArrayList<Integer> A)
	{
		int count = 0;
		Collections.sort(A);
		for(int iter = 0; iter < A.size()-2; iter++)
		{
			int kter = iter+2;
			for(int jter = iter +1; jter < A.size(); jter++)
			{
				while(kter < A.size() && A.get(iter) + A.get(jter) > A.get(kter))
				{
					++kter;
				}
				count = count + kter-jter-1;
			}
		}
		return count;
	}
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int testCase = input.nextInt();
		Triangle tri = new Triangle();
		while(testCase-- > 0)
		{
			int n = input.nextInt();
			ArrayList<Integer> ai = new ArrayList<Integer>();
			for(int iter = 0; iter < n; iter++)
			{
				ai.add(input.nextInt());
			}
			System.out.println(tri.countTriangle(ai));
			ai.clear();
		}
	}
}
