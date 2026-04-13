class MinStack {
private: 
    vector<int> s;
    vector<int> ms;
public:
    MinStack() {
        s = {};
    }
    
    void push(int val) {
        s.push_back(val);
        if (ms.empty()) ms.push_back(val);
        else ms.push_back(min(val, ms.back()));
        return;
    }
    
    void pop() {
        s.erase(s.end());
        ms.erase(ms.end());
        return;
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return ms.back();
    }
};
