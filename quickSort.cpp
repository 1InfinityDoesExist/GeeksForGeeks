#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    void quickSort(vector<int> &A);
};
Solution::Solution(){}
int partition(vector<int> &A, int low, int high)
{
    int pivot = A[high];
    int iter = low-1;
    for(int jter = low; jter < high; jter++)
    {
        if(A[jter] < pivot)
        {
            iter++;
            swap(A[iter], A[jter]);
        }
    }
    swap(A[iter+1], A[high]);
    return iter+1;
}
void quicksort(vector<int> &A, int low, int high)
{
    if(low < high)
    {
        int pi = partition(A, low, high);
        quicksort(A, low, pi-1);
        quicksort(A, pi+1, high);
    }
}
void Solution::quickSort(vector<int> &A)
{
    int low = 0;
    int high = A.size()-1;
    quicksort(A, low, high);
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
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        sol.quickSort(v);
        for(int iter = 0; iter < n; iter++)
        {
            cout << v[iter] << " ";
        }
        cout << endl;
    }
    return 0;
}
