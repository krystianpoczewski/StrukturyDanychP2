#include <iostream>
#include "PriorityQueueDynamicArray.h"
#include "PriorityQueueMax.h"
#include "PriorityQueueHeap.h"
#include <random>
#include <fstream>
#include <chrono>



std::string GetOperationName(int operationIndex) {
	switch (operationIndex) {
	case 0:
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
	//Tests(priorityQueue, "Tests Priority Queue Dynamic Array2.txt");
	//Tests(priorityQueueHeap, "Tests Priority Queue Heap2.txt");
	PriorityQueueDynamicArray pq;

	// Insert 10 elements with priorities
	pq.Insert(10, 2);
	pq.Insert(20, 3);
	pq.Insert(30, 1);
	pq.Insert(40, 3);
	pq.Insert(50, 2);
	pq.Insert(60, 4);
	pq.Insert(70, 4);
	pq.Insert(80, 3);
	pq.Insert(90, 1);
	pq.Insert(100, 2);

	// Print the initial priority queue
	std::cout << "Initial Priority Queue:" << std::endl;
	pq.PrintAll();

	// Modify the key of an element
	pq.ModifyKey(3, 4);

	// Print the priority queue after 1st modification
	std::cout << "\nPriority Queue after 1st Modification:" << std::endl;
	pq.PrintAll();

	// Modify the key of another element
	pq.ModifyKey(2, 5);

	// Print the priority queue after 2nd modification
	std::cout << "\nPriority Queue after 2nd Modification:" << std::endl;
	pq.PrintAll();

	// Modify the key of another element
	pq.ModifyKey(4, 1);

	// Print the priority queue after 3rd modification
	std::cout << "\nPriority Queue after 3rd Modification:" << std::endl;
	pq.PrintAll();

	pq.Insert(1, 1);
	std::cout << "\nPriority Queue after another insertion:" << std::endl;
	pq.PrintAll();
}

