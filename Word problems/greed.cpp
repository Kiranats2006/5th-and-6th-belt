#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int greed[n];
    for(int i=0; i<n; i++){
        cin>>greed[i];
    }
    int m;
    cin>>m;
    int sizes[m];
    for(int i=0; i<n; i++){
        cin>>sizes[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(greed[j]>greed[j+1]){
                int temp=greed[j];
                greed[j]=greed[j+1];
                greed[j+1]=temp;
            }
        }
    }
    for(int i=0; i<m-1; i++){
        for(int j=0; j<m-i-1; j++){
            if(sizes[j]>sizes[j+1]){
                int temp=sizes[j];
                sizes[j]=sizes[j+1];
                sizes[j+1]=temp;
            }
        }
    }
    int i=0;
    int j=0;
    int contented=0;
    while(i<n && j<m){
        if(sizes[j]>=greed[i]){
            contented++;
            i++;
        }
        j++;
    }
    cout<<contented;
    return 0;
}