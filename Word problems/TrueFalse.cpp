#include<iostream>
using namespace std;
int main(){
    string answerKey;
    int k;
    cin>>answerKey>>k;
    int n=answerKey.length();
    int maxLength=0;
    for(int start=0; start<n; start++){
        int countF=0;
        int end=start;
        while(end<n && countF<=k){
            if(answerKey[end]=='F'){
                countF++;
            }
            if(countF<=k){
                if(maxLength<end-start+1){
                    maxLength=end-start+1;
                }
            }
                end++;
        }
    }
    for(int start=0; start<n; start++){
        int countT=0;
        int end=start;
        while(end<n && countT<=k){
            if(answerKey[end]=='T'){
                countT++;
            }
            if(countT<=k){
                if(maxLength<end-start+1){
                    maxLength=end-start+1;
                }
            }
                end++;
        }
    }
    cout<<maxLength<<endl;
    return 0;
}