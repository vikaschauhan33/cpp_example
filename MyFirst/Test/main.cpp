//
#include "gtest/gtest.h"
#include "calc.h"

// my first fancy addition test
TEST (MyFirst, Addition)
{
    // equal to 20
    //EXPECT_EQ(addition(10, 10), 20);
    
    // not equal to 20
    //EXPECT_EQ(addition(10, 10), 20);
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}