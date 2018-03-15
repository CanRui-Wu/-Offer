#include <iostream>
using namespace std;

class Solution {
public:
	//Effective verison
	// int NumberOf1(int n) {
	// 	int count = 0;
	// 	while(n) {
	// 		count++;
	// 		n = (n-1)&n;
	// 	}
	// 	return count;
	// }

	//Normal verison
	int NumberOf1(int n) {
		int count = 0;
		for(int i = 0;i < sizeof(int)*8;i++) {
			if(n&1) {
				count++;
			}
			n = (n >> 1);
		}
		return count;
	}
};

int main() {
	Solution solution;
	cout << solution.NumberOf1(-1) << endl;
}