#include "../../src/Spatial/QuadTree.h"
#include "gtest/gtest.h"

TEST(QuadTree_Tests, Test_Insert_Valid_Input_ExpectEqual)
{
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    tree.insert(std::make_pair(Point2D(2,3), 2));
    auto actual = tree.search(BoundingBox(Point2D(1,5), Point2D(5,1)));
    auto expected = std::vector<std::pair<const Point2D, int>> {std::make_pair(Point2D(2,3), 2)};
    EXPECT_EQ(expected, actual);
}

TEST(QuadTree_Tests, Test_Insert_Given_Wrong_Input_Expect_PointNotWithinBoxException)
{
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    EXPECT_THROW(tree.insert(std::make_pair(Point2D(-1,-2), 2)), PointNotWithinBoxException);
}

TEST(QuadTree_Tests, Test_Remove_Given_Valid_Input_ExcpectEqual) {
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    tree.insert(std::make_pair(Point2D(2,3), 2));
    tree.remove(Point2D(2,3));
    auto actual = tree.search(BoundingBox(Point2D(1,5), Point2D(5,1)));
    auto expected = std::vector<std::pair<const Point2D, int>> {};
    EXPECT_EQ(expected, actual);
}

TEST(QuadTree_Tests, Test_Remove_Given_Invalid_Input_ExpectInvalidArgumentException) {
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    tree.insert(std::make_pair(Point2D(2,3), 2));
    EXPECT_THROW(tree.remove(Point2D(3,3)), std::invalid_argument);
}

TEST(QuadTree_Tests, Test_Insert_Updating_Existing_Point_Valid_Input_ExpectEqual)
{
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    tree.insert(std::make_pair(Point2D(2,3), 2));
    tree.insert(std::make_pair(Point2D(2,3), 3));
    auto actual = tree.search(BoundingBox(Point2D(1,5), Point2D(5,1)));
    auto expected = std::vector<std::pair<const Point2D, int>> {std::make_pair(Point2D(2,3), 3)};
    EXPECT_EQ(expected, actual);
}

TEST(QuadTree_Tests, Test_Search_Valid_Input_ExpectEqual) {
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    tree.insert(std::make_pair(Point2D(0,0), 1));
    tree.insert(std::make_pair(Point2D(2,3), 5));
    tree.insert(std::make_pair(Point2D(4,4), 3));
    tree.insert(std::make_pair(Point2D(10,10), 8));
    auto actual = tree.search(BoundingBox(Point2D(1,5), Point2D(5,1)));
    auto expected = std::vector<std::pair<const Point2D, int>> {std::make_pair(Point2D(2,3), 5), std::make_pair(Point2D(4,4), 3)};
    EXPECT_EQ(expected, actual);
}

TEST(QuadTree_Tests, Test_Search_Invalid_Input_Expect_BoxOutOfBoundsException) {
    QuadTree<int> tree(BoundingBox(Point2D(0, 10), Point2D(10, 0)));
    tree.insert(std::make_pair(Point2D(0,0), 1));
    EXPECT_THROW(tree.search(BoundingBox(Point2D(-1,6), Point2D(11,-1))), BoxOutOfBoundsException);
}