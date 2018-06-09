#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int countInversion(vector<int> &A);
};
Solution::Solution(){}
int merge(vector<int> &A, int *temp, int left, int mid, int right)
{
    int i, j ,k;
    int inv_count (0);
    i = left;
    j = mid;
    k = left;
    while(i <= mid-1 && j <= right)
    {
        if(A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            inv_count = inv_count + mid-i;
        }
    }
    while(i <= mid-1)
    {
        temp[k++] = A[i++];
    }
    while(j <= right)
    {
        temp[k++] = A[j++];
    }
    for(int iter = left; iter <= right; iter++)
    {
        A[iter] = temp[iter];
    }
    return inv_count;
}
int _mergeSort(vector<int> &A, int *temp, int left, int right)
{
    int count (0);
    if(left < right)
    {
        int mid = (right+left)/2;
        count = _mergeSort(A, temp, left, mid);
        count += _mergeSort(A, temp, mid+1, right);
        count += merge(A, temp, left, mid+1, right);
    }

    return count;
}
int Solution::countInversion(vector<int> &A)
{
    int n = A.size();
    int *temp = (int *)malloc(sizeof(int) * n);
    return _mergeSort(A, temp, 0, n-1);
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
        vector<int> v;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.countInversion(v);
        cout << ans << endl;
    }
    return 0;
}
