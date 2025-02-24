#include <iostream>
#include <vector>

using namespace std;

void backtrack(string& digits, int index, string& current, vector<string>& result, vector<string>& phone){
    if(index==digits.length()){
        result.push_back(current);
        return;
    }
    int digit=digits[index]-'0';
    string letters=phone[digit];
    for(int i=0; i<letters.size(); i++){
        current.push_back(letters[i]);
        backtrack(digits, index+1, current, result, phone);
        current.pop_back();
    }
}
vector<string> letterCombination(string digits){
    if(digits.empty()){
        return {};
    }
    vector<string> phone={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    vector<string> result;
    string current;
    backtrack(digits,0,current,result,phone);
    return result;
}
int main(){
    string digits;
    cin>>digits;
    vector<string> Combinations=letterCombination(digits);
    for(int i=0; i<Combinations.size(); i++){
        cout<<Combinations[i]<<" ";
    }
    cout<<endl;
}