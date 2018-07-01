#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
    private:
        int capacity;
    public:
        LRUCache(int cap);
        int solve(list<int> &A);
};

LRUCache::LRUCache(int cap)
{
    this->capacity = cap;
}

int LRUCache::solve(list<int> &A)
{
    int page_fault (0);
    list<int> v;
    for(list<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        list<int>::iterator jter = find(v.begin(), v.end(), *iter);
        if(jter == v.end())
        {
            if(v.size() == capacity)
            {
                list<int>::iterator pter = v.begin();
                v.erase(pter);
            }
            v.push_back(*iter);
            page_fault++;

          /*  for(list<int>::iterator i = v.begin(); i != v.end(); i++)
            {
                cout << *i << " "<< "------>" << page_fault << endl;
            }*/
        //    cout << endl;
        }
        else
        {                 //Hit condition...
            int cp = *iter;
            v.erase(jter);
            v.push_back(cp);
          /*  for(list<int>::iterator i = v.begin(); i != v.end(); i++)
            {
                cout << *i << " ";
            }*/
           // cout << page_fault<<endl;
          //  cout << endl;
        }
    }
    return page_fault;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        list<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int capacity;
        cin >> capacity;
        LRUCache *sol = new LRUCache(capacity);
        int ans = sol->solve(v);
        cout << ans << endl;
    }
    return 0;
}
