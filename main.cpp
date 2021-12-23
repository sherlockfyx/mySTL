#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

#include "inc/mystring.h"
#include "inc/mysingleton.h"
#include "inc/mystruct.h"


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> st;
        for (int i = 0; i < k-1; i++) {
            st.insert(nums[i]);
        }
        for (int i = k-1; i < nums.size(); ++i) {
            auto first = next(st.begin(),(k-1)/2);
            auto second = next(st.begin(),k/2);
            res.push_back((*first+*second)/2);
            st.insert(nums[i]);
            st.erase(st.find(nums[i-k-1]));
        }
        return res;
    }
};






int main(){


    Solution A;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<double> num = A.medianSlidingWindow(nums,3);


    return 0;
}

