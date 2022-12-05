#include <stack>
#include <iostream>

int main() {
    std::stack<int> stack;
    
    while (stack.size() < 1000000000000)
    {
        int count = 0;

        stack.push(count);
    }
    std::cout << "stack szie is = " << stack.size();
    
}