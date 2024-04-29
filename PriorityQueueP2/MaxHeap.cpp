#include "MaxHeap.h"
#include <iostream>

int MaxHeap::parentOf(int index)
{
	return index / 2;
}

int MaxHeap::leftChildOf(int index)
{
	return index * 2;
}

int MaxHeap::rightChildOf(int index)
{
	return (index * 2) + 1;
}

void MaxHeap::heapifyUp(int index)
{
	if (index == 1)
		return; //Jest na pozycji 1, nie potrzebna zmiana pozycji

	if (_heap[index].priority > _heap[parentOf(index)].priority) {
		std::swap(_heap[index], _heap[parentOf(index)]);
	}
	heapifyUp(parentOf(index)); //Rekrurencyjne wywolanie funckji aby wszystkie wartosci byly poprawne
	//Wykonywane az do dojscia do pierwszej pozycji
}

void MaxHeap::heapifyDown(int index)
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

MaxHeap::MaxHeap()
{
	_size = 0;
	Element firstElement(-1, -1);
	_heap.push_back(firstElement);
}

MaxHeap::~MaxHeap()
{

}

void MaxHeap::Insert(int priority, int value)
{
	Element elementToInsert(value, priority);
	_heap.push_back(elementToInsert); // Dodanie nowego elementu na koniec
	heapifyUp(++_size); // Uporzadkowanie kopca od dodanego elementu
}

Element MaxHeap::ExtractMax()
{
	if (isEmpty()) {
		throw std::runtime_error::runtime_error("Heap is empty!");
	}

	Element maximumElement = _heap[1];

	std::swap(_heap[1], _heap[_size]); // Przeniesienie ostatniego elementu na miejsce pierwsze
	_size--; // Zmiejszenie wielkosci kopca
	_heap.pop_back();
	heapifyDown(1); // Uporzadkowanie kopca 
	return maximumElement; // Zwrocenie usunietego elementu
}

Element MaxHeap::GetMax() const
{
	return _heap[1];
}

int MaxHeap::GetSize() const
{
	return _size;
}

bool MaxHeap::isEmpty() const
{
	return _size == 0;
}

void MaxHeap::PrintAll() const
{
	if (isEmpty()) {
		std::cout << "Empty heap" << std::endl;
		return;
	}
	for (int i = 1; i < _size + 1; i++) {
		std::cout << "Priority: " << _heap[i].priority << ", Value: " << _heap[i].value << std::endl;
	}
}
