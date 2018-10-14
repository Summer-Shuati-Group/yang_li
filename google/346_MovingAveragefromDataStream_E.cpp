class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
	double sum; // current sum
	int s1; // current size 
	int s2; // size - current size
    MovingAverage(int size) {
		sum = 0;
		this->s2 = size;
		this->s1 = 0;
    }
    
    double next(int val) {
		if (s2 == 0) {
			sum -= q.front();
			q.pop();
			sum += val;
			q.push(val);
			return sum / s1;
		}
		else {
			s1++;
			s2--;
			q.push(val);
			sum += val;
			return sum / s1;
		}
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */