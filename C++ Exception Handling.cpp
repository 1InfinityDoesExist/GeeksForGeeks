#include<bits/stdc++.h>
using namespace std;

class MyException : public exception{
    private:
        const char *msg = "";
        MyException(){}
    public:
        MyException(const char *s):msg(s){}
        const char *what() const throw(){
            return msg;
        }
};

int max(int x, int y){
    return x > y ? x : y;
}
int min(int x, int y){
    return x < y ? x : y;
}
class Solution
{
    private:
    public:
        Solution();
        void solve(int x, int y);
};
Solution::Solution(){}
void Solution::solve(int x, int y){
    if(y == 0){
        try{
            throw MyException("inf");
           // throw m;

        }catch(exception &e){
            cout << e.what() << endl;
        }
        return;
    }

    if(x < 0 && y < 0 || x > 0 && y > 0){
        cout << x*y << endl;
        return;
    }
    else if( y < 0){
        cout << (max(x, y) - min(x, y)) << endl;
        return;
    }
    else if(x < 0 && (y < abs(x)) ){
        cout << x/y << endl;
        return;
    }
    else{
        cout << x + y << endl;
        return;
    }
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
        int x, y;
        cin >> x >> y;
        sol.solve(x, y);
    }
    return 0;
}
