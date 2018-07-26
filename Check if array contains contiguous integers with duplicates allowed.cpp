using namespace std;

class Solution
{
    private:
    public:
        Solution();
        bool continousArray(vector<int> &A);
};
Solution::Solution(){}
bool Solution::continousArray(vector<int> &A)
{
    sort(A.begin(), A.end());
    int start = A[0];
    int end = A[A.size()-1];
    map<int, int> mp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
    }
    for(int iter = start; iter <= end; iter++)
    {
        if(mp[iter] == 0)
        {
            return false;
        }
    }
    return true;
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
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        bool ans = sol.continousArray(A);
        if(ans)
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
}
