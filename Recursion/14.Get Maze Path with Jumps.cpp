#include<bits/stdc++.h>             // Correct, but sequence of the Outputs is not matching.
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
void getMazePaths(int sr, int sc, string op, int dr, int dc, vector<string>& ans) {

    if(sr == dr and sc == dc) {
        ans.push_back(op);
        return;
    }

    string op1 = "h";
    string op2 = "v";
    string op3 = "d";

    for(int move=1; move <= dr-sr; move++) {
        getMazePaths(sr+move,sc,op2 + to_string(move) + op,dr,dc,ans);
    }
    for(int move=1; move <= dc-sc; move++) {
        getMazePaths(sr,sc+move,op1 + to_string(move) + op,dr,dc,ans);
    }
    for(int move=1; move <= dr-sr and move <= dc-sc; move++) {
        getMazePaths(sr+move,sc+move,op3 + to_string(move) + op,dr,dc,ans);
    }

    // if(sr<dr) getMazePaths(sr+1,sc,op1,dr,dc,ans);
    // if(sc<dc) getMazePaths(sr,sc+1,op2,dr,dc,ans);

}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans;
    getMazePaths(0,0,"",n-1,m-1,ans);
    sort(ans.begin(), ans.end());
    display(ans);

    return 0;
}