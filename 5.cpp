#include <iostream>
using namespace std;


class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str == NULL || length == 0)
			return;
		int space_count = 0;
		for(int i = 0;i < length;i++) {
			if(str[i] == ' ')
				space_count++;
		}
		if(space_count == 0)
			return;
		for(int i = 2*space_count+length-1;i >= 0;i--) {
			if(str[i-2*space_count] != ' ') {
				str[i] = str[i-2*space_count];
			} else {
				str[i] = '0';
				str[i-1] = '2';
				str[i-2] = '%';
				space_count--;
				i = i-2;
			}
		}
	}
};

int main() {
	char str[] = "a b  c1111111111111111111";
	Solution solution;
	solution.replaceSpace(str,2);
	printf("%s",str);
}