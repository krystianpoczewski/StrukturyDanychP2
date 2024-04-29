#include <iostream>
#include "PriorityQueueDynamicArray.h"
#include "PriorityQueueMax.h"
#include "MaxHeap.h"

int main()
{
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


    MaxHeap maxHeap;

    // Insert elements into the heap
    maxHeap.Insert(5, 50);
    maxHeap.Insert(3, 30);
    maxHeap.Insert(8, 80);
    maxHeap.Insert(2, 20);
    maxHeap.Insert(6, 60);

    std::cout << "Heap size after insertion: " << maxHeap.GetSize() << std::endl;

    // Print all elements in the heap
    std::cout << "All elements in the heap:" << std::endl;
    maxHeap.PrintAll();

    // Extract the maximum element from the heap
    Element maxElement = maxHeap.ExtractMax();
    std::cout << "Extracted maximum element: Priority=" << maxElement.priority << ", Value=" << maxElement.value << std::endl;

    // Get the maximum element without removing it
    Element currentMax = maxHeap.GetMax();
    std::cout << "Current maximum element: Priority=" << currentMax.priority << ", Value=" << currentMax.value << std::endl;

    // Print all elements in the heap after extraction
    std::cout << "Heap after extraction:" << std::endl;
    maxHeap.PrintAll();
    std::cout << std::endl;
    maxHeap.Insert(2, 60);
    maxHeap.PrintAll();
    return 0;
}

