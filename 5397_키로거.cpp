// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     while(n--) {
//         list<char> L; //vector를 썼으면 앞으로 삭제시 당겨짐
//         list<char>::iterator cursor = L.begin();
//         string s;
//         cin >> s;

//         int len = s.size(), i = 0;

//         //auto cursor = L.begin();
//         while(i < len) {
//             if(s[i] == '-') {
//                 if(cursor != L.begin()) {
//                     cursor--;
//                     L.erase(cursor);
//                 }
//             } else if(s[i] == '<') {
//                 if(cursor != L.begin()) {
//                     cursor--;
//                 }
//             } else if(s[i] == '>') {
//                 if(cursor != L.end()) {
//                     cursor++;
//                 }
//             } else {
//                 L.insert(cursor, s[i]);
//             }
//             i++;
//         }

//         for(auto c : L) {
//             cout << c;
//         }
//         cout << "\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T; 
    while (T--) {
        string L; cin >> L;
        list<char> ans;
        list<char>::iterator ans_iter = ans.begin();
        int L_len = L.size(), L_idx = 0;
 
        while (L_idx < L_len) {
            switch (L[L_idx]) {
            case '<':
                if (ans_iter != ans.begin()) ans_iter--;
                break;
            case '>':
                if (ans_iter != ans.end()) ans_iter++;
                break;
            case '-':
                if (ans_iter != ans.begin())  ans.erase((--ans_iter)++);
                break;
            default:
                ans.insert(ans_iter, L[L_idx]);
                break;
            }
            L_idx++;
        }
        for (auto x : ans) printf("%c", x);
        printf("\n");
    }
    return 0;
}
