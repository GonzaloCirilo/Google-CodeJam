#include <stdio.h>
#include <math.h>

int main() {
	int ts; long long x, y, tx, ty;
	scanf("%d", &ts);
	for (int t = 1; t <= ts; t++) {
		scanf("%lld %lld", &x, &y);
		printf("Case #%d: ", t);
		if ((x + y) % 2 == 0 && (x || y)) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		tx = x, ty = y;
		long long ax = 0, ay = 0, e = 1;
		while (ax != x || ay != y) {
			int aux = abs(ax - x);
			if ((abs(ax - x) == e && abs(ay - y) == 0) || (abs(ay - y) == e && abs(ax - x) == 0)) {
				if (abs(ay - y) == 0) {
					if (x > ax) {
						ax += e;
						printf("E");
					}
					else {
						ax -= e;
						printf("W");
					}
				}
				else {
					if (y > ay) {
						ay += e;
						printf("N");
					}
					else {
						ay -= e;
						printf("S");
					}
				}

				continue;
			}


			if ((int)abs(tx) % 2 == 1) {
				long long dx = (tx + 1) / 2, dy = ty / 2;
				long long dax = ax + (e * -1);
				if ((int)abs(dx + dy) % 2 == 1) {
					tx = dx, ax = dax, ty = dy;
					printf("W");
					e *= 2;
					continue;
				}
				dx = (tx - 1) / 2;
				dax = ax + (e * 1);
				if ((int)abs(dx + dy) % 2 == 1) {
					tx = dx, ax = dax, ty = dy;
					printf("E");
				}

			}
			else if ((int)abs(ty) % 2 == 1) {
				long long dy = (ty + 1) / 2, dx = tx / 2;
				long long day = ay + (e * -1);
				if ((int)abs(dx + dy) % 2 == 1) {
					ty = dy, ay = day, tx = dx;
					printf("S");
					e *= 2;
					continue;
				}
				dy = (ty - 1) / 2;
				day = ay + (e * 1);
				if ((int)abs(dx + dy) % 2 == 1) {
					ty = dy, ay = day, tx = dx;
					printf("N");
				}
			}
			e *= 2;
		}
		printf("\n");
	}

	return 0;
}