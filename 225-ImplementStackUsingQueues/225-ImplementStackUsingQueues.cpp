// Last updated: 01/04/2026, 19:27:22
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    void push(int x) {
    q1.push(x);
    int n = q1.size();
    for(int i=0;i<n-1;i++){
        q1.push(q1.front());
        q1.pop();
    }
    }
    
    int pop() {
    int result = q1.front();
    q1.pop();
    return result;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
