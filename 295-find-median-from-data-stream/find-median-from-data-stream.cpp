class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(minh.size()>maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    double findMedian() {
        if(maxh.size()==minh.size()) return (maxh.top()+minh.top())/2.0;
        return maxh.top();
    }
};