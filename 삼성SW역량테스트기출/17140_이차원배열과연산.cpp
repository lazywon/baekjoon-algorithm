#include<bits/stdc++.h>
using namespace std;

int r, c, k, result;
int arr[4][4];
int num[101];
vector<vector<int> > table;
int rowSize, colSize;

int calculate(int row, int col) {
    if(row >= col) {
        //R연산
        int n = 0;
        int max = 0;
        for(int i=0;i<row;i++) {
            if(n > max) max = n;
            for(int j=0;j<col;j++) {
                for(int k=0;k<101;k++) {
                    if(k == table[i][j]) {
                        num[k] = 1;
                    }
                }
            }
            for(int j=0;j<101;j++) {
                if(num[j] == 1) n += 1;
            }
        }
    } else { 
        //C연산

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;
    // for(int i=1;i<=3;i++) {
    //     for(int j=1;j<=3;j++) {
    //         cin >> arr[i][j];
    //     }
    // }

    for(int i=0;i<3;i++) {
        vector<int> element(3);
        int a;
        for(int j=0;j<3;j++) {
            cin >> element[j];
        }
        table.push_back(element);
    }

    for(int i=0;i<101;i++) {
        num[i] = i;
    }

    rowSize = table.size();
    colSize = 3;
    
    for(int t=0;t<=100;t++) {
        result = t;
        if(table[r-1][c-1] == k) {
            cout << result << "\n";
            break;
        }
        
        //연산
        calculate(rowSize, colSize);

        

    }

    if(result > 100) {
        cout << "-1\n";
    }

    return 0;
}