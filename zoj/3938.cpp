#include <cstdio>

using namespace std;
typedef long long LL;

int a;
int b[5], pos[5], lab[5];

int main(int argc, char const *argv[])
{
	LL t;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%d %d %d %d %d", &a, &b[1], &b[2], &b[3], &b[4]);
		switch (a)
		{
			case 1:
				pos[0] = 2;
				lab[0] = b[2];
				break;
			case 2:
				pos[0] = 2;
				lab[0] = b[2];
				break;
			case 3:
				pos[0] = 3;
				lab[0] = b[3];
				break;
			case 4:
				pos[0] = 4;
				lab[0] = b[4];
				break;
			default: break;
		}
		printf("%d %d\n", pos[0], lab[0]);

		scanf("%d %d %d %d %d", &a, &b[1], &b[2], &b[3], &b[4]);
		switch (a)
		{
			case 1:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == 4)
						pos[1] = i;
				lab[1] = 4;
				break;
			case 2:
				pos[1] = pos[0];
				lab[1] = b[pos[0]];
				break;
			case 3:
				pos[1] = 1;
				lab[1] = b[1];
				break;
			case 4:
				pos[1] = pos[0];
				lab[1] = b[pos[0]];
				break;
			default: break;
		}
		printf("%d %d\n", pos[1], lab[1]);

		scanf("%d %d %d %d %d", &a, &b[1], &b[2], &b[3], &b[4]);
		switch (a)
		{
			case 1:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == lab[1])
					{
						pos[2] = i;
						lab[2] = lab[1];
					}
				break;
			case 2:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == lab[0])
					{
						pos[2] = i;
						lab[2] = lab[0];
					}
				break;
			case 3:
				pos[2] = 3;
				lab[2] = b[3];
				break;
			case 4:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == 4)
						pos[2] = i;
				lab[2] = 4;
				break;
			default: break;
		}
		printf("%d %d\n", pos[2], lab[2]);

		scanf("%d %d %d %d %d", &a, &b[1], &b[2], &b[3], &b[4]);
		switch (a)
		{
			case 1:
				pos[3] = pos[0];
				lab[3] = b[pos[0]];
				break;
			case 2:
				pos[3] = 1;
				lab[3] = b[1];
				break;
			case 3:
				pos[3] = pos[1];
				lab[3] = b[pos[1]];
				break;
			case 4:
				pos[3] = pos[1];
				lab[3] = b[pos[1]];
				break;
			default: break;
		}
		printf("%d %d\n", pos[3], lab[3]);

		scanf("%d %d %d %d %d", &a, &b[1], &b[2], &b[3], &b[4]);
		switch (a)
		{
			case 1:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == lab[0])
					{
						pos[4] = i;
						lab[4] = lab[0];
					}
				break;
			case 2:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == lab[1])
					{
						pos[4] = i;
						lab[4] = lab[1];
					}
				break;
			case 3:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == lab[3])
					{
						pos[4] = i;
						lab[4] = lab[3];
					}
				break;
			case 4:
				for (int i = 1; i <= 4; ++i)
					if (b[i] == lab[2])
					{
						pos[4] = i;
						lab[4] = lab[2];
					}
				break;
			default: break;
		}
		printf("%d %d\n", pos[4], lab[4]);
	}	
	return 0;
}