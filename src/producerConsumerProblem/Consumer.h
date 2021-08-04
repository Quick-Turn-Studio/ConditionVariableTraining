#pragma once

#include <Stack.h>
#include <vector>

class Consumer
{
public:
    explicit Consumer(int elementsToConsume);
    void consume(containers::Stack<int>& stack);
    std::vector<int> getConsumedElements() const;
    int getMissedConsumes() const;

private:
    std::vector<int> elements;
    int elementsToConsume = 0;
    int missedConsumes = 0;
};
