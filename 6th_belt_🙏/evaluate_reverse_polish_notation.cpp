#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class stack {
private:
    int* arr;
    int top;
    int n;
public:
    stack(int size) {
        n = size;
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    int Top() {
        if (top == -1) {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    ~stack() {
        delete[] arr;
    }
};

int evalRPN(vector<string>& tokens) {
    stack st(tokens.size());

    for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.Top();
            st.pop();
            int a = st.Top();
            st.pop();

            int result;
            if (token == "+") {
                result = a + b;
            } 
            else if (token == "-") {
                result = a - b;
            } 
            else if (token == "*") {
                result = a * b;
            } 
            else {
                result = a / b;
            }
            
            st.push(result);
        } 
        else {
            int num = 0;
            bool negative = false;
            int j = 0;
            
            if (token[0] == '-') {
                negative = true;
                j = 1;
            }
            
            for (; j < token.size(); j++) {
                num = num * 10 + (token[j] - '0');
            }

            if (negative) num = -num;
            st.push(num);
        }
    }
    
    return st.Top();
}

int main() {
    int n;
    cin >> n;
    vector<string> tokens(n);

    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    cout << evalRPN(tokens) << endl;

    return 0;
}
