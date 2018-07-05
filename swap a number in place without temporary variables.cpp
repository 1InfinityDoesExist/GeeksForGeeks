#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    void swapping1(int x, int y);
    void swapping2(int u, int v);
};
Solution::Solution(){}
void Solution::swapping1(int x, int y){
    cout << "The value of x and y before is " << x << " " << y << endl;
    x = x^y;
    y = x^y;
    x = x^y;
    cout << "The value of x and y after is " << x << " " << y << endl;
    return;
}
void Solution::swapping2(int x, int y)
{
    cout << "The value of x and y before is " << x << " " << y << endl;
    x = y - x;
    y = y - x;
    x = x + y;
    cout << "The value of x and y after is " << x << " " << y << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int a, b;
    cin >> a >> b;
    sol.swapping1(a, b);
    int x,y;
    cin >> x >> y;
    sol.swapping2(x, y);
    return 0;
}
