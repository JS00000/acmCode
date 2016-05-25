// 作者：SimonS
// 链接：https://www.zhihu.com/question/29910524/answer/46075905
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#define MAX 1005
/*
计算从1-n范围内的SG值。
Array(存储可以走的步数，Array[0]表示可以有多少种走法)
Array[]需要从小到大排序
/*HDU1847博弈SG函数
1.可选步数为1-m的连续整数，直接取模即可，SG(x) = x % (m+1);
2.可选步数为任意步，SG(x) = x;
3.可选步数为一系列不连续的数，用GetSG(计算)
*/
int SG[MAX], hash[MAX];
void GetSG(int Array[], int n = MAX-1)
{
    memset(SG, 0, sizeof(SG));
    for(int i = 0; i <= n; ++i)
    {
        memset(hash, 0, sizeof(hash));
        for(int j = 1; j <= Array[0]; ++j)
        {
            if(i < Array[j]) break;
            hash[SG[i - Array[j]]] = 1;
        }
        for(int j = 0; j <= n; ++j)
            if(!hash[j])
            {
                SG[i] = j;
                break;
            }
    }
}