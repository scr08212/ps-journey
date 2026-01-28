#include <stdio.h>

int main(void) {
	int d[3] = { 0 }, b = 0;
	scanf("%d %d %d", &d[0], &d[1], &d[2]);
	if (d[0] == d[1] && d[1] == d[2])
		printf("%d", 10000 + d[0] * 1000);
	else if (d[0] == d[1] || d[0] == d[2])
		printf("%d", 1000 + d[0] * 100);
	else if (d[1] == d[2])
		printf("%d", 1000 + d[1] * 100);
	else {
		for (int i = 0; i < 3; i++) {
			if (d[i] > b)
				b = d[i];
		}
		printf("%d",b*100);
	}
}