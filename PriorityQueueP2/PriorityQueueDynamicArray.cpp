#include "PriorityQueueDynamicArray.h"
#include <iostream>



void PriorityQueueDynamicArray::binary_search(int priority, int* firstBigger, int* lastLower, int* foundIndex)
{
	int low = 0;
	int high = _size - 1;
	*firstBigger = -1;
	*lastLower = -1;
	*foundIndex = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (_queue[mid].priority == priority) {
			int i = mid;
			int j = mid;
			while (i >= 0 && _queue[i].priority == _queue[mid].priority) {
				*lastLower = --i;
			}
			while (j < _size && _queue[j].priority == _queue[mid].priority) {
				*firstBigger = ++j;
			}
			*foundIndex = *firstBigger - 1;
			return;
		}
		else if (_queue[mid].priority < priority) {
			low = mid + 1;
			*lastLower = mid;
		}
		else {
			high = mid - 1;
			*firstBigger = mid;
		}
	}
}

PriorityQueueDynamicArray::PriorityQueueDynamicArray()
{
	_size = 0;
}

PriorityQueueDynamicArray::~PriorityQueueDynamicArray()
{

}

void PriorityQueueDynamicArray::Insert(int value, int priority)
{
	Element elementToInsert(value, priority);

	int firstBigger, lastLower, foundIndex;
	binary_search(priority, &firstBigger, &lastLower, &foundIndex);
	_queue.insert(_queue.begin() + ++lastLower, elementToInsert);
	_size++;
}

Element PriorityQueueDynamicArray::ExtractMax()
{
	if (isEmpty()) {
		throw std::out_of_range("The priority queue is empty");
	}
	//Usuniecie ostatniego elementu i zwrocenie jego wartosci
	Element elementExtracted = _queue[_size - 1];
	_queue.pop_back();
	_size--;
	return elementExtracted;
}

Element& PriorityQueueDynamicArray::Peek()
{
	if (isEmpty()) {
		throw std::out_of_range("The priority queue is empty");
	}
	return _queue[_size - 1];
}

void PriorityQueueDynamicArray::ModifyKey(int oldPriority, int newPriority)
{
	if (isEmpty()) {
		std::cout << "The priority queue is empty" << std::endl;
		return;
	}
	if (newPriority == oldPriority) {
		std::cout << "New priority is equal to old priority. No change needed." << std::endl;
		return;
	}
	int firstBiggerOld, lastLowerOld, foundIndexOld;
	binary_search(oldPriority, &firstBiggerOld, &lastLowerOld, &foundIndexOld);
	if (foundIndexOld == -1) {
		std::cout << "Unable to find element with specified priority" << std::endl;
		return;
	}
	int valueToInsert = _queue[foundIndexOld].value;
	_queue.erase(_queue.begin() + foundIndexOld);
	_size--;
	Insert(valueToInsert, newPriority);

}

bool PriorityQueueDynamicArray::isEmpty() const
{
	return _size == 0;
}

int PriorityQueueDynamicArray::GetSize() const
{
	return _size;
}

void PriorityQueueDynamicArray::PrintAll() const
{
	if (isEmpty()) {
		std::cout << "Can't print an empty priority queue" << std::endl;
		return;
	}
	for (Element el : _queue) {
		std::cout << "Priority: " << el.priority << ", Value: " << el.value << std::endl;
	}
}

void PriorityQueueDynamicArray::Clear()
{
	_queue.clear();
	_size = 0;
}
