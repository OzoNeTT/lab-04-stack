// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <Stack.hpp>

TEST(Stack, simple)
{
    Stack<int> st;
    st.push(10);
    EXPECT_EQ(st.head(), 10);
    st.push_emplace(1);
    st.push_emplace(2);
    st.push_emplace(3);
    EXPECT_EQ(st.head(), 3);
    st.push_emplace(4);
    EXPECT_EQ(st.head(), 4);
    st.push_emplace(5);
    EXPECT_EQ(st.head(), 5);
    st.pop();
    EXPECT_EQ(st.head(), 4);
    st.pop();
    EXPECT_EQ(st.head(), 3);
    st.pop();
    EXPECT_EQ(st.head(), 2);

}

