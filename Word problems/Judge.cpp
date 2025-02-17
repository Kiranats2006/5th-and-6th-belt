#include<iostream>
using namespace std;
int main(){
    int m, n;
    cin>>m>>n;
    int trustGiven[n+1]={0};
    int trustRecieved[n+1]={0};
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        trustGiven[a]++;
        trustRecieved[b]++;
    }
    for(int i=0; i<=n; i++){
        if(trustGiven[i]==0 && trustRecieved[i]==n-1){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}