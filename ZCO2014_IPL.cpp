#include <bits/stdc++.h>
using namespace std;
#define MIN(a, b, c) min(a, min(b,c))
#define MAX 200007
int dp[MAX], cost[MAX];
//Fast I/O
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
//Fast Input
inline int read(){
	int n=0;char c;

	while((c=getchar_unlocked())<48);
	n += (c - '0');
	while((c=getchar_unlocked())>=48)
		n = n*10 + (c - '0');

	return n;
}
//Solve Function
void solve() {
    //int days; cin >> days;
    int days; days =  read();
    int sum = 0;
    for(int i=0; i<days; i++) {
        cost[i] = read();
        sum+=cost[i];
    }
        
    dp[0] = cost[0];
    dp[1] = cost[1];
    dp[2] = cost[2];
    
    for(int i=3; i<days; i++) 
        dp[i] = cost[i] + MIN(dp[i-1], dp[i-2], dp[i-3]);
    
    //Answer = SumOfCost - SUPW_Answer
    //Answer = Total - Mininum earning
    int answer = sum - MIN(dp[days-1], dp[days-2], dp[days-3]);
    cout << answer << endl;
}
int main() {
    __fastio;
    solve();
    return 0;
}
