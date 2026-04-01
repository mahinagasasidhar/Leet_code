// Last updated: 01/04/2026, 19:26:00
class StockSpanner {
public:
    int cnt;
    stack<pair<int,int>> st;

    StockSpanner() {
        cnt = -1;
    }
    
    int next(int price) {
        cnt++;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if (st.empty()) {
            st.push({price, cnt});
            return (cnt == 0) ? 1 : cnt + 1;
        } else {
            int ans = cnt - st.top().second;
            st.push({price, cnt});
            return ans;
        }
    }
};