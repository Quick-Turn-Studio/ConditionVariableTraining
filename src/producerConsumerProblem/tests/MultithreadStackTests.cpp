#include <Consumer.h>
#include <Producer.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <thread>

#include <Stack.h>

namespace containers::tests
{

using TestedStack = Stack<int>;

using namespace testing;

void producerJob(Producer& producer, TestedStack& stack)
{
    while (producer.getElementsCountToProduce() > 0) {
        producer.produce(stack);
    }
}

void consumerJob(Consumer& consumer, TestedStack& stack)
{
    consumer.consume(stack);
}

TEST(StackTest, ConsumerConsumesSameNumberOfElementsAsProducerProduces)
{
    // given:
//    constexpr auto elementToProduce = 10'000;
    constexpr auto elementToProduce = 10;
    Stack<int> stack;
    auto producer = Producer(elementToProduce);
    auto consumer = Consumer(elementToProduce);

    // when:
    auto producerThread = std::thread(producerJob, std::ref(producer), std::ref(stack));
    auto consumerThread = std::thread(consumerJob, std::ref(consumer), std::ref(stack));

    producerThread.join();
    consumerThread.join();

    // expected:
    const auto elementsLeftCount = stack.size();
    const auto consumedElementsCount = static_cast<int>(consumer.getConsumedElements().size());
    const auto missedConsumptionsCount = consumer.getMissedConsumes();

    EXPECT_THAT(elementsLeftCount, Eq(0));
    EXPECT_THAT(consumedElementsCount, Eq(elementToProduce));
    EXPECT_THAT(missedConsumptionsCount, Eq(0));
}

} // namespace containers::tests
