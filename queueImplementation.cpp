#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> queue;

public:
    void enqueue(int value) {
        queue.push_back(value);
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        } else {
            std::cout << "Queue is empty!" << std::endl;
        }
    }

    int front() {
        if (!queue.empty()) {
            return queue.front();
        } else {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
    }

    int back() {
        if (!queue.empty()) {
            return queue.back();
        } else {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
    }

    bool is_empty() {
        return queue.empty();
    }

    int size() {
        return queue.size();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front of queue: " << q.front() << std::endl;
    std::cout << "Back of queue: " << q.back() << std::endl;

    q.dequeue();
    std::cout << "Front of queue after dequeue: " << q.front() << std::endl;

    return 0;
}
