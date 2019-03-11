//
// Created by stevlulz on 3/8/19.
//

#include <gtest/gtest.h>

int add(int a, int b){
    return a+b;
}
TEST(blabla,blabla1){
    ASSERT_EQ(1,add(1,0));
}