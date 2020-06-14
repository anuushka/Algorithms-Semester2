#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

struct Point
{
    int x;
    int y;
};

Point *arr;
double *key;

float minKey(int &n)
{
    int min = INT_MAX;
    int min_index;
    for(int i = 1; i < n; i++)
        if(key[i] < min && key[i])
        {
            min = key[i];
            min_index = i;
        }
    return min_index;
}

bool mstSet(int &n)
{
    for(int i = 1; i < n; i++)  
	{
		 if(key[i])    
		 return false;
	} 
    return true;
}

double distance(Point a, Point b)
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
int main()
{
    int n;
    cin >> n;
    n++;
    arr = new Point[n];
    key = new double[n];

    for(int i = 1; i < n; i++)
    {
    	int x, y;
        cin >> x >> y;
        arr[i].x = x;
        arr[i].y = y;
        key[i] = INT32_MAX;
    }
  
    double result = 0;
    int v;
    while(!mstSet(n))
    {
        if (key[1])
        {
            key[1] = 0;
            v = 1;
        }
        else
        {
            v = minKey(n);
            result += sqrt(key[v]);
            key[v] = 0;
        }
        for(int u = 1; u < n; u++)
        {
            if(key[u] && u != v && key[u] > distance(arr[v], arr[u]))
            {
                key[u] = distance(arr[v], arr[u]);
            }
        }
    }
    cout << setprecision(9) << result;
    return 0;
}
