#include<bits/stdc++.h>
using namespace std;

class A
{
private:
    int x;
public:
    A():x(14){}
    friend class B;
};
class B
{
private:
    int b;
public:
    B();
        void show(A &a){
            cout << a.x << endl;
        }
};
B::B(){}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    A a;
    B b;
    b.show(a);
    return 0;
}
