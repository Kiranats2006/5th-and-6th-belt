#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int matrix[n][n], helperMatrix[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            helperMatrix[j][n-i-1]=matrix[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<helperMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}