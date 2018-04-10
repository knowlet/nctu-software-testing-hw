#include "triangle.h"

TriangleType Triangle::IsATriangle(int a, int b, int c)
{
    if (a < MIN || b < MIN || c < MIN || a > MAX || b > MAX || c > MAX)
        throw TriangleException();
    if (a + b <= c || b + c <= a || a + c <= b)
        throw TriangleException();
    else if (a == b && a == c)
        return TriangleType::EQUILATERAL;
    else if ((a == b && b != c) || (a == c && a != b) || (b == c && a != b))
        return TriangleType::ISOSCELES;
    else
        return TriangleType::SCALENE;
}