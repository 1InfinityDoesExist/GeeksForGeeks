#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int find_in_sorted_and_rotated_array(vector<int> &A, const int k);
};
Solution::Solution(){}
int Solution::find_in_sorted_and_rotated_array(vector<int> &A, const int k)
{
    if(A.size() == 0)
    {
        return 0;
    }
    int low = 0;
    int high = A.size()-1;
    while(low < high)
    {
        int mid = low + (high-low)/2;
        if(A[mid] == k)
        {
            return mid;
        }
        if(A[low] <= A[mid])
        {
            if(k >= A[low] && k < A[mid])
            {
                high = mid-1;
            }
            else
            {
                low  = mid+1;
            }
        }
        else
        {
            if(k > A[mid] && k <= A[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return A[low] == k ? low : 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.find_in_sorted_and_rotated_array(A, k);
        if(ans)
        {
            cout << "Found "<<endl;
        }
        else
        {
            cout << "OOPS! NOT FOUND" <<endl;
        }
    }
    return 0;
}
