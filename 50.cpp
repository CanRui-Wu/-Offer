#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int test[52];
        memset(test,-1,sizeof(test));
        for(int i = 0;i < (int)str.length();i++) {
        	int index;
        	if(str[i] >= 'a' && str[i] <= 'z')
        		index = str[i]-'a';
        	else
        		index = str[i]-'A'+26;
        	if(test[index] == -1) {
        		test[index] = i;
        	} else {
        		test[index] = -2;
        	}
        }
        int min_index = INT_MAX;
        for(int i = 0;i < 52;i++) {
        	if(test[i] >= 0 && test[i] < min_index) {
        		min_index = test[i];
        	}
        }
        if(min_index == INT_MAX)
        	min_index = -1;
        return min_index;
    }
};

int main() {
	Solution solution;
	cout << solution.FirstNotRepeatingChar("eDSDSEabcdcbaeh") << endl;
}