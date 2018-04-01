#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n, m, p, q;
string str;
vector<pair<int,int>> v;
int main() {
	cin >> n>> m;
	for(int i =0; i< n; i++){
		cin >> str;
		if (str == "order") {
			scanf("%d %d", &p, &q);
			v.push_back({ p,q });
			for (int j = 0; j < v.size(); j++) {
				printf("%d ", v[j].first);
			}
			printf("\n");
		}
		else if (str == "sort") {
			if (v.size() == 0) {
				printf("sleep\n");
			}
			else {
				sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int>b) {
					if (a.second != b.second)return a.second < b.second;
					else {
						return a.first < b.first;
					}
				});
				for (int j = 0; j < v.size(); j++) {
					printf("%d ", v[j].first);
				}
				printf("\n");
			}
			
		}
		else if (str == "complete") {
			scanf("%d", &p);

			for (int j = 0; j < v.size(); j++) {
				if (v[j].first == p) {
					v.erase(v.begin() + j);

					if (v.size() == 0) {
						printf("sleep\n");
					}
					else {
						for (int k = 0; k < v.size(); k++) {
							printf("%d ", v[k].first);
						}
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}