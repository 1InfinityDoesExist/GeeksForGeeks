using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> findonesingle(vector<int> &A, vector<int> &B);
};
Solution::Solution(){}
vector<int> Solution::findonesingle(vector<int> &A, vector<int> &B)
{
    vector<int> res;
    int lenA = A.size();
    int lenB = B.size();
    map<int , int> mp;
    for(int iter = 0; iter < lenB; iter++)
    {
        mp[B[iter]]++;
    }
    for(int iter = 0; iter < lenA; iter++)
    {
        if(mp.find(A[iter]) == mp.end())
        {
            res.push_back(A[iter]);
        }
    }
    return res;
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
        int n, m;
        cin >> n >> m;
        vector<int> A;
        vector<int> B;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        for(int iter = 0; iter < m; iter++)
        {
            int data;
            cin >> data;
            B.push_back(data);
        }
        vector<int> ans = sol.findonesingle(A, B);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
