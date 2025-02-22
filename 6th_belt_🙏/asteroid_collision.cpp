#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class stack{
    private:
    int* arr;
    int top;
    int n;
    public:
    stack(int size){
        n=size;
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"No element to pop";
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"No element in stack";
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
    void getElements(vector<int>& result){
        for(int i=0; i<=top; i++){
            result.push_back(arr[i]);
        }
    }
};
vector<int> asteroidCollision(vector<int>& asteroids){
    stack st(asteroids.size());
    for(int i=0; i<asteroids.size(); i++){
        int asteroid=asteroids[i];
        bool destroyed=false;
        while(!st.empty() && st.Top()>0 && asteroid<0){
            if(st.Top()<-asteroid){
                st.pop();
                continue;
            }
            else if(st.Top()==-asteroid){
                st.pop();
            }
            destroyed=true;
            break;
        }
        if(!destroyed){
            st.push(asteroid);
        }
    }
    vector<int> result;
    st.getElements(result);
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int> asteroids(n);
    for(int i=0; i<n; i++){
        cin>>asteroids[i];
    }
    vector<int> result=asteroidCollision(asteroids);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}