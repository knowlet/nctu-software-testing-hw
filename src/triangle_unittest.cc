#include "triangle.h"
#include "gtest/gtest.h"

namespace {
TEST(BoundaryValue, Normal)
{
    Triangle t;
    // minimum (min)
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(NOM, NOM, MIN));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(NOM, MIN, NOM));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN, NOM, NOM));
    // just above the minimum (min+)
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(NOM, NOM, MIN + 1));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(NOM, MIN + 1, NOM));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN + 1, NOM, NOM));
    // a nominal value (nom)
    EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(NOM, NOM, NOM));
    // just below their maximum (max-) 
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(NOM, NOM, MAX - 1));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(NOM, MAX - 1, NOM));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MAX - 1, NOM, NOM));
    // at their maximum (max)
    EXPECT_THROW(t.IsATriangle(NOM, NOM, MAX), TriangleException);
    EXPECT_THROW(t.IsATriangle(NOM, MAX, NOM), TriangleException);
    EXPECT_THROW(t.IsATriangle(MAX, NOM, NOM), TriangleException);
}

TEST(BoundaryValue, Robust)
{
    Triangle t;
    // min-
    EXPECT_THROW(t.IsATriangle(NOM, NOM, MIN - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(NOM, MIN - 1, NOM), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN - 1, NOM, NOM), TriangleException);
    // max+
    EXPECT_THROW(t.IsATriangle(NOM, NOM, MAX + 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(NOM, MAX + 1, NOM), TriangleException);
    EXPECT_THROW(t.IsATriangle(MAX + 1, NOM, NOM), TriangleException);
}

TEST(BoundaryValue, WorstCase)
{
    Triangle t;
    // minimum (min)
    EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(MIN, MIN, MIN));
    EXPECT_THROW(t.IsATriangle(MIN, MIN, MIN + 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MIN, NOM), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MIN, MAX - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MIN, MAX), TriangleException);
    // just above the minimum (min+)
    EXPECT_THROW(t.IsATriangle(MIN, MIN + 1, MIN), TriangleException);
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN, MIN + 1, MIN + 1));
    EXPECT_THROW(t.IsATriangle(MIN, MIN + 1, NOM), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MIN + 1, MAX - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MIN + 1, MAX), TriangleException);
    // a nominal value (nom)
    EXPECT_THROW(t.IsATriangle(MIN, NOM, MIN), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, NOM, MIN + 1), TriangleException);
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN, NOM, NOM));
    EXPECT_THROW(t.IsATriangle(MIN, NOM, MAX - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, NOM, MAX), TriangleException);
    // just below their maximum (max-) 
    EXPECT_THROW(t.IsATriangle(MIN, MAX - 1 + 1, MIN), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MAX - 1 + 1, MIN + 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MAX - 1 + 1, NOM), TriangleException);
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN, MAX - 1, MAX - 1));
    EXPECT_THROW(t.IsATriangle(MIN, MAX - 1, MAX), TriangleException);
    // at their maximum (max)
    EXPECT_THROW(t.IsATriangle(MIN, MAX, MIN), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MAX, MIN + 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MAX, NOM), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN, MAX, MAX - 1), TriangleException);
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN, MAX, MAX));
}

TEST(BoundaryValue, SpecialValue)
{
    Triangle t;

    EXPECT_THROW(t.IsATriangle(5, 5, 10), TriangleException);
    EXPECT_EQ(TriangleType::SCALENE, t.IsATriangle(6, 8, 10));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(7, 7, 10));
    EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(10, 10, 10));
}

TEST(EquivalenceClass, WeakNormal)
{
    Triangle t;
    EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(5, 5, 5));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(2, 2, 3));
    EXPECT_EQ(TriangleType::SCALENE, t.IsATriangle(3, 4, 5));
    EXPECT_THROW(t.IsATriangle(4, 1, 2), TriangleException);
}

TEST(EquivalenceClass, WeakRobust)
{
    Triangle t;
    EXPECT_THROW(t.IsATriangle(-1, 5, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, -1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, 5, -1), TriangleException);
    EXPECT_THROW(t.IsATriangle(201, 5, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, 201, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, 5, 201), TriangleException);
}

TEST(EquivalenceClass, StrongRobust)
{
    Triangle t;
    EXPECT_THROW(t.IsATriangle(-1, 5, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, -1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, 5, -1), TriangleException);

    EXPECT_THROW(t.IsATriangle(-1, -1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, -1, -1), TriangleException);
    EXPECT_THROW(t.IsATriangle(-1, 5, -1), TriangleException);
    EXPECT_THROW(t.IsATriangle(-1, -1, -1), TriangleException);
}

TEST(EdgeTesting, WeakNormal)
{
    Triangle t;
    // minimum (min)
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(5, 5, MIN));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(5, MIN, 5));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN, 5, 5));
    // just above the minimum (min+)
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(5, 5, MIN + 1));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(5, MIN + 1, 5));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(MIN + 1, 5, 5));
    // a nominal value (nom)
    EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(5, 5, 5));
    // just below their maximum (max-) 
    EXPECT_THROW(t.IsATriangle(5, 5, MAX - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, MAX - 1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(MAX - 1, 5, 5), TriangleException);
    // at their maximum (max)
    EXPECT_THROW(t.IsATriangle(5, 5, MAX), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, MAX, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(MAX, 5, 5), TriangleException);
}

TEST(EdgeTesting, WeakRobust)
{
    Triangle t;
    // min-
    EXPECT_THROW(t.IsATriangle(5, 5, MIN - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, MIN - 1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN - 1, 5, 5), TriangleException);
    // max+
    EXPECT_THROW(t.IsATriangle(5, 5, MAX + 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, MAX + 1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(MAX + 1, 5, 5), TriangleException);
}

TEST(EdgeTesting, StrongRobust)
{
    Triangle t;
    // min-
    EXPECT_THROW(t.IsATriangle(5, 5, MIN - 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, MIN - 1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(MIN - 1, 5, 5), TriangleException);
    // max+
    EXPECT_THROW(t.IsATriangle(5, 5, MAX + 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(5, MAX + 1, 5), TriangleException);
    EXPECT_THROW(t.IsATriangle(MAX + 1, 5, 5), TriangleException);
}

TEST(Decision, TableBased)
{
    Triangle t;
    // a1:Not a triangle
    EXPECT_THROW(t.IsATriangle(5, 4, 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(4, 5, 1), TriangleException);
    EXPECT_THROW(t.IsATriangle(1, 4, 5), TriangleException);
    // a4:Equilateral
    EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(5, 5, 5));
    // a3:Isosceles
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(5, 5, 2));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(5, 2, 5));
    EXPECT_EQ(TriangleType::ISOSCELES, t.IsATriangle(2, 5, 5));
    // a2:Scalene
    EXPECT_EQ(TriangleType::SCALENE, t.IsATriangle(5, 4, 3));
}
TEST(ExceptionTest, ShouldThrowErr)
{
    Triangle t;
    try {
        EXPECT_EQ(TriangleType::EQUILATERAL, t.IsATriangle(-1, -1, -1));
    }
    catch(TriangleException& e) {
        EXPECT_STREQ(ERRMSG, e.what());
        // std::cout << e.what() << std::endl;
    }
}
}  // namespace
