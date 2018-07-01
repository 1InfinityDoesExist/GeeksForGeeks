int capacity;
vector<int> v;
map<int, int> mp;
LRUCache::LRUCache(int N)
{
     capacity = N;
     v.clear();
     mp.clear();

}
void LRUCache::set(int x, int y)
{
     vector<int>::iterator iter = find(v.begin(), v.end(), x);
     if(iter == v.end())
     {
         if(v.size() == capacity)
         {
             vector<int>::iterator jter = v.begin();
             v.erase(jter);
         }
         v.push_back(x);
         mp[x] = y;
     }
     else
     {
         if(y != mp[x]){
             mp[x] = y;
         }
         int cp = *iter;
         v.erase(iter);
         v.push_back(cp);
     }

}

int LRUCache::get(int x)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), x);
    if(iter != v.end())
    {
        int cp = *iter;
        v.erase(iter);
        v.push_back(cp);
        return mp[cp];
    }
    else
    {
        return -1;
    }
}
