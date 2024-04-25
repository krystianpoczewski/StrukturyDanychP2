#include <iostream>
#include "PriorityQueueDynamicArray.h"
#include "PriorityQueueMax.h"


int main()
{
    PriorityQueueDynamicArray priorityQueue;

    priorityQueue.Insert(10, 3);
    priorityQueue.Insert(20, 1);
    priorityQueue.Insert(30, 5);
    priorityQueue.Insert(40, 2);
    priorityQueue.Insert(50, 4);
    priorityQueue.Insert(2000, 1);

    priorityQueue.PrintAll();


    std::cout << "Peek: " << "Priority: " << priorityQueue.Peek().priority << ", Value: " << priorityQueue.Peek().value << std::endl;

    priorityQueue.ModifyKey(1, 6);
    std::cout << "After modifying priority of element with value 30:" << std::endl;
    priorityQueue.PrintAll();

    std::cout << "Extracted max: " << "Priority: " << priorityQueue.ExtractMax().priority << ", Value: " << priorityQueue.ExtractMax().value << std::endl;

    return 0;
}

