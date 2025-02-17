# include<iostream>
using namespace std;
bool isPalindrome(string& str, int left, int right){
    while(left<right){
        if(str[left]!=str[right]){
            return false;
            break;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    string doubles=s+s;
    int n=s.length();
    for(int i=0; i<n; i++){
        int length=i+n-1;
        if(isPalindrome(doubles, i, length)){
            cout<<"yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}