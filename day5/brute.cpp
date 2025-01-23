#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// you just need to implement the function
// timecomplexity := O(n-k)*O(k)
// spacecomplexity := O(n-k)
vector<int> maxInRollingWindow(vector<int>& prices, int k) {
    vector<int>maximumPricePerK;
    int pricesSize = prices.size();

    for(int i=0;i<=prices.size()-k;i++){
        int maximum = INT_MIN;
        for(int j=i;j<k+i ;j++){
            if(prices[j] > maximum){
                maximum = prices[j];
            }
        }
        maximumPricePerK.push_back(maximum);
    }
    return maximumPricePerK;
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
            std::cout << result[i] << " " << std::endl;
        }
    }

    return 0;
}


// #include<iostream>
// #include<vector>
// #include<string>

// using namespace std;


// int main(){
// vector<char>temp; // why the size of this 24
// std::cout << sizeof(temp) << std::endl;

// }
