#include "Consumer.h"

Consumer::Consumer(int elementsToConsume)
  : elementsToConsume(elementsToConsume)
{
}

void Consumer::consume(containers::Stack<int>& stack)
{
    while (elementsToConsume > 0) {
        try {
            elements.push_back(stack.pop());
            --elementsToConsume;
        }
        catch (const std::out_of_range&) {
            ++missedConsumes;
        }
    }
}

std::vector<int> Consumer::getConsumedElements() const
{
    return elements;
}

int Consumer::getMissedConsumes() const
{
    return missedConsumes;
}
