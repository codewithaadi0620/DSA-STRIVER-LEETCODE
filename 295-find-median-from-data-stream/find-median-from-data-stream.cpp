class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianFinder() {
    }

    void addNum(int num) {
        if (maxH.empty() || maxH.top() >= num) {
            maxH.push(num);
        } else {
            minH.push(num);
        }

        // Balance the heaps
        if (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        } 
        else if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    double findMedian() {
        if (maxH.size() > minH.size()) {
            return maxH.top();
        }

        return ((double)maxH.top() + minH.top()) / 2.0;
    }
};