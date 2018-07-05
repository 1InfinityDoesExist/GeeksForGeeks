#include<bits/stdc++.h>
using namespace std;

#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1

class Solution
{
private:
public:
    Solution();
    int bigOrLittle();
};
Solution::Solution(){}
int Solution::bigOrLittle(){
    short int word = 0x0001;
    char *str = (char *) &word;
    return (str[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int ans = sol.bigOrLittle();
    if(1)
    {
        cout << "LITTLE_ENDIAN" <<endl;
    }
    else{
        cout << "SMALL_ENDIAN"<<endl;
    }
    return 0;
}
