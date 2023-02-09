#include <iostream>
#include <vector>

class Stack {
  private:
    std::vector<int> data;
  
  public:
    Stack() {}
    ~Stack() {}

    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if (data.empty()) {
            std::cout << "Error: Stack is empty!" << std::endl;
        } else {
            data.pop_back();
        }
    }

    int top() {
        if (data.empty()) {
            std::cout << "Error: Stack is empty!" << std::endl;
            return -1;
        } else {
            return data.back();
        }
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Top element is: " << s.top() << std::endl;
    s.pop();
    std::cout << "Top element is: " << s.top() << std::endl;
    s.pop();
    std::cout << "Top element is: " << s.top() << std::endl;
    s.pop();
    return 0;
}
