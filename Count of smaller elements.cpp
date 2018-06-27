#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    public:
        Solution();
        int big(vector<int> v,const int d);
};
Solution::Solution(){}
int Solution::big(vector<int> v,const int d)
{
    int count (0);
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        if(*iter <= d)
        {
            count++;
            continue;
        }
        else
        {
            break;
        }
    }
    return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution sol;
	int testcase;
	cin>>testcase;
	while (testcase--)
	{
	    vector<int> v;
	    int n;
	    cin >> n;
	    for(int i=0;i<n;i++)
	    {
	        int data;
	        cin>>data;
	        v.push_back(data);
	    }
	    int d;
	    cin>>d;
	    int ans=sol.big(v,d);
	    cout<<ans<<endl;
	}

	return 0;
}
