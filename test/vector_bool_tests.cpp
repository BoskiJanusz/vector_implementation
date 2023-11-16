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
    for(size_t i = 0; i < 64; i++){
        v.push_back(a);
    }
    auto value = v[63];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, ArrayOfTwoElementsSecondBitOfFirstElementIsEqualOneTest) {
    my::vector<bool> v{};
    bool a = 1;
    for(size_t i = 0; i < 65; i++){
        v.push_back(a);
    }
    auto value = v[64];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, ArrayOfTwoElementsSecondBitOfSecondElementIsEqualZeroTest) {
    my::vector<bool> v{};
    bool a = 1;
    for(size_t i = 0; i < 65; i++){
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
