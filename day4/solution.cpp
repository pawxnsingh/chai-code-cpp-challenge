#include <iostream>
#include <string>
#include <vector>
using namespace std;

// you just need to implement the BrowserHistory class below
class BrowserHistory {
    // private vector i guess
private:
    vector<string>history;
    int current_index;
public:
    BrowserHistory(string homepage) {
       history.push_back(homepage);
       current_index = 0;
    }

    void visit(string url) {
        // user visit a url then make the 
        history.push_back(url);
        current_index ++;

    }

    string back(int steps) {
        // go some steps back and return the current URL 
        current_index -= steps;
        return history[current_index];
    }

    string forward(int steps) {
        // go some step forward and return the current URL
        current_index += steps;
        return history[current_index];
    }
};

int main() {
    int n;
    cin >> n; 
    string operation, url;
    int steps;

    // please do not change below code
    BrowserHistory browserHistory("chaicode.com");
    
    string result = "chaicode.com ";
    for (int i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "visit") {
            cin >> url;
            browserHistory.visit(url);
            result += url + " ";
        } else if (operation == "back") {
            cin >> steps;
            result += browserHistory.back(steps) + " ";
        } else if (operation == "forward") {
            cin >> steps;
            result += browserHistory.forward(steps) + " ";
        }
    }
    
    cout << result.substr(0, result.size() - 1);

    return 0;
}