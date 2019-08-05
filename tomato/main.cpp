#include <iostream>
#include <queue>
using namespace std;

struct site
{
	int x, y,z;
};

int N, M, H;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
int map[101][101][101] = { 0 };
int visit[101][101][101] = { 0 };
queue<site> q;

bool inner(int x, int y, int z) {
	return x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H;
}

bool Check_Tom() {
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

void bfs() {
	int count=0;
	while (!q.empty()) {
		int qs = q.size();
		for (int l = 0; l < qs; l++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				if (inner(x + dx[i], y + dy[i], z + dz[i])) {
					if (map[x + dx[i]][y + dy[i]][z + dz[i]] == 0) {
						map[x + dx[i]][y + dy[i]][z + dz[i]] = 1;
						q.push({ x + dx[i],y + dy[i],z + dz[i] });
					}
				}
			}
			if (Check_Tom()==true && q.size() == 0) {
				cout << count << endl;
				return;
			}
			else if (Check_Tom() == false && q.size() == 0) {
				cout << -1 << endl;
				return;
			}
		}
		count++;
	}
}

int main() {
	bool check_T = false;
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
					q.push({ i,j,k });
				if (map[i][j][k] == 0) {
					check_T = true;
				}
			}
		}
	}

	if (check_T) {
		bfs();
	}
	else {
		cout << 0 << endl;
	}
	return 0;

}