#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<unordered_map>
/*
   Given a non-empty array of integers, return the k most frequent elements

*/
using namespace std;
class Solution{
/*
  使用hash_map统计，用堆找出K个数量最多的元素。 priority_queue默认为大根堆
  <计数，元素>

*/
public:
  vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> hash;
    priority_queue<pair<int, int>> q;
    vector<int> ret;
    for(auto a:nums){
      hash[a]++;
    }
    for(auto it:hash){
      q.push(make_pair(it.second, it.first));
    }
    for(int i = 0; i < k; ++i){
      ret.push_back(q.top().second);
      q.pop();
    }
    return ret;
  }
};

class Solution2{
  typedef pair<int, int> data;
public:
  vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> hash;
    priority_queue<data, vector<data>, greater<data>> heap;
    vector<int> ret;
    for(int num:nums){
      hash[num]++;
    }
    for(auto it:hash){
      heap.push(make_pair(it.second, it.first));
      if(heap.size() > k) heap.pop();
    }
    while(!heap.empty()){
      ret.push_back(heap.top().second);
      heap.pop();
    }
    return ret;
  }
};

class Solution3{
  typedef pair<int, int> data;
public:
  vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> hash;
    priority_queue<data, vector<data>, greater<data>> heap;
    vector<int> ret;
    for(int num:nums){
      hash[num]++;
    }
    for(auto it:hash){
      heap.push(make_pair(it.second, it.first));
      if(heap.size() > k) heap.pop();
    }
    while(!heap.empty()){
      ret.push_back(heap.top().second);
      heap.pop();
    }
    return ret;


  }
};

int main(){
  vector<int> num = {5, 5, 5, 5, 5, 6, 3, 1, 3, 6, 1, 3};
  // Solution solution = Solution();
  Solution solution = Solution();
  Solution2 solution2 = Solution2();
  Solution3 solution3 = Solution3();

  vector<int> ret = solution.topKFrequent(num, 3);
  for(auto i = ret.begin(); i != ret.end(); i++){
    cout<<*i<<" ";
  }
  cout<<endl;
  vector<int> ret2 = solution2.topKFrequent(num, 3);
  for(auto i = ret2.begin(); i!=ret2.end(); i++){
    cout<<*i<<" ";
  }
  cout<<endl;
  vector<int> ret3 = solution3.topKFrequent(num, 3);
  for(auto i = ret3.begin(); i!=ret3.end(); i++){
    cout<<*i<<" ";
  }

}
