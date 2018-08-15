import java.lang.*;
import java.util.*;
import java.io.*;

public class OddFactor
{
	public int countOddFactor(final int N)
	{
		return (int)(Math.pow((double)N, 0.5)) - (int)(Math.pow((double)0, 0.5));
	}
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		OddFactor of = new OddFactor();
		int testCase = input.nextInt();
		while(testCase-- > 0)
		{
			int N = input.nextInt();
			System.out.println(of.countOddFactor(N));

		}
	}
}
