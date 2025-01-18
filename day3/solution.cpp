// this include the header file which tell the computer to include the istream and ostream
// which gonna be used in the taking input from the keyboard and displaying output to the screen
#include<iostream>
#include<vector>
#include <algorithm>
// this below line tell which name space to use, in this case standard namespace is used
// namespace is set of collection class,method, function in the same scope
using namespace std;

vector<vector<int>> func(vector<vector<int>> teams) {
    vector<vector<int>>result;
    // each list in the 2d array
    // {team_index, total_elimination, highest_individual_elimination}
    // and the team_index should be 1-based idx
    vector<vector<int>>teamInfo;
    // calculate the teamResult
    for(int i=0;i<teams.size();i++){
        int total_elimination = 0;
        int highest_individual_elimination = 0;
        vector<int>temp;
        for(int eliminations :teams[i]){
            total_elimination += eliminations;
            if(eliminations > highest_individual_elimination){
                highest_individual_elimination = eliminations;
            }
        }
        temp.push_back(i+1);
        temp.push_back(total_elimination);
        temp.push_back(highest_individual_elimination);
        teamInfo.push_back(temp);
    }

    // now write the custom sort function, which will sort it in increasing order

    sort(teamInfo.begin(),teamInfo.end(),[](const vector<int>& a, const vector<int>& b){
        // now i have both a and b
        // we need to use condition here which define, like the 
        // 1. team with the highest total will be considerd first
        // 2. if multiple team have same highest total, then compare the highest individual elimination
        if (a[1] != b[1]){
            return a[1] > b[1]; // then sort it in the desending order
        }   
        else {
            return a[2] > b[2];
        }

    });

    // now the first value we would have will mbe
    int highest_total = teamInfo[0][1]; // 10
    int highest_individual_elimination = teamInfo[0][2]; // 5

    for(vector<int> team:teamInfo){
        if(team[1] == highest_total && team[2] == highest_individual_elimination){
            result.push_back(team);
        }
    }

    return result;
}

int main() {
    // initial code 
    vector<vector<int>> teams;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int team_size;
        cin >> team_size;
        vector<int> team(team_size);
        for (int j = 0; j < team_size; j++) {
            cin >> team[j];
        }
        teams.push_back(team);
    }
    // you have to implement the func() only
    vector<vector<int>> result = func(teams);

    // print the result(please don't modify this)
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
        } else {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }   
    // end of initial code
    return 0;
}