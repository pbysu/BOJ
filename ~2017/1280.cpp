#include<iostream>
#include<algorithm>
#define reminder 1000000007
using namespace std;
typedef long long ll;
int n;
ll val;
pair<ll, ll> seg[800400];
 
 
pair<ll, ll> update(ll pos, int node, int x, int y) {
    if (pos<x || pos >y) {
        return seg[node];
    }
 
    if (x == y) {
        return seg[node] = { (seg[node].first + pos) % reminder, seg[node].second + 1 };
    }
    int mid = (x + y) >> 1;
    pair<ll, ll> left = update(pos, node * 2, x, mid);
    pair<ll, ll> right = update(pos, node * 2 + 1, mid + 1, y);
 
    return seg[node] = { (left.first % reminder + right.first % reminder) % reminder, right.second + left.second };
}
 
 
pair<ll, ll> query(int lo, int hi, int node, int x, int y) {
    if (lo > y || hi < x) {
        return{ 0, 0 };
    }
 
    if (lo <= x && y <= hi) return seg[node];
 
    int mid = (x + y) >> 1;
 
    pair<ll, ll> left = query(lo, hi, node * 2, x, mid);
    pair<ll, ll> right = query(lo, hi, node * 2 + 1, mid+1, y);
 
    return{ (left.first% reminder + right.first% reminder) % reminder,
        left.second + right.second };
 
}
 
 
 
int main() {
    scanf("%d", &n);
 
    scanf("%lld", &val);
    update(val, 1, 0, 200000-1);
 
    ll leftSum, leftCnt, rightSum, rightCnt;
    ll sum = 0;
    ll ans = 1;
    pair<ll, ll> temp;
    bool check = true;
    ll tem = val;
    for (int i = 1; i < n; i++) {
         
        scanf("%lld", &val);
        if (check && tem != val) {
            check = false;
        }
        temp = query(0, val, 1, 0, 200000-1);
        leftSum = temp.first;
 
        if (leftSum < 0) leftSum += reminder;
 
        leftCnt = temp.second;
 
        temp = query(val + 1, 200000-1, 1, 0, 200000-1);
        rightSum = temp.first;
 
        if (rightSum < 0) rightSum += reminder;
        rightCnt = temp.second;
 
 
        update(val, 1, 0, 200000-1);
 
        sum = (
            ((leftCnt*val)%reminder + reminder - leftSum) % reminder
            + (rightSum + reminder - (rightCnt*val)%reminder) % reminder
            ) % reminder;
 
        if(sum)
            ans = (ans*sum) % reminder;
    }
 
    if (check) printf("0\n");
    else    printf("%lld", ans);
 
    return 0;
}