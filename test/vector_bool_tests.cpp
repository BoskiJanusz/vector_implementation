#include <gtest/gtest.h>
#include <string>
#include "../src/vector.hpp"

TEST(VectorBoolTest, OneTrueValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto value = v[0];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, OneFalseValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 0;
    v.push_back(a);
    auto value = v[0];
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, FourTrueValuesIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    auto value = v[3];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, FourTrueValuesIntoVectorFifthIsEqualZeroTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    auto value = v[4];
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, FillOneTableWithValuesLastBitIsEqualOneTest) {
    my::vector<bool> v{};
    bool a = 1;
    for (size_t i = 0; i < 64; i++) {
        v.push_back(a);
    }
    auto value = v[63];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, ArrayOfTwoElementsSecondBitOfFirstElementIsEqualOneTest) {
    my::vector<bool> v{};
    bool a = 1;
    for (size_t i = 0; i < 65; i++) {
        v.push_back(a);
    }
    auto value = v[64];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, ArrayOfTwoElementsSecondBitOfSecondElementIsEqualZeroTest) {
    my::vector<bool> v{};
    bool a = 1;
    for (size_t i = 0; i < 65; i++) {
        v.push_back(a);
    }
    auto value = v[65];
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, ReferenceOfABitVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    v[0] = 0;
    auto value = v[0];
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, ReferenceOfAFourBitsVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v[3] = 0;
    auto value = v[3];
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, InitializetedByValueCopyConstructorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto copiedVector{v};
    auto value = v[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, NotInitializetedByValueCopyConstructorTest) {
    my::vector<bool> v{};
    auto copiedVector{v};
    auto value = v[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, OneTrueValueIntoVectorConstructorTest) {
    my::vector<bool> v{1};
    auto value = v[0];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MoveOneValueConstructorTest) {
    my::vector<bool> vector{1};
    auto copiedVector{std::move(vector)};
    auto value = true;
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, OneVectorValueCopiedToAnotherVectorCopyAssignmentOperatorTest) {
    bool v1 = 1, v2 = 0;
    my::vector<bool> trueVector{v1};
    my::vector<bool> falseVector{v2};
    falseVector = trueVector;
    auto value = falseVector[0];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, OneVectorValueMovedToAnotherVectorMoveAssignmentOperatorTest) {
    bool v1 = 1, v2 = 0;
    my::vector<bool> trueVector{v1};
    my::vector<bool> falseVector{v2};
    falseVector = std::move(trueVector);
    auto value = falseVector[0];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodAtOneTrueValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto value = v.at(0);
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodOneFalseValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 0;
    v.push_back(a);
    auto value = v.at(0);
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodFourTrueValuesIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    auto value = v.at(3);
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, OutOfRangeVectorTest) {
    my::vector<bool> v{};
    bool a = 0;
    v.push_back(a);
    ASSERT_THROW(v.at(1), std::out_of_range);
}

TEST(VectorBoolTest, MethodFrontOneTrueValueVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto value = v.front();
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodFrontOneFalseValueVectorTest) {
    my::vector<bool> v{};
    bool a = 0;
    v.push_back(a);
    auto value = v.front();
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodFrontFourValuesVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    bool b = 0;
    v.push_back(a);
    v.push_back(b);
    v.push_back(b);
    v.push_back(b);
    auto value = v.front();
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodBackOneTrueValueVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto value = v.back();
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodBackOneFalseValueVectorTest) {
    my::vector<bool> v{};
    bool a = 0;
    v.push_back(a);
    auto value = v.back();
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, MethodBackFourValuesVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    bool b = 0;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v.push_back(b);
    auto value = v.back();
    auto expected = false;
    EXPECT_EQ(value, expected);
}