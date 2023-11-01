#include <gtest/gtest.h>
#include <string>
#include "../src/vector.hpp"

TEST(VectorTest, IntOneValueIntoVectorTest){
    my::vector<int> v{};
    int a = 5;
    v.push_back(a);
    auto value = v[0];
    auto expected = 5;
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntThreeValueIntoVectorTest){
    my::vector<int> v{};
    int a = 5;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    auto value = v[2];
    auto expected = 5;
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharOneValueIntoVectorTest){
    my::vector<char> v{};
    char c = 't';
    v.push_back(c);
    auto value = v[0];
    auto expected = 't';
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharThreeValueIntoVectorTest){
    my::vector<char> v{};
    char c = 't';
    v.push_back(c);
    v.push_back(c);
    v.push_back(c);
    auto value = v[2];
    auto expected = 't';
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringOneValueIntoVectorTest){
    my::vector<std::string> v{};
    std::string str{"test"};
    v.push_back(str);
    auto value = v[0];
    auto expected = "test";
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringThreeValueIntoVectorTest){
    my::vector<std::string> v{};
    std::string str{"test"};
    v.push_back(str);
    v.push_back(str);
    v.push_back(str);
    auto value = v[2];
    auto expected = "test";
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntCopyConstructorTest){
    int a{5};
    my::vector<int> vector{a};
    auto copiedVector {vector};
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharCopyConstructorTest){
    char c = 'c';
    my::vector<char> vector{c};
    auto copiedVector {vector};
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringCopyConstructorTest){
    std::string str{"test"};
    my::vector<std::string> vector{str};
    auto copiedVector {vector};
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntCopyAssignmentOperatorOneAssignEmptyToEmptyIsNotEqualVectorTest){
    my::vector<int> vector{};
    my::vector<int> copiedVector{};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_NE(value, expected);
}

TEST(VectorTest, IntCopyAssignmentOperatorOneAssignToItselfVectorTest){
    my::vector<int> vector{};
    vector = vector;
    auto value = vector[0];
    auto expected = vector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntCopyAssignmentOperatorOneAssignEmptyVectorTest){
    int a{5};
    my::vector<int> vector{a};
    my::vector<int> copiedVector{};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntCopyAssignmentOperatorOneAssignNonEmptyVectorTest){
    int a{5}, b{6};
    my::vector<int> vector{a};
    my::vector<int> copiedVector{b};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharCopyAssignmentOperatorOneAssignEmptyToEmptyIsNotEqualVectorTest){
    my::vector<char> vector{};
    my::vector<char> copiedVector{};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_NE(value, expected);
}

TEST(VectorTest, CharCopyAssignmentOperatorOneAssignToItselfVectorTest){
    my::vector<char> vector{};
    vector = vector;
    auto value = vector[0];
    auto expected = vector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharCopyAssignmentOperatorOneAssignEmptyVectorTest){
    char c = 'c';
    my::vector<char> vector{c};
    my::vector<char> copiedVector{};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharCopyAssignmentOperatorOneAssignNonEmptyVectorTest){
    char c = 'c', d = 'd';
    my::vector<char> vector{c};
    my::vector<char> copiedVector{d};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringCopyAssignmentOperatorOneAssignEmptyToEmptyIsEqualVectorTest){
    my::vector<std::string> vector{};
    my::vector<std::string> copiedVector{};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringCopyAssignmentOperatorOneAssignToItselfVectorTest){
    my::vector<std::string> vector{};
    vector = vector;
    auto value = vector[0];
    auto expected = vector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringCopyAssignmentOperatorOneAssignEmptyVectorTest){
    std::string str{"test"};
    my::vector<std::string> vector{str};
    my::vector<std::string> copiedVector{};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringCopyAssignmentOperatorOneAssignNonEmptyVectorTest){
    std::string str1{"test1"}, str2{"test2"};
    my::vector<std::string> vector{str1};
    my::vector<std::string> copiedVector{str2};
    copiedVector = vector;
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntMoveConstructorTest){
    int a{5};
    my::vector<int> vector{a};
    auto copiedVector {std::move(vector)};
    auto value = 5;
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharMoveConstructorTest){
    char c = 'c';
    my::vector<char> vector{c};
    auto copiedVector {std::move(vector)};
    auto value = 'c';
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringMoveConstructorTest){
    std::string str{"test"};
    my::vector<std::string> vector{str};
    auto copiedVector {std::move(vector)};
    auto value = "test";
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}
