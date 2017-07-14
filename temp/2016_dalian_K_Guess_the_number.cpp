#include <iostream>
#include <stdint.h>
#include <inttypes.h>
#include <algorithm>
#define Maxn 5000005
#define Mod_Num 100000073
using namespace std;
typedef int64_t inta;
const bool Output_flag = true;
inta many_Time[Maxn+5];
inta many_Acti[Maxn+5];
void init()
{
	memset(many_Time, 0, sizeof(many_Time));
	memset(many_Acti, 0, sizeof(many_Acti));
}
int64_t max(inta a,inta b) 
{
    if (a > b) return a;
	return b; 
}
int main()
{
    init();
    inta *p = many_Time;
    inta *q = many_Acti;
    p[1] = 1;p[0] = 0;
    q[1] = 1;q[0] = 1;
    int32_t i, j, t, total_num, pre_total_num;
    i = 2; j = 2; pre_total_num = 1;
    while (j < Maxn) 
    {
        t = i;
        total_num = pre_total_num + 1;
        total_num %= Mod_Num;
        pre_total_num = 0;
        while (j < Maxn && t--) {
            p[j] = i;
            q[j] = total_num;
            total_num = (total_num - q[j - i] + Mod_Num) % Mod_Num;
            pre_total_num += q[j];
            pre_total_num %= Mod_Num;
            j++;
		}
		i++;
	}
	for (i = 0; i < 100; i++)
		printf("%d:	p:%lld	q:%lld\n", i, p[i], q[i]);
    // int32_t a, b;
    // while (scanf("%d%d",&a,&b)!=EOF)
        // printf("%" PRId64 " %" PRId64 "\n",p[b-a+1],q[b-a+1]);
    return 0;
}
