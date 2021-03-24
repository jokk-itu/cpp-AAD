#include "../../src/Helpers/BoundingBox.h"
#include "gtest/gtest.h"

TEST(BoundingBox_Tests, Test_GetMid_ExpectEqual_UnevenPoint) {
    BoundingBox box(Point2D(0,5), Point2D(5,0));
    EXPECT_EQ(box.getMid(), Point2D(2.5F, 2.5F));
}

TEST(BoundingBox_Tests, Test_GetMid_ExpectEqual_EvenPoint) {
    BoundingBox box(Point2D(0,4), Point2D(4,0));
    EXPECT_EQ(box.getMid(), Point2D(2,2));
}

TEST(BoundingBox_Tests, Test_IsIntersecting_ExpectTrue) {
    BoundingBox box(Point2D(0,2), Point2D(2,0));
    BoundingBox box1(Point2D(1,5), Point2D(5,1));
    EXPECT_TRUE(box.isIntersecting(box1));
}

TEST(BoundingBox_Tests, Test_IsIntersecting_ExpectFalse) {
    BoundingBox box(Point2D(0,2), Point2D(2,0));
    BoundingBox box1(Point2D(3,5), Point2D(5,3));
    EXPECT_FALSE(box.isIntersecting(box1));
}

TEST(BoundingBox_Tests, Test_IsWithinBox_ExpectTrue) {
    BoundingBox box(Point2D(0,2), Point2D(2,0));
    Point2D point(1,1);
    EXPECT_TRUE(box.isWithinBox(point));
}

TEST(BoundingBox_Tests, Test_IsWithinBox_ExpectFalse) {
    BoundingBox box(Point2D(0,2), Point2D(2,0));
    Point2D point(3,3);
    EXPECT_FALSE(box.isWithinBox(point));
}