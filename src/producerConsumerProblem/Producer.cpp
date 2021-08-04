#include "Producer.h"

Producer::Producer(int elementToProduce)
  : elementsToProduce(elementToProduce)
{
}

void Producer::produce(containers::Stack<int>& stack)
{
    stack.push(--elementsToProduce);
}

int Producer::getElementsCountToProduce() const
{
    return elementsToProduce;
}