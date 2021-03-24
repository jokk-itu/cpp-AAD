#include "../../src/Helpers/Point2D.h"
#include "gtest/gtest.h"

TEST(Point2D_Tests, Point2D_LessThan_ExpectTrue) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_TRUE(point < point1);
}

TEST(Point2D_Tests, Point2D_LessThan_ExpectFalse) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_FALSE(point1 < point);
}

TEST(Point2D_Tests, Point2D_LargerThan_ExpectTrue) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_TRUE(point1 > point);
}

TEST(Point2D_Tests, Point2D_LargerThan_ExpectFalse) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_FALSE(point > point1);
}

TEST(Point2D_Tests, Point2D_Equals_ExpectTrue) {
    Point2D point(3, 3);
    Point2D point1(3, 3);
    EXPECT_TRUE(point == point1);
}

TEST(Point2D_Tests, Point2D_Equals_ExpectFalse) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_FALSE(point == point1);
}

TEST(Point2D_Tests, Point2D_LargerThanOrEqual_ExpectTrue) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_TRUE(point1 >= point);
}

TEST(Point2D_Tests, Point2D_LargerThanOrEqual_ExpectFalse) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_FALSE(point >= point1);
}

TEST(Point2D_Tests, Point2D_LessThanOrEqual_ExpectTrue) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_TRUE(point <= point1);
}

TEST(Point2D_Tests, Point2D_LessThanOrEqual_ExpectFalse) {
    Point2D point(2, 2);
    Point2D point1(3, 3);
    EXPECT_FALSE(point1 <= point);
}