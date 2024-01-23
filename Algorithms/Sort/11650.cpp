#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
    int y;
    int x;
} Point;

bool compare(const Point &point1,const Point &point2)
{
    if(point1.x<point2.x)
        return true;
    else if(point1.x==point2.x)
    {
        if(point1.y<point2.y)
            return true;
    }
    return false;
}

int main(void)  
{
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    sort(points.begin(), points.end(), compare);
    for (int i = 0; i < n;i++){
        printf("%d %d\n", points[i].x, points[i].y);
    }
}