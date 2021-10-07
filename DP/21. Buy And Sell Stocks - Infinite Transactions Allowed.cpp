#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    
    int prev = -1;
    int least = INT_MAX;
    int profit = 0;
    int total_profit = 0;
    
    for(auto i : v) {
        if(i < least || i < prev) {
            if(prev != -1) {
                profit = prev - least;
                total_profit += profit;
                prev = -1;
                // cout<<"profit : "<<profit<<"\n";
            }
            least = i;
            // cout<<"least : "<<least<<"\n";
        }
        else {
            prev = i;
            // cout<<"prev : "<<prev<<"\n";
        }
    }
    
    if(prev > least) total_profit += prev-least;
    // The above is done bcz may be last me graph upar hi jata jaaye
    // and dip hi naa aaye to last increase wala profit nhi collect ho 
    // payega, to usko last me collect kar lenge alag se, agar exist karta hai to
    
    cout<<total_profit<<"\n";
    
    return 0;
}