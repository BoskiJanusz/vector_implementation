#include <gtest/gtest.h>
#include <string>
#include "../src/vector.hpp"

TEST(VectorBoolTest, OneValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto value = v[0];
    std::cout << v[0];
    auto expected = true;
    EXPECT_EQ(value, expected);
}