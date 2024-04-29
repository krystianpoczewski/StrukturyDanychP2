#include "PriorityQueueHeap.h"
#include <iostream>


PriorityQueueHeap::PriorityQueueHeap()
{
    _size = 0;
}

PriorityQueueHeap::~PriorityQueueHeap()
{

}

void PriorityQueueHeap::Insert(int value, int priority)
{

}

Element PriorityQueueHeap::ExtractMax()
{
    throw std::runtime_error::runtime_error("Heap is empty!");
}

Element& PriorityQueueHeap::Peek()
{
    throw std::runtime_error::runtime_error("Heap is empty!");
}

void PriorityQueueHeap::ModifyKey(int oldPriority, int newPriority)
{

}

bool PriorityQueueHeap::isEmpty() const
{
    return _size == 0;
}

int PriorityQueueHeap::GetSize() const
{
    return _size;
}

void PriorityQueueHeap::PrintAll() const
{

}
