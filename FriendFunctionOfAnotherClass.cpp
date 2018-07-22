#include<bits/stdc++.h>
using namespace std;
class B;
class A
{
private:
    string myName;
public:
    A();
    void display(B &b);
};
A::A(){
    myName = "Tess Mar Khan";
}
class B
{
private:
    int b;
public:
    B():b(0){}
    friend void A::display(B &x);
};
void A::display(B &x)
{
    cout << "The value of b is :- " << x.b <<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    A a;
    B b;
    a.display(b);
    return 0;
}
