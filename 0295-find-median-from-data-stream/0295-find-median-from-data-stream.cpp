class MedianFinder {
public:
    multiset<int> order;
    multiset<int>::iterator it;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        order.insert(num);
        if (order.size() == 1) 
        {
            it = order.begin();
        } 
        else 
        {
            if (num < *it and order.size() % 2 == 0) {
                --it;
            }
            if (num >= *it and order.size() % 2 != 0) {
                ++it;
            }
        }  
    }
    
    double findMedian() 
    {
        if (order.size() % 2 != 0) {
            return double(*it);
        } 
        else {
            auto one = *it, two = *next(it);
            return double(one + two) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */