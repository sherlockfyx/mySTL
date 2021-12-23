//
// Created by Fangyx on 2021/12/4.
//

#ifndef HELLOWORLD_MYALG_H
#define HELLOWORLD_MYALG_H
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <string>

//LRU页面置换算法
class LRUCache{
public:
    LRUCache():cap(5){}
    LRUCache(int x):cap(x){}
    int get(int key){
        if(map.find(key)==map.end()) return -1;
        else{
            cache.splice(cache.begin(),cache,map[key]);
            return map[key]->second;
        }
    }
    void set(int key,int value){
        if(get(key)!=-1) map[key]->second = value;//存在
        else{
            if(cache.size()>=cap){
                int temp = cache.back().first;
                cache.pop_back();
                map.erase(temp);
            }
            cache.emplace_front(key,value);
            map[key] = cache.begin();
        }
    }
private:
    int cap;
    std::list<std::pair<int,int>> cache;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> map;
};

//字符串匹配算法-KMP
class KMP{
public:
    int strStr(std::string s,std::string p){
        int n = s.size();
        int m = p.size();
        if(m==0) return 0;
        std::vector<int> next(m);
        getNext(next,p);
        int j = -1;
        for(int i = 0;i<s.size();i++){
            while(j>=0&&s[i]!=p[j+1]){
                j = next[j];
            }
            if(s[i]==p[j+1]) j++;
            if(j == p.size()-1) return i-p.size()+1;
        }

        return -1;
    }
    void getNext(std::vector<int> &next,std::string& p){
        int j = -1;
        next[0] = j;
        for(int i = 1;i<p.size();i++){
            while(j>=0&&p[i]!=p[j+1]){
                j = next[j];
            }
            if(p[i]==p[j+1]){
                j++;
            }
            next[i] = j;
        }
    }
};

//排序算法
class Sort{
public:
    void quicksort(std::vector<int>& nums,int l,int r){
        if(l>=r) return;
        int i = l;
        int j = r;
        int key = nums[i];
        while(i<j){
            while(i<j&&nums[j]>=key) j--;
            nums[i] = nums[j];
            while(i<j&&nums[i]<=key) i++;
            nums[j] = nums[i];
        }
        nums[i] = key;//更新
        quicksort(nums,l,i-1);
        quicksort(nums,i+1,r);
    }
    void mergesort(std::vector<int>& nums,int l,int r){
        if(l>=r) return;
        int mid =  l+(r-l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        std::vector<int> tmp(r-l+1);
        int i = l,j = mid+1;
        int cnt = 0;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]) tmp[cnt++] = nums[i++];
            else tmp[cnt++] = nums[j++];
        }
        while(i<=mid) tmp[cnt++] = nums[i++];
        while(j<=r) tmp[cnt++] = nums[j++];
        for(int k = 0;k<r-l+1;k++){
            nums[k+l] = tmp[k];
        }
    }
    void heapsort(std::vector<int>& nums,int index){//下标
        //构建最大堆
        for(int i = (index-1)/2;i>=0;--i){
            heapify(nums,index,i);
        }
        while(index>=1){
            std::swap(nums[0],nums[index]);
            index-=1;
            heapify(nums,index,0);
        }
    }
    //维护某个节点的平衡
    void heapify(std::vector<int>& nums,int index,int i){
        int maxpos = i;//下沉
        for(;;){
            if(i*2+1<=index&&nums[i*2+1]>nums[i]) maxpos = i*2+1;
            if(i*2+2<=index&&nums[i*2+2]>nums[i]) maxpos = i*2+2;
            if(maxpos!=i) {
                std::swap(nums[i],nums[maxpos]);
                i = maxpos;
            }else{
                break;
            }
        }
    }
    void bucketsort(std::vector<int>& nums) {
        if (nums.empty()) return;
        int low = *std::min_element(nums.begin(), nums.end());
        int high = *std::max_element(nums.begin(), nums.end());
        int n = high - low + 1;
        std::vector<int> buckets(n);
        std::vector<int> res;
        for (auto x: nums) ++buckets[x - low];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < buckets[i]; ++j) {
                res.push_back(i + low);
            }
        }
    }

};

#endif //HELLOWORLD_MYALG_H