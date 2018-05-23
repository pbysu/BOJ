#include<cstdio>
#include<queue>	
#include<algorithm>

using namespace std;

int input[101][101];
bool visited[101][101][4];
int n, m;
int sr, sc, sd;
int er, ec, ed;

pair<int, int> dir[4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };


int bfs(int r, int c, int d) {

	queue<pair<int, pair<int, int>>> q;

	q.push({ d, { r,c } });

	pair<int, pair<int, int>> temp;

	int sizeOfq;
	int ans = 0;
	int td1, td2;
	int tr, tc, ttr, ttc, tttr, tttc;
	while (!q.empty()) {

		sizeOfq = q.size();

		while (sizeOfq--) {
			temp = q.front();
			q.pop();

			if (er == temp.second.first && ec == temp.second.second
				&& ed == temp.first)
				return ans;

			tr = temp.second.first + dir[temp.first].first;
			tc = temp.second.second + dir[temp.first].second;

			if (tr <= n && tr > 0 && tc > 0 && tc <= m &&
				!visited[tr][tc][temp.first] && input[tr][tc] == 0) {

				q.push({ temp.first,{ tr, tc} });
				visited[tr][tc][temp.first] = true;
			}


			ttr = tr+ dir[temp.first].first;
			ttc = tc+ dir[temp.first].second;

			if (ttr <= n && ttr > 0 && ttc > 0 && ttc <= m &&
				!visited[ttr][ttc][temp.first] &&
				input[tr][tc] == 0 && input[ttr][ttc]==0) {

				q.push({ temp.first,{ ttr, ttc } });
				visited[tr][tc][temp.first] = true;
			}

			tttr = ttr + dir[temp.first].first;
			tttc = ttc + dir[temp.first].second;

			if (tttr <= n && tttr > 0 && tttc > 0 && tttc <= m &&
				!visited[tttr][tttc][temp.first] && input[tttr][tttc] == 0
				&& input[tr][tc] == 0 && input[ttr][ttc] == 0) {

				q.push({ temp.first, {tttr,tttc } });
				visited[tr][tc][temp.first] = true;
			}



			tr = temp.second.first;
			tc = temp.second.second;

			if (temp.first < 2) {
				td1 = 3;
				td2 = 2;
			}

			else {
				td1 = 1;
				td2 = 0;
			}

			if (!visited[temp.second.first][temp.second.second][td1]) {
				visited[temp.second.first][temp.second.second][td1] = true;
				q.push({ td1,{temp.second } });
			}
			if (!visited[temp.second.first][temp.second.second][td2]) {
				visited[temp.second.first][temp.second.second][td2] = true;
				q.push({ td2,{temp.second} });
			}
		}
		ans++;
	}

}


int main() {


	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	scanf("%d %d %d", &sr, &sc, &sd);
	scanf("%d %d %d", &er, &ec, &ed);

	sd--;
	ed--;


	printf("%d\n", bfs(sr, sc, sd));

	return 0;
}