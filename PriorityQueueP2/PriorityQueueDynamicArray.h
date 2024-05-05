#pragma once

#include "PriorityQueueMax.h"
#include <vector>

class PriorityQueueDynamicArray : public PriorityQueueMax
{
private:
    std::vector<Element> _queue;
    int _size;

    void binary_search(int priority, int* firstBigger, int* lastLower, int* foundIndex);
public:
    PriorityQueueDynamicArray();
    ~PriorityQueueDynamicArray();

    void Insert(int value, int priority) override;
    Element ExtractMax() override;
    Element& Peek() override;
    void ModifyKey(int oldPriority, int newPriority) override;
    bool isEmpty() const override;
    int GetSize() const override;
    void PrintAll() const;
    void Clear() override;
};