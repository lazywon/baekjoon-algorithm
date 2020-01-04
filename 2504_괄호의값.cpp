/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<int> st;

    // '(' -> -1
    // '[' -> -2

    int result = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') {
            st.push(-1);
        }
        else if(s[i] == '[') {
            st.push(-2);
        }
        else if(s[i] == ')') {
            if(st.empty()) {
                st.push(-100);
                //cout << 0 << "\n";
                break;
            }
            else {
                if(st.top() == '(') {
                    st.pop();
                    st.push(2);
                }
                else { //top이 숫자일때 숫자와 곱해준다.
                    int tmp = st.top();
                    st.pop();
                    if(st.top() == '(') {
                        st.push(tmp * 2);
                    }
                }
            }
        }
        else {
            if(st.empty()) {
                st.push(-100);
                //cout << 0 << "\n";
                break;
            }
            else {
                if(st.top() == '[') {
                    st.pop();
                    st.push(3);
                }
                else { //top이 숫자일때 숫자와 곱해준다.
                    int tmp = st.top();
                    st.pop();
                    if(st.top() == '[') {
                        st.push(tmp * 3);
                    }
                }
            }
        }
        if(st.top() > 0) {
            int val = 0;
            //st.pop();
            while(st.top() > 0) {
                val += st.top();
                st.pop();
            }

            st.push(val);
        }

    }

    result = st.top();
    st.pop();

    if(!st.empty()) {
        cout << 0 << "\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    stack<char> st;
    int tmp = 1;
    int sum = 0;

    cin >> s;

    for(int i=0;i<s.size();i++) {
        switch(s[i]) {
            case '(':
                tmp *= 2;
                st.push('(');
                break;
            case '[':
                tmp *= 3;
                st.push('[');
                break;
            case ')':
                if(s[i-1] == '(')
                    sum += tmp;
                if(st.empty()) 
                    return !cout << 0;
                    //st.push(-1);
                    //break;
                if(st.top() == '(')
                    st.pop();
                tmp /= 2;
                break;
            case ']':
                if(s[i-1] == '[')
                    sum += tmp;
                if(st.empty())
                    return !cout << 0;
                    //st.push(-1);
                    //break;
                if(st.top() == '[')
                    st.pop();
                tmp /= 3;
        }
    }

    if(st.empty()) {
        cout << sum << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
*/

#include <stdio.h>
#include <stack>
using namespace std;

int sum, tmp = 1;
char str[33];
stack<char> stk;

//[[()]]
//[[(
int main() {
    scanf("%s", str + 1);

    for (int i = 1; str[i]; i++) {
        switch (str[i]) {
        case '(':
            tmp *= 2, stk.push('('); break;
        case '[':
            tmp *= 3, stk.push('['); break;
        case ')':
            if (str[i - 1] == '(') sum += tmp;
            if (stk.empty()) return !printf("0");
            if (stk.top() == '(') stk.pop();
            tmp /= 2; break;
        case ']':
            if (str[i - 1] == '[') sum += tmp;
            if (stk.empty()) return !printf("0");
            if (stk.top() == '[') stk.pop();
            tmp /= 3;
        }
    }

    printf("%d", stk.empty() ? sum : 0);

    return 0;
}