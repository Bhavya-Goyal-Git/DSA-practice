#include <iostream>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/n-queue-using-array_1170053?leftPanelTabValue=SUBMISSION

// Problem : Given the number of queues n, and the size of array s, implement n number of queues in a single array of size s.

// Approach : For doing this, we need another array of size s, called next, which stores the stack of freespots and also controls the linking of elements in various queues it is initialized with 1,2,3..,-1 as free after 0 is 1, 1 is 2 and so on until free after last spot is -1. Also a variable called freespot that stores the available freespot in array. Also 2 arrays front and rear of size n (number of queues) to store the fronts and rears of each queue initialzed with all -1's. The operations are as follows :
// Enqueuing : Firstly check overflow condtion that is simply if freeSpot is -1, if yes return false. Then, find the index where insertion can be done, index = freespot. Now this freespot is utilised and must be changed. therefore freespot = next[index]. Now we check if this is the first insertion in that queue. front[q] == -1 if yes then front[q] = index. Else, this is not first insertion and front does not need to be changed, however we need to link the previous last element to this element. for this, write next[rear[q]] = index in the else part. Now, mark the position of this element filled that is next[index] = -1 and update the rear of this queue rear[q] = index. Finally actually add the element into array, that is arr[index] = data and return true;
// Dequeuing : Firstly check underflow condition if front[q] == -1 then return -1 as no elements are present. Else first find the index where to pop from that is index = front[q]. Now update this front (effectively pop the element) by doing front[q] = next[index]. This shifts the front to next element in the list. Now we have to manage some freespots. Make the deleted place in freespots stack in the next array, i.e. next[index] = freespot and freespot = index. At the end, simply return the value to be popped i.e. return arr[index]

class NQueue
{
public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    // Initialize your data structure.
    NQueue(int n, int s)
    {
        this->arr = new int[s];
        this->next = new int[s];
        for (int i = 0; i < s; i++)
        {
            (this->next)[i] = i + 1;
        }
        (this->next)[s - 1] = -1;
        this->front = new int[n];
        this->rear = new int[n];
        this->freeSpot = 0;
        for (int i = 0; i < n; i++)
        {
            (this->front)[i] = -1;
            (this->rear)[i] = -1;
        }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        if (freeSpot == -1)
        {
            return false;
        }
        // finding index to insert at
        int index = freeSpot;
        // updating freespot variable
        freeSpot = next[index];
        // check whether it is first element or not
        if (front[m - 1] == -1)
        {
            front[m - 1] = index;
        }
        else
        {
            // else perform the linking of previous element to this one
            next[rear[m - 1]] = index;
        }
        // mark the spot as filled
        next[index] = -1;
        // update rear to desired index
        rear[m - 1] = index;
        // add the data finally into array and return true
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        if (front[m - 1] == -1)
        {
            return -1;
        }
        // find index to pop from
        int index = front[m - 1];
        // update front to next element in the queue
        front[m - 1] = next[index];
        // manage the freespots in next
        next[index] = freeSpot;
        freeSpot = index;
        // return the popped value
        return arr[index];
    }
};