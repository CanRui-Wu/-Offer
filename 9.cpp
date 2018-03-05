#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(!stack2.empty()) {
        	int result = stack2.top();
        	stack2.pop();
        	return result;
        } else {
        	while(!stack1.empty()) {
        		stack2.push(stack1.top());
        		stack1.pop();
        	}
        	return pop();
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
	Solution solution;
	solution.push(2);
	solution.push(3);
	cout << solution.pop() << endl;
	solution.push(4);
	cout << solution.pop() << endl;
	solution.push(5);
	cout << solution.pop() << endl;
	cout << solution.pop() << endl;
}