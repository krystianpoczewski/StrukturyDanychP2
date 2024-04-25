#pragma once

#include "PriorityQueueMax.h"
#include <vector>

class PriorityQueueDynamicArray : public PriorityQueueMax
{
private:
    std::vector<Element> _queue;
    int _size;

    void IncreaseKey(int oldPriority, int newPriority) override;
    void DecreaseKey(int oldPriority, int newPriority) override;
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
};