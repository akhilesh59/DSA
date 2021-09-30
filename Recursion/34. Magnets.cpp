#include<bits/stdc++.h>
using namespace std;

int countInRow(vector<vector<char>>& ans, vector<int>& cnt_arr, char ch, int rowNo) {
    int count = 0;
    for(int col = 0; col < ans[0].size(); col++) {
        if(ans[rowNo][col] == ch) {
            count++;
        }
    }

    return count;
}

int countInCol(vector<vector<char>>& ans, vector<int>& cnt_arr, char ch, int colNo) {
    int count = 0;
    for(int row = 0; row < ans.size(); row++) {
        if(ans[row][colNo] == ch) {
            count++;
        }
    }

    return count;
}

bool isItSafe(vector<vector<char>>& ans, vector<int>& top, vector<int>& left, vector<int>& right, vector<int>& bottom, int r, int c, char ch) {

    if( ( (c-1 >= 0) && (ans[r][c-1] == ch) ) || ( (c+1 < ans[0].size()) && (ans[r][c+1] == ch) ) || ( (r-1 >= 0) && (ans[r-1][c] == ch) )) {

        return false;
    }

    if(ch == '+') {
        int cinr = countInRow(ans, left, ch, r);
        int cinc = countInCol(ans, top, ch, c);

        if(left[r] != -1 && cinr > left[r]) {
            return false;
        }
        if(top[c] != -1 && cinc > top[c]) {
            return false;
        }
    }
    else {
        int cinr = countInRow(ans, right, ch, r);
        int cinc = countInCol(ans, bottom, ch, c);

        if(right[r] != -1 && cinr > right[r]) {
            return false;
        }
        if(bottom[c] != -1 && cinc > bottom[c]) {
            return false;
        }
    }

    return true;
}

bool isAnsValid(vector<vector<char>>& ans, vector<int>& top, vector<int>& left, vector<int>& right, vector<int>& bottom) {

    for(int i=0; i<left.size(); i++) {
        int cinr = countInRow(ans, left, '+', i);
        if(left[i] != -1 && cinr != left[i]) {
            return false;
        }
    }

    for(int i=0; i<top.size(); i++) {
        int cinc = countInCol(ans, top, '+', i);
        if(top[i] != -1 && cinc != top[i]) {
            return false;
        }
    }

    for(int i=0; i<right.size(); i++) {
        int cinr = countInRow(ans, right, '-', i);
        if(right[i] != -1 && cinr != right[i]) {
            return false;
        }
    }

    for(int i=0; i<bottom.size(); i++) {
        int cinc = countInCol(ans, bottom, '-', i);
        if(bottom[i] != -1 && cinc != bottom[i]) {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>>& arr, vector<int>& top, vector<int>& left, vector<int>& right, vector<int>& bottom, vector<vector<char>>& ans, int r, int c) {

    if(c == arr[0].size()) {
        c = 0;
        r++;
    }
    if(r == arr.size()) {
        if(isAnsValid(ans, top, left, right, bottom) == true) {
            return true;
        }
    }

    if(arr[r][c] == 'L') {
        if(isItSafe(ans, top, left, right, bottom, r, c, '+') && isItSafe(ans, top, left, right, bottom, r, c+1, '-')) {
            ans[r][c] = '+';
            ans[r][c+1] = '-';

            if(solve(arr, top, left, right, bottom, ans, r, c+2) == true) {
                return true;
            }

            ans[r][c] = 'X';
            ans[r][c+1] = 'X';
        }

        if(isItSafe(ans, top, left, right, bottom, r, c, '-') && isItSafe(ans, top, left, right, bottom, r, c+1, '+')) {
            ans[r][c] = '-';
            ans[r][c+1] = '+';

            if(solve(arr, top, left, right, bottom, ans, r, c+2) == true) {
                return true;
            }

            ans[r][c] = 'X';
            ans[r][c+1] = 'X';
        }
    }

    else if(arr[r][c] == 'T') {
        if(isItSafe(ans, top, left, right, bottom, r, c, '+') && isItSafe(ans, top, left, right,        bottom, r+1, c, '-')) {
            ans[r][c] = '+';
            ans[r+1][c] = '-';

            if(solve(arr, top, left, right, bottom, ans, r, c+1) == true) {
                return true;
            }

            ans[r][c] = 'X';
            ans[r+1][c] = 'X';
        }

        if(isItSafe(ans, top, left, right, bottom, r, c, '-') && isItSafe(ans, top, left, right, bottom, r+1, c, '+')) {
            ans[r][c] = '-';
            ans[r+1][c] = '+';

            if(solve(arr, top, left, right, bottom, ans, r, c+1) == true) {
                return true;
            }

            ans[r][c] = 'X';
            ans[r+1][c] = 'X';
        }
    }

    // Call for NO

    bool callForNo = solve(arr, top, left, right, bottom, ans, r, c+1);
    if(callForNo == true) {
        return true;
    }

    return false;

}

int main() {
    int m,n; cin >> m >> n;

    vector<vector<char>> arr(m, vector<char>(n));

    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin >> arr[i][j];

    vector<int> top(n); 
    for(auto &i : top) cin >> i;

    vector<int> left(m); 
    for(auto &i : left) cin >> i;

    vector<int> right(m); 
    for(auto &i : right) cin >> i;

    vector<int> bottom(n); 
    for(auto &i : bottom) cin >> i;

    vector<vector<char>> ans(m, vector<char>(n, 'X'));

    if(solve(arr, top, left, right, bottom, ans, 0, 0)) {
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                cout << ans[i][j];
    }

    return 0;
}