class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(int it:stones)
            maxHeap.push(it);
        
        while(maxHeap.size()>1){
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if(second!=first)
                maxHeap.push(abs(first-second));
        }

        maxHeap.push(0);

        return maxHeap.top();
    }
};
