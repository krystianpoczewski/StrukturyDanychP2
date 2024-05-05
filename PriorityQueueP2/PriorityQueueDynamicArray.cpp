#include "PriorityQueueDynamicArray.h"
#include <iostream>


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
	//Element o najwiekszym priorytecie jest na ostatniej pozycji w vectorze.
	for (int i = 0; i < _size; i++) {
		if (_queue[i].priority >= priority) {
			_queue.insert(_queue.begin() + i, elementToInsert);
			_size++;
			return;
		}
	}
	// Jezeli nie znajdzie priorytety wiekszego/rownego to dodanie na koniec elementu o najwiekszym priorytecie
	_queue.push_back(elementToInsert);
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
	//Zmienne pomocnicze
	int oldIndex = -1;
	int newIndex = -1;
	bool newPriorityBiggerThanOld = newPriority > oldPriority;
	//Petla ktora przechodzi przez wszystkie elementy i zapamietuje indeksy elementow na ktorych ma wykonac operacje
	for (int i = 0; i < _size; i++) {
		if (newPriority > _queue[i].priority) {
			newIndex = i;
		}
		if (oldPriority == _queue[i].priority) {
			oldIndex = i;
		}
		if (oldIndex != -1 && newIndex != -1 || newPriorityBiggerThanOld && oldIndex != -1)
			break;
	}
	if (oldIndex == -1) {
		std::cout << "Unable to find element with this priority";
		return;
	}


	Element elementToModify = _queue[oldIndex];
	_queue.erase(_queue.begin() + oldIndex);

	elementToModify.priority = newPriority;
	if (newPriorityBiggerThanOld) {
		_queue.push_back(elementToModify);
	}
	else if (newIndex == -1) {
		_queue.insert(_queue.begin(), elementToModify);
	}
	else {
		_queue.insert(_queue.begin() + newIndex, elementToModify);
	}
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
