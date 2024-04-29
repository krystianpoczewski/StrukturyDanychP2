#pragma once
#include <vector>
#include "PriorityQueueMax.h"

class MaxHeap
{
private:
	std::vector<Element> _heap;
	int _size;

	int parentOf(int index);
	int leftChildOf(int index);
	int rightChildOf(int index);
	void heapifyUp(int index);
	void heapifyDown(int index);
public:
	MaxHeap();
	~MaxHeap();

	void Insert(int priority, int value);
	Element ExtractMax();
	Element GetMax() const;

	int GetSize() const;
	bool isEmpty() const;

	void PrintAll() const;
};

