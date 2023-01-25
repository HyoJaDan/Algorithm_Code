#include <iostream>

using namespace std;

int N, S, M;
int v_list[51] = {};
bool dp[51][1001] = {};

int solve() {
	dp[0][S] = true;;

	for (int i=1; i<=N; i++) {
		for (int j=0; j<=M; j++) {
			if (!dp[i-1][j]) continue;

			int up = j + v_list[i], down =  j - v_list[i];

			if (down >= 0) dp[i][down] = true;
			if (up <= M) dp[i][up] = true;
		}
	}
	
	int ret = -1;
	for (int i=0; i<=M; i++) {
		if (dp[N][i]) ret = i;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	cin >> N >> S >> M;
	for (int i=1; i<=N; i++) cin >> v_list[i];

	cout << solve() << "\n";
}
