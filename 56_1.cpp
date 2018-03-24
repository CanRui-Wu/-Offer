#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void FindMyNumsAppearOnce(vector<int> data,int *num) {
		*num = data[0];
		for(int i = 1;i < data.size();i++)
			*num ^= data[i];
	} 

    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    	int result = data[0]^data[1];
    	for(int i = 2;i < data.size();i++) {
    		result = result^data[i];
    	}
    	int temp = 1;
    	for(int j = 0;j < 32;j++) {
    		if(result & temp)
    			break;
    		temp = temp << 1;
    	}
    	int start = 0;
    	int end = data.size()-1;
    	while(start != end) {
    		if(data[start] & temp) {
    			if(~data[end] & temp) {
    				swap(data[start],data[end]);
    			} else {
    				end--;
    			}
    		} else {
    			start++;
    		}
    	}    	
    	FindMyNumsAppearOnce(vector<int>(data.begin(),data.begin()+start),num1);
    	FindMyNumsAppearOnce(vector<int>(data.begin()+start,data.end()),num2);
    }
};

int main() {
	int num1,num2;
	Solution solution;
	vector<int> data = {1,3,2,4,6,8,8,6,4,2};
	solution.FindNumsAppearOnce(data,&num1,&num2);
	cout << num1 << endl;
	cout << num2 << endl;
}