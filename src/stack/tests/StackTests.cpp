#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <Stack.h>

namespace containers::tests
{

using namespace testing;

TEST(StackTest, DefaultConstructorCreateEmptyStack)
{
    // given:

    // when:
    Stack<int> stack;

    // expected:
    EXPECT_THAT(stack.isEmpty(), Eq(true));
}

TEST(StackTest, EmptyInitializerListConstructorCreateEmptyStack)
{
    // given:

    // when:
    Stack<int> stack = {};

    // expected:
    EXPECT_THAT(stack.isEmpty(), Eq(true));
}

TEST(StackTest, InitializerListConstructorAddAllElements)
{
    // given:

    // when:
    Stack<int> stack = {1, 2, 3, 5, 5};

    // expected:
    ASSERT_THAT(stack.size(), Eq(5));
}

TEST(StackTest, PopingElementReturnLastPushedElementAndDecreaseSize)
{
    // given:
    constexpr auto addedValue = 10;
    Stack<int> stack = {5, 32};
    stack.push(addedValue);

    // when:
    const auto popValue = stack.pop();
    const auto sizeAfterPop = stack.size();

    // expected:
    EXPECT_THAT(popValue, Eq(addedValue));
    EXPECT_THAT(sizeAfterPop, Eq(2));
}

}
