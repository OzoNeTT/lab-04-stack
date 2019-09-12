// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <Stack.hpp>

TEST(Stack, simple)
{
    Stack<int> st;
    st.push(14);
    EXPECT_EQ(st.head(), 14);
    st.push(11);
    EXPECT_EQ(st.head(), 11);
    st.pop();
    EXPECT_EQ(st.head(), 14);

}