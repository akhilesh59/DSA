#include<bits/stdc++.h>

int students_req(vector<int>& v, int p) {
    int students = 1, n = v.size();
    int curr_student_sum = 0;
    
    for(int i=0; i<n; ++i) {
        if(v[i] + curr_student_sum <= p) {
            curr_student_sum += v[i];
        }
        else {
            ++students;
            curr_student_sum = v[i];
            if(curr_student_sum > p) return INT_MAX;
        }
    }
    return students;
    
}

int Solution::books(vector<int> &v, int b) {
    int ans = 0;
    if(b > v.size()) return -1;
    int low = 0;
    int high = accumulate(v.begin(), v.end(), 0);
    
    while(low <= high) {
        int mid = low + (high-low)/2;
        int x = students_req(v, mid);
        if(x <= b) {
            ans = mid;
            high = mid-1;
        }
        else if(x > b) low = mid+1;
        else high = mid-1;
    }
    
    return ans;
}
