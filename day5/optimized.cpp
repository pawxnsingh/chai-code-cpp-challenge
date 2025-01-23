#include <vector>
#include <deque>
using namespace std;

// you just need to implement the function
vector<int> maxInRollingWindow(vector<int>& prices, int k) {
    int left = 0;
    int right = 0;
    deque<int>dq;
    vector<int>result;


    while(right < prices.size()){
        while(!dq.empty() && prices[right] > dq.back()){
            dq.pop_back();
        }

        dq.push_back(prices[right]);

        if(right - left + 1 >= k){
            // 2. store the maximum of window in the result
            // 3. move the left pointer by one position
            result.push_back(dq.front());

            if(prices[left] == dq.front()){
                dq.pop_front();
            }

            left++;

        }
        right++;
    }
    
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

   // please do not remove the following code
    vector<int> result = maxInRollingWindow(prices, k);
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}