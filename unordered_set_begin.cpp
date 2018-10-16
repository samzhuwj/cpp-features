#include <iostream>
#include <unordered_set>

struct Point { double x, y; };

int main()
{
  Point pts[3] = {{1,0}, {2,0}, {3,0}};
  std::unordered_set<Point*> points = {pts, pts+1, pts+2}; // points is a set containing the addresses of points

  for (auto iter=points.begin(); iter!=points.end(); ++iter) // change each y-coordinate of (i,0) from 0 into i^2 and print the point
  {
    (*iter)->y = ((*iter)->x) * ((*iter)->x); // iter is a pointer-to-Point*
    std::cout << "(" << (*iter)->x << ", " << (*iter)->y << ") ";
  }

  std::cout << '\n';

  for (Point* i : points) // using the range-based for loop, we increase each y-coordinate by 10
  {
    i->y += 10;
    std::cout << "(" << i->x << ", " << i->y << ") ";
  }
}

// Possible output:
// (3, 9) (2, 4) (1, 1)
// (3, 19) (2, 14) (1, 11)
