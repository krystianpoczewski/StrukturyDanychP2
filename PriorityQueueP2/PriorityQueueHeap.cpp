#include "PriorityQueueHeap.h"
#include <iostream>

int PriorityQueueHeap::parentOf(int index)
{
	return index / 2;
}

int PriorityQueueHeap::leftChildOf(int index)
{
	return index * 2;
}

int PriorityQueueHeap::rightChildOf(int index)
{
	return (index * 2) + 1;
}

void PriorityQueueHeap::heapifyUp(int index)
{
	if (index > _size || index < 1)
		return;
	if (index == 1)
		return; //Jest na pozycji 1, nie potrzebna zmiana pozycji

	if (_heap[index].priority > _heap[parentOf(index)].priority) {
		std::swap(_heap[index], _heap[parentOf(index)]);
	}
	heapifyUp(parentOf(index)); //Rekrurencyjne wywolanie funckji aby wszystkie wartosci byly poprawne
	//Wykonywane az do dojscia do pierwszej pozycji
}

void PriorityQueueHeap::heapifyDown(int index)
{
	if (index > _size)
		return;

	int indexToSwap = index; //Zmienna pomocnicza przechowujaca indeks wiekszego dziecka
	if (leftChildOf(index) <= _size && _heap[leftChildOf(index)].priority > _heap[index].priority) {
		indexToSwap = leftChildOf(index); // Jezeli lewe dziecko jest wieksze od rodzica to zmienna ma wartosc indeksu lewego dziecka
	}
	if (rightChildOf(index) <= _size && _heap[rightChildOf(index)].priority > _heap[indexToSwap].priority) {
		indexToSwap = rightChildOf(index); // Jezeli prawe dziecko jest wieksze od lewego dziecka lub rodzica to zmienna pomocnicza ma wartosc indeksu prawego dziecka
	}
	if (indexToSwap != index) {
		// Jezeli rodzic nie jest wiekszy niz jego dzieci to zamien rodzica z wiekszym od niego dzieckiem
		std::swap(_heap[index], _heap[indexToSwap]);
		//Wywolanie rekurencyjne tej samej metody, zeby sprawdzic czy dziecko, ktore zamienione zostalo z rodzicem jest uporzadkowane dobrze
		//Wykonywane jest to momentu kiedy rodzic jest wiekszy niz jego dzieci lub indeks jest poza zasiegiem
		heapifyDown(indexToSwap);
	}
}

int PriorityQueueHeap::indexOfElement(int index, int oldPriority)
{
	if (index >= _size)
		return -1;

	if (_heap[index].priority == oldPriority)
		return index;

	int leftIndex = indexOfElement(leftChildOf(index), oldPriority);
	if (leftIndex != -1)
		return leftIndex; 

	int rightIndex = indexOfElement(rightChildOf(index), oldPriority);
	return rightIndex; 
}


PriorityQueueHeap::PriorityQueueHeap()
{
	_size = 0;
	Element firstElement(-1, -1);
	_heap.push_back(firstElement);
}

PriorityQueueHeap::~PriorityQueueHeap()
{

}

void PriorityQueueHeap::Insert(int value, int priority)
{
	Element elementToInsert(value, priority);
	_heap.push_back(elementToInsert); // Dodanie nowego elementu na koniec
	heapifyUp(++_size); // Uporzadkowanie kopca od dodanego elementu
}

Element PriorityQueueHeap::ExtractMax()
{
	if (isEmpty()) {
		throw std::out_of_range("The priority queue is empty");
	}

	Element maximumElement = _heap[1];

	std::swap(_heap[1], _heap[_size]); // Przeniesienie ostatniego elementu na miejsce pierwsze
	_size--; // Zmiejszenie wielkosci kopca
	_heap.pop_back();
	heapifyDown(1); // Uporzadkowanie kopca 
	return maximumElement; // Zwrocenie usunietego elementu
}

Element& PriorityQueueHeap::Peek()
{
	if (isEmpty()) {
		throw std::out_of_range("The priority queue is empty");
	}
	return _heap[1];
}

void PriorityQueueHeap::ModifyKey(int oldPriority, int newPriority)
{
	if (isEmpty()) {
		std::cout << "The priority queue is empty" << std::endl;
		return;
	}
	if (oldPriority == newPriority) {
		std::cout << "Priorities are the same!" << std::endl;
		return;
	}
	int newIndex = indexOfElement(1, oldPriority);
	if (newIndex == -1) {
		std::cout << "Unable to find an element with this priority" << std::endl;
		return;
	}
	_heap[newIndex].priority = newPriority;
	if (oldPriority > newPriority)
		heapifyDown(newIndex);
	else
		heapifyUp(newIndex);
}

bool PriorityQueueHeap::isEmpty() const
{
    return _size == 0;
}

int PriorityQueueHeap::GetSize() const
{
    return _size;
}

void PriorityQueueHeap::PrintAll()
{
	if (isEmpty()) {
		std::cout << "The priority queue is empty" << std::endl;
		return;
	}
	std::cout << "Size of heap: " << _size << std::endl;
	for (int i = 1; i <= _size; i++) {
		if (leftChildOf(i) > _size && rightChildOf(i) > _size)
			break;
		std::cout << "Parent Node :: Priority: " << _heap[i].priority << ", Value: " << _heap[i].value << " ";
		if (leftChildOf(i) <= _size) {
			std::cout << "Left Child Node :: Priority: " << _heap[leftChildOf(i)].priority << ", Value: " << _heap[leftChildOf(i)].value << " ";
		}
		if (rightChildOf(i) <= _size) {
			std::cout << "Right Child Node :: Priority: " << _heap[rightChildOf(i)].priority << ", Value: " << _heap[rightChildOf(i)].value << " ";
		}
		std::cout << std::endl;
	}
}

void PriorityQueueHeap::Clear()
{
	_heap.clear();
	_size = 0;
	Element firstElement(-1, -1);
	_heap.push_back(firstElement);
}
