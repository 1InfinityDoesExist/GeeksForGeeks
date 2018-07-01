
#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
private:
    int capacity;
protected:
    vector<int> v;
    map<int, int> mp;
public:
    LRUCache(int );

    int get(int );

    void set(int , int );
};

 LRUCache::LRUCache(int capacity){
        this->capacity = capacity;
    }

int LRUCache::get(int key)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), key);
        if(iter != v.end())
        {
            int sk = *iter;
            v.erase(iter);
            v.push_back(sk);
            return mp[key];
        }
        else
        {
            return -1;
        }

    }

void LRUCache::set(int key, int value)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), key);
    if(iter == v.end())
    {
        if(v.size() == capacity)
        {
            vector<int>::iterator jter = v.begin();
            v.erase(jter);
        }
        v.push_back(key);
        mp[key] = value;
        }
        else
        {
            if(value != mp[key]){
                mp[key] = value;
            }
            int sk = *iter;
            v.erase(iter);
            v.push_back(sk);
        }
    }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
