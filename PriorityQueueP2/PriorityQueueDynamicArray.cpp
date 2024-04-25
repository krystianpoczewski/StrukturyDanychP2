#include "PriorityQueueDynamicArray.h"
#include <iostream>

void PriorityQueueDynamicArray::IncreaseKey(int oldPriority, int newPriority)
{
	int oldIndex, newIndex = -1;
	for (int i = 0; i < _size; i++) {
		if (newPriority < _queue[i].priority) {
			newIndex = i;
		}
		if (oldPriority == _queue[i].priority) {
			oldIndex = i;
			break;
		}
	}
	if (oldIndex == -1) {
		std::cout << "Unable to find element with this priority";
		return;
	}
	if (newPriority == oldPriority) {
		std::cout << "New priority is equal to old priority. No change needed." << std::endl;
		return;
	}

	Element elementToModify = _queue[oldIndex];
	_queue.erase(_queue.begin() + oldIndex);

	elementToModify.priority = newPriority;

	if (newIndex == -1) {
		_queue.insert(_queue.begin(), elementToModify);
	}
	else {
		_queue.insert(_queue.begin() + newIndex, elementToModify);
	}
}

void PriorityQueueDynamicArray::DecreaseKey(int oldPriority, int newPriority)
{
	int oldIndex = -1;
	int newIndex = -1;
	for (int i = 0; i < _size; i++) {
		if (newPriority < _queue[i].priority) {
			newIndex = i;
			break;
		}
		if (oldPriority == _queue[i].priority) {
			oldIndex = i;
		}
	}
	if (oldIndex == -1) {
		std::cout << "Unable to find element with this priority";
		return;
	}


	Element elementToModify = _queue[oldIndex];
	_queue.erase(_queue.begin() + oldIndex);

	elementToModify.priority = newPriority;

	if (newIndex == -1) {
		_queue.insert(_queue.begin(), elementToModify);
	}
	else {
		_queue.insert(_queue.begin() + newIndex, elementToModify);
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

	//Przejscie przez elementy tablicy dynamicznej i dodanie na odpowiednia pozycje
	for (int i = 0; i < _size; i++) {
		if (_queue[i].priority < priority) {
			_queue.insert(_queue.begin() + i, elementToInsert);
			_size++;
			return;
		}
	}
	//Jezeli priorytet jest mniejszy niz pozostale w tablicy dynamicznej dodaj na koniec
	//Jezeli kolejka priorytetowa jest puta to tez dodaj na koniec, poniewaz nie wykonuje petli
	_queue.push_back(elementToInsert);
	_size++;
}

Element PriorityQueueDynamicArray::ExtractMax()
{
	if (isEmpty()) {
		std::cout << "The priority queue is empty" << std::endl;
		Element wrongElement(-1, -1);
		return wrongElement;
	}
	Element elementExtracted = _queue[0];
	_queue.erase(_queue.begin());
	_size--;
	return elementExtracted;
}

Element& PriorityQueueDynamicArray::Peek()
{
	if (isEmpty()) {
		std::cout << "The priority queue is empty" << std::endl;
		Element wrongElement(-1, -1);
		return wrongElement;
	}
	return _queue[0];
}

void PriorityQueueDynamicArray::ModifyKey(int oldPriority, int newPriority)
{
	if (newPriority == oldPriority) {
		std::cout << "New priority is equal to old priority. No change needed." << std::endl;
		return;
	}

	if (oldPriority < newPriority)
		IncreaseKey(oldPriority, newPriority);
	else if (oldPriority > newPriority)
		DecreaseKey(oldPriority, newPriority);
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
