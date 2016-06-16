class MedianFinder {
priority_queue<double, vector<double>, greater<double> >left;
priority_queue<double, vector<double>, less<double> >right;
double median=0;
int diff=0;
public:

// Adds a number into the data structure.
void addNum(int num) {
    diff=left.size()-right.size();
    num=double(num);
    if(diff==0){
        if(median < num){
            left.push(num);
            median=left.top();
        }
        else{
            right.push(num);
            median=right.top();
        }
    }
    else if(diff==1){
        if(median < num){
            right.push(left.top());
            left.pop();
            left.push(num);
        }
        else right.push(num);
        median= (left.top() + right.top() )/2;
    }
    else if(diff== -1){
        if(median < num)left.push(num);
        else{
            left.push(right.top());
            right.pop();
            right.push(num);
        }
        median=(left.top() + right.top() )/2;
    }
}

// Returns the median of current data stream
double findMedian() {
    return median;
}
};