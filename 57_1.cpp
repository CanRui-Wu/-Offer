#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size() < 2)
        	return result;
       	int begin = 0;
       	int end = array.size()-1;
       	int init = 0;
       	while(begin < end) {
       		cout << begin << end << endl;
       		if(array[begin]+array[end] == sum) {
       			if(init == 0 || array[begin]*array[end] < result[0]*result[1]) {
       				if(init != 0)
       					result.clear();
       				else
       					init = 1;
       				result.push_back(array[begin]);
       				result.push_back(array[end]);	
       			}
       			begin++;
       			end--;
       		} else if(array[begin] + array[end] > sum) {
       			end--;
       		} else {
       			begin++;
       		}
       	}
       	return result;
    }
};

int main() {
	Solution solution;
	vector<int> array = {-1,-2,-3,-4,-5,-6,-7,-8};
	vector<int> result = solution.FindNumbersWithSum(array,-9);
	for(int i = 0;i < result.size();i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}