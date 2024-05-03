#pragma once
#include "PriorityQueueMax.h"
#include "MaxHeap.h"
#include <vector>

class PriorityQueueHeap : public PriorityQueueMax
{
private:
    std::vector<Element> _heap;
    int _size;

    int parentOf(int index);
    int leftChildOf(int index);
    int rightChildOf(int index);
    void heapifyUp(int index);
    void heapifyDown(int index);
    int indexOfElement(int index, int priority);
public:
    PriorityQueueHeap();
    ~PriorityQueueHeap();

    void Insert(int value, int priority) override;
    Element ExtractMax() override;
    Element& Peek() override;
    void ModifyKey(int oldPriority, int newPriority) override;
    bool isEmpty() const override;
    int GetSize() const override;
    void PrintAll();
};

