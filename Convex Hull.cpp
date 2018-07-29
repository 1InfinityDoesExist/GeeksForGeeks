
#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
};
class Solution
{
    private:
    public:
        Solution();
        void convexHull(vector<Point> points);
};
Solution::Solution(){}
bool comp(Point a, Point b)
{
    return a.x < b.x;
}
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
	{
	    return 0;
	}
	return (val > 0)? 1: 2;
}

void Solution::convexHull(vector<Point> points)
{
    vector<Point> hull;
	int n = points.size();
	if (n < 3)
	{
	    hull.clear();
	    points.clear();
	    cout << "-1" <<endl;
	    return;
	}
	int l = 0;
	for (int i = 1; i < n; i++)
	{
		if(points[i].x < points[l].x)
		{
			l = i;
		}
	}
	int p = l, q;
	do
	{
		hull.push_back(points[p]);
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
		if (orientation(points[p], points[i], points[q]) == 2)
			q = i;
		}
		p = q;
	} while (p != l);

	sort(hull.begin(), hull.end(), comp);
	for (int i = 0; i < hull.size()-1; i++)
	{
	    cout <<  hull[i].x << " "<< hull[i].y << ", ";
	}
	cout <<  hull[hull.size()-1].x << " "<< hull[hull.size()-1].y << " ";
	hull.clear();
	points.clear();
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	Solution sol;
	Point p;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int k, l;
	    vector<Point> vp;
	    for(int iter = 0; iter < n; iter++)
	    {
	        cin >> k >> l;
    	    p.x = k;
    	    p.y = l;
    	    vp.push_back(p);
	    }
	     sol.convexHull(vp);
	     vp.clear();
	     cout << endl;
	}
	return 0;
}
