#include<bits/stdc++.h>
using namespace std;

class A
{
private:
    string firstName;
    string secondName;
public:
    A();
    void setName(string str1, string str2);
    friend void display(A &a);
};
A::A(){}
void A::setName(string str1, string str2)
{
    firstName = str1;
    secondName = str2;
}
void display(A &a)
{
    cout << a.firstName << " " << a.secondName << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    A a;
    a.setName("Avinash", "patel");
    display(a);
    return 0;
}
