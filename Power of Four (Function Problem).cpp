/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


int isPowerOfFour(unsigned int n)
{
  // Your code goes here
  if(n <= 0)
  {
      return false;
  }
  while(n%4 == 0)
  {
      n /= 4;
  }
  return n == 1;
}
