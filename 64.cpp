#include <iostream>
using namespace std;

class Test {
public:
	static int a;
	static int sum;
	Test() {
		sum += a++;
	}
};

int Test::a = 1;
int Test::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
    	Test::sum = 0;
    	Test::a = 1;
        Test *b = new Test[n];
        delete[] b;
        return Test::sum;
    }
};

int main() {
	Solution solution;
	cout << solution.Sum_Solution(5) << endl;
}