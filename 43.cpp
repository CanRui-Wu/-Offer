#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int mycount(int n,int *table) {
		if(n == 0)
			return 0;
		if(n < 10)
			return 1;
		int temp = n;
		int num = 1;
		while(temp/10) {
			num++;
			temp = temp/10;
		}
		int next = n - temp*pow(10,num-1);
		int result = temp*table[num-2];
		if(temp == 1)
			result += next+1;
		else
			result += pow(10,num-1);
		result += mycount(next,table);
		return result;
	}
    int NumberOf1Between1AndN_Solution(int n) {
    	if(n == 0)
    		return 0;
		if(n < 10)
			return 1;
		int num = 0;
		int temp = n;
		while(temp) {
			num++;
			temp = temp/10;
		}
		cout << num << endl;
		int *table = new int[num-1];
		table[0] = 1;
		for(int i = 1;i < num;i++)
			table[i] = table[i-1]*10+pow(10,i);
		int result = mycount(n,table);
		delete[] table;
		return result;
    }
};

int main() {
	Solution solution;
	cout << solution.NumberOf1Between1AndN_Solution(100) << endl;
}