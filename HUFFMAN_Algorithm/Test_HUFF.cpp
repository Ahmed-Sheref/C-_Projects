#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Create a min-heap priority_queue using a custom comparator
    queue<int> pq;

    // Add some elements to the priority queue
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(5);
    pq.push(30);

    // Display the smallest element (it will always be at the top)
    cout << "The smallest element is: " << pq.front() << endl; // 5

    // Remove the smallest element
    pq.pop(); 

    // Now the smallest element should be 10
    cout << "After popping, the smallest element is: " << pq.front() << endl; // 10

    // Print all the remaining elements (Note: not in sorted order)
    cout << "Remaining elements: ";
    while (!pq.empty()) {
        cout << pq.front() << " "; // Prints the smallest element at the top
        pq.pop(); // Remove the top element
    }
    cout << endl;

    return 0;
}
