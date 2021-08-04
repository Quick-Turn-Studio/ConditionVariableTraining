#pragma once

#include <Stack.h>

class Producer
{
public:
    explicit Producer(int elementToProduce);

    void produce(containers::Stack<int>& stack);
    int getElementsCountToProduce() const;

private:
    int elementsToProduce = 0;
};
