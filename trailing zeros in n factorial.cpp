
/*
simple logic...
number/5 + number/25

example number = 100;
        number/5 + number/25;
        100/5 + 100/25;
        20 + 4;
        24 which is the answer...
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int trailZeros(int num);
};
Solution::Solution(){}
int Solution::trailZeros(int num)
{
    int count (0);
    if(num < 0)
    {
        return 0;
    }
    for(int iter = 5; num/iter > 0; iter *= 5)
    {
        count += num/iter;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    int ans = sol.trailZeros(n);
    cout << ans <<endl;
    return 0;
}
