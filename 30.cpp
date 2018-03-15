#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        value_stack.push(value);
        if(!min_value_stack.empty()) {
        	min_value_stack.push(std::min(min_value_stack.top(),value));
        }
        else {
        	min_value_stack.push(value); 
        }
    }
    void pop() {
        value_stack.pop();
        min_value_stack.pop();
    }
    int top() {
        return value_stack.top();
    }
    int min() {
        return min_value_stack.top();
    }
private:
	stack<int> value_stack;
	stack<int> min_value_stack;
};

int main() {
	Solution solution;
	solution.push(7);
	solution.push(2);
	solution.push(4);
	cout << solution.min() << endl;
	solution.pop();
	cout << solution.min() << endl;
	solution.pop();
	cout << solution.min() << endl;
}