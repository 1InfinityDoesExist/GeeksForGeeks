int Solution::largestRectangleArea(vector<int> &A)
{
    stack<int> index;
    int newArea;
    int maxArea = INT_MIN;
    int iter = 0;
     while(iter < A.size())
     {
         if(index.empty() || A[index.top()] <= A[iter])
         {
             index.push(iter++);
         }
         else
         {
             int tp = index.top();
             index.pop();
             newArea = A[tp] * (index.empty() ? iter : iter - index.top() -1);
             if(maxArea < newArea)
             {
                 maxArea = newArea;
             }
         }
     }
     while(!index.empty())
     {
         int tp = index.top();
         index.pop();
         newArea = A[tp] * (index.empty() ? iter : iter - index.top() -1);
         if(maxArea  < newArea)
         {
             maxArea = newArea;
         }
     }
     return maxArea;
}
