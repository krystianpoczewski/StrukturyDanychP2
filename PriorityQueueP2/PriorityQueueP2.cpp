#include <iostream>
#include "PriorityQueueDynamicArray.h"
#include "PriorityQueueMax.h"
#include "PriorityQueueHeap.h"
#include <random>
#include <fstream>
#include <chrono>



std::string GetOperationName(int operationIndex) {
	switch (operationIndex) {
	case 0 :
		return "Insert";
	case 1: 
		return "Extract Max";
	case 2:
		return "Peek";
	case 3:
		return "Modify Key";
	case 4:
		return "Get Size";
	default:
		return "Unknown Operation";
	}
}

void Tests(PriorityQueueMax* queue, std::string fileName) {
	std::ofstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Can't open the file: " << fileName << std::endl;
		return;
	}

	int sizes[] = { 5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000 };
	int testCount = 50;

	const int min = 0;
	const int max = 1000000;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min, max);

	for (int operation = 0; operation < 5; operation++) {
		std::string operationName = GetOperationName(operation);
		file << operationName << std::endl;
		for (int size : sizes) {
			std::cout << size;
			long long totalTime = 0;
			std::uniform_int_distribution<int> randomPriorityDistrubution(0, size - 1);
			for (int i = 0; i < testCount; i++) {
				int indexOfElementToChangePriority = randomPriorityDistrubution(generator);
				int oldPriority = 0;
				for (int j = 0; j < size; j++) {
					int priorityToInsert = distribution(generator);
					int valueToInsert = distribution(generator);

					if (j == indexOfElementToChangePriority)
						oldPriority = priorityToInsert;

					queue->Insert(valueToInsert, priorityToInsert);
				}
				auto start = std::chrono::high_resolution_clock::now();
				auto stop = std::chrono::high_resolution_clock::now();
				int priority, value, newPriority;
				switch (operation) {
				case 0:
					priority = distribution(generator);
					value = distribution(generator);
					start = std::chrono::high_resolution_clock::now();
					queue->Insert(value, priority);
					stop = std::chrono::high_resolution_clock::now();
					totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
					break;
				case 1:
					start = std::chrono::high_resolution_clock::now();
					queue->ExtractMax();
					stop = std::chrono::high_resolution_clock::now();
					totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
					break;
				case 2:
					start = std::chrono::high_resolution_clock::now();
					queue->Peek();
					stop = std::chrono::high_resolution_clock::now();
					totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
					break;
				case 3:
					newPriority = distribution(generator);
					start = std::chrono::high_resolution_clock::now();
					queue->ModifyKey(oldPriority, newPriority);
					stop = std::chrono::high_resolution_clock::now();
					totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
					break;
				case 4:
					start = std::chrono::high_resolution_clock::now();
					queue->GetSize();
					stop = std::chrono::high_resolution_clock::now();
					totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
					break;
				}
				queue->Clear();
			}
			file << size << "," << totalTime / testCount << std::endl;
		}
	}
	file.close();
}

int main()
{
	PriorityQueueDynamicArray* priorityQueue = new PriorityQueueDynamicArray;
	PriorityQueueHeap* priorityQueueHeap = new PriorityQueueHeap;
	Tests(priorityQueue, "Tests Priority Queue Dynamic Array.txt");
	Tests(priorityQueueHeap, "Tests Priority Queue Heap.txt");
	/*PriorityQueueDynamicArray priorityQueue;

	priorityQueue.Insert(10, 3);
	priorityQueue.Insert(20, 1);
	priorityQueue.Insert(30, 5);
	priorityQueue.Insert(40, 2);
	priorityQueue.Insert(50, 4);
	priorityQueue.Insert(2000, 4);

	priorityQueue.PrintAll();


	std::cout << "Peek: " << "Priority: " << priorityQueue.Peek().priority << ", Value: " << priorityQueue.Peek().value << std::endl;

	priorityQueue.ModifyKey(5, 1);
	std::cout << "After modifying priority of element" << std::endl;
	priorityQueue.PrintAll();

	Element extracted = priorityQueue.ExtractMax();
	std::cout << "Extracted max: " << "Priority: " << extracted.priority << ", Value: " << extracted.value << std::endl;*/

	//PriorityQueueHeap maxHeap;

	//// Insert elements into the heap
	//maxHeap.Insert(5, 50);
	//maxHeap.Insert(3, 30);
	//maxHeap.Insert(8, 80);
	//maxHeap.Insert(2, 20);
	//maxHeap.Insert(6, 60);

	////std::cout << "Heap size after insertion: " << maxHeap.GetSize() << std::endl;

	//// Print all elements in the heap
	//std::cout << "All elements in the heap:" << std::endl;
	//maxHeap.PrintAll();

	//// Extract the maximum element from the heap
	//Element maxElement = maxHeap.ExtractMax();
	//std::cout << "Extracted maximum element: Priority=" << maxElement.priority << ", Value=" << maxElement.value << std::endl;

	//// Get the maximum element without removing it
	//Element currentMax = maxHeap.Peek();
	//std::cout << "Current maximum element: Priority=" << currentMax.priority << ", Value=" << currentMax.value << std::endl;

	//// Print all elements in the heap after extraction
	//std::cout << "Heap after extraction:" << std::endl;
	//maxHeap.PrintAll();
	//std::cout << std::endl;
	//maxHeap.Insert(2, 60);
	//maxHeap.PrintAll();
	//std::cout << std::endl;
	//maxHeap.Insert(5, 1);
	//maxHeap.Insert(3, 2);
	//maxHeap.Insert(8, 3);
	//maxHeap.Insert(2, 100);
	//maxHeap.Insert(6, 0);
	//maxHeap.PrintAll();
	//std::cout << std::endl;
	//maxHeap.ModifyKey(1, 100);
	//maxHeap.Insert(6, 1000);
	//maxHeap.PrintAll();
	//return 0;
}

