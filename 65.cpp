#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2) {
    	int carry = (num1 & num2) << 1;
    	int sum = num1^num2;
    	int temp;
    	while(carry != 0) {
    		temp = (sum & carry) << 1;
    		sum = sum^carry;
    		carry = temp;
    	}
    	return sum;
    }
};
int main() {

}