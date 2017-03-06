#include <stdio.h>

int main(void)
{
	int i, j;
	//int zahyou[203][203]; // int r[x座標][y座標]
	int rnum = 0;
	int bnum = 0;

	int x1, y1, r;
	int x2, y2, x3, y3;
	scanf("%d %d %d", &x1, &x2, &x3);
	scanf("%d %d %d %d", &x2, &y2, &x3, &y3);

	for (i = x1 - r; i <= x1 + r; i++)
	{
		for (j = y1 -r; j <= y1 + r; j ++)
		{
			if (((i - x1) * (i - x1)) + ((j - y1) * (j - y1)) <= r * r)
			{
				// 配列に入れる必要はない、一気に計算すれば楽
				if (x2 <= i <= x3 && y2 <= j <= y3)
				{
					bnum++;
				}else{
					rnum++;
				}
			}
		}
	}

	if (rnum > 0)
	{
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	if (bnum > 0)
	{
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
}