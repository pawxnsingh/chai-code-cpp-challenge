#include<iostream>
using namespace std;

bool isPalindrome(string s, int left, int right){

    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool canbepalindrome(string s){
    int left = 0;
    int right = s.size()-1;

    while(left < right){
        // if there is a mismatch
        if(s[left] != s[right]){
            return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
        }
        left++;
        right--;
    }
    return true;
}

int main(){
   string s;
   cin >> s;
   if(canbepalindrome(s)){
    cout << "true" << endl;
   }else{
    cout << "false" << endl;
   }
}