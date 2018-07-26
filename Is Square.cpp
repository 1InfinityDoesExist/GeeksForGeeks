#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
};
Solution::Solution(){}
int finddistance(int a, int b, int c, int d)
{
    return sqrt(pow(c-a, 2) + pow(d-b, 2));
}
void Solution::solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0 && x4 == 0 && y4 == 0)
    {
        cout << "No" <<endl;
        return;
    }
    int d12 = finddistance(x1, y1, x2, y2);
    int d13 = finddistance(x1, y1, x3, y3);
    int d14 = finddistance(x1, y1, x4, y4);
    int d24 = finddistance(x2, y2, x4, y4);
    int d23 = finddistance(x2, y2, x3, y3);
    int d34 = finddistance(x3, y3, x4, y4);
    if((d12 == d23) && (d12 == d34) && (d12 == d14) && (d24 == d13))
    {
            cout << "Yes" <<endl;
            return;
    }
    else if((d12 == d13) && (d12 == d24) && (d13 == d34) && (d14 == d23))
    {
        cout << "Yes" <<endl;
        return;
    }
    else if((d12 == d34) && (d13 == d14) && (d13 == d23) && (d24 == d23))
    {
        cout << "Yes" <<endl;
        return;
    }
    cout << "No" <<endl;
    return;
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
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        sol.solve(x1, y1, x2, y2, x3, y3, x4, y4);

    }
    return 0;
}
