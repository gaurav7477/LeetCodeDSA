class MedianFinder {
public:
    priority_queue<int>max_heap; // store lower element
    priority_queue<int,vector<int>,greater<int>> min_heap; // store higher element
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty()){
             max_heap.push(num);
            return;
        }
        if(max_heap.size()> min_heap.size()){
            if(max_heap.top() > num){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else{
                min_heap.push(num);
            }
        }
        
        else{
            if(min_heap.top() < num){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else{
                max_heap.push(num);
            }
        }
    }

    
    double findMedian() {
        if(max_heap.size()== min_heap.size())
        {
            return (double)(min_heap.top() + max_heap.top())/2.0;
        }
        else
        {
            if(max_heap.size() > min_heap.size())
                return max_heap.top();
            else
                return min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */