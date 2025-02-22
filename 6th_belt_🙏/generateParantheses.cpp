#include <iostream>
#include <vector>

using namespace std;
void backtrack(int n, int open, int closed, string current, vector<string>& result){
    if(open==n && closed==n){
        result.push_back(current);
        return;
    }
    if(open<n){
        backtrack(n, open+1, closed, current+"(", result);
    }
    if(closed<open){
        backtrack(n, open, closed+1, current+ ")", result);
    }
}
vector<string> generateParantheses(int n){
    vector<string> result;
    backtrack(n,0,0,"", result);
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<string> result=generateParantheses(n);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}