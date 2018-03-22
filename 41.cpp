#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//Way 1,directly use heap
// class Solution {
// public:
// 	static bool compare(int a,int b) {
// 		return a > b;
// 	}
//     void Insert(int num) {
//         if(max_heap.size() <= min_heap.size()) {
//         	if(min_heap.size() != 0 && num > min_heap[0]) {
//         		max_heap.push_back(min_heap[0]);
//         		pop_heap(min_heap.begin(),min_heap.end(),compare);
//         		min_heap.back() = num;
//         		push_heap(min_heap.begin(),min_heap.end(),compare);
//         	} else {
//         		max_heap.push_back(num);
//         	}
//         	push_heap(max_heap.begin(),max_heap.end());
//         } else {
//         	if(max_heap.size() != 0 && max_heap[0] > num) {
//         		min_heap.push_back(max_heap[0]);
//         		pop_heap(max_heap.begin(),max_heap.end());
//         		max_heap.back() = num;
//         		push_heap(max_heap.begin(),max_heap.end());
//         	} else {
//         		min_heap.push_back(num);
//         	}
//         	push_heap(min_heap.begin(),min_heap.end(),compare);
//         }
//     }

//     double GetMedian() { 
//     	//cout << "****" << min_heap.size() << "*****" << max_heap.size() << endl;
//     	if(min_heap.size() == 0 && max_heap.size() == 0)
//     		return -1;
//     	if(max_heap.size() > min_heap.size()) {
//     		return max_heap[0];
//     	} else if(min_heap.size() > max_heap.size()) {
//     		return min_heap[0];
//     	} else {
//     		//cout << "xxxx" << min_heap[0] << "xxxxx" << max_heap[0] << endl;
//     		return ((double)min_heap[0]+max_heap[0])/2;
//     	}
//     }
// private:
// 	vector<int> max_heap;
// 	vector<int> min_heap;
// };


//Way2,use priority heap
class Solution {
public:
	static bool compare(int a,int b) {
		return a > b;
	}
	Solution(): min_heap(compare) {

	}
    void Insert(int num) {
      	if(max_heap.size() <= min_heap.size()) {
      		if(min_heap.size() != 0 && num > min_heap.top()) {
      			max_heap.push(min_heap.top());
      			min_heap.pop();
      			min_heap.push(num);
      		} else {
      			max_heap.push(num);
      		}
      	} else {
      		if(max_heap.size() != 0 && num < max_heap.top()) {
      			min_heap.push(max_heap.top());
      			max_heap.pop();
      			max_heap.push(num);
      		} else {
      			min_heap.push(num);
      		}
      	}
    }

    double GetMedian() { 
    	if(min_heap.size() == 0 && max_heap.size() == 0)
    		return -1;
    	if(max_heap.size() > min_heap.size()) {
    		return max_heap.top();
    	} else if(min_heap.size() > max_heap.size()) {
    		return min_heap.top();
    	} else {
    		return ((double)min_heap.top()+max_heap.top())/2;
    	}
    }
private:
	priority_queue<int> max_heap;
	priority_queue<int,vector<int>,bool(*)(int,int)> min_heap;
};
 
int main() {
	Solution solution;
	int temp;
	for(int i = 0;i < 10;i++) {
		cin >> temp;
		solution.Insert(temp);
		cout << solution.GetMedian() << endl;
	}
}