#pragma once
#include <vector>
#include "PriorityQueueMax.h"

class PriorityQueueHeap : public PriorityQueueMax
{
private:
    std::vector<Element> _queue;
    int _size;


public:
    PriorityQueueHeap();
    ~PriorityQueueHeap();

    void Insert(int value, int priority) override;
    Element ExtractMax() override;
    Element& Peek() override;
    void ModifyKey(int oldPriority, int newPriority) override;
    bool isEmpty() const override;
    int GetSize() const override;
    void PrintAll() const;
};

