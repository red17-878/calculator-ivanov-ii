//
// Created by sr9000 on 2/22/25.
//

#include <gtest/gtest.h>

extern "C" {
// yep, not using header just because its simplier to declare than provide correct headers
int a_plus_b(int a, int b);
}

TEST(ExampleTest, AplusB)
{
    EXPECT_EQ(3, a_plus_b(1, 2));
}
