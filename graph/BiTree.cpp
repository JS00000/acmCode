#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <cmath>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define INFEASIBLE -1

#ifndef OVERFLOW
#define OVERFLOW -2
#endif

using namespace std;


typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int CreateBiTree(BiTree &T)
{
	TElemType c;
	scanf("%c", &c);
	if (c == '@' || c == ' ')
		T = NULL;
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

int PrintElement(TElemType e)
{
	printf("%c", e);
	return OK;
}

int PreOrderTraverse(BiTree T, int(* Visit)(TElemType e))
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}

int InOrderTraverse(BiTree T, int(* Visit)(TElemType e))
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}

int PostOrderTraverse(BiTree T, int(* Visit)(TElemType e))
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data)) return OK;
		return ERROR;
	}
	else return OK;
}

int sum;
int OutputLeafNode(BiTree T, int(* Visit)(TElemType e))
{
	if (T)
	{
		bool flag = 1;
		if (OutputLeafNode(T->lchild, Visit) != OVERFLOW) flag = 0;
		if (OutputLeafNode(T->rchild, Visit) != OVERFLOW) flag = 0;
		if (flag)
		{
			Visit(T->data);
			sum++;
			return OK;
		}
		return ERROR;
	}
	else return OVERFLOW;
}

int GetBiTDeep(BiTree T)
{
	if (!T) return 0;
	int deepL = GetBiTDeep(T->lchild);
	int deepR = GetBiTDeep(T->rchild);
	if (deepL < deepR) return deepR + 1;
	else return deepL + 1;
}

int LevelOrderTraverse(BiTree T, int(* Visit)(TElemType e))
{
	queue<BiTree> q;
	q.push(T);
	while(!q.empty())
	{
		BiTree it = q.front();
		Visit(it->data);
		q.pop();
		if (it->lchild) q.push(it->lchild);
		if (it->rchild) q.push(it->rchild);
	}
	return OK;
}


TElemType comp[33];
char mp[32][64];

int defComp(int j, TElemType e)
{
	comp[j] = e;
	return OK;
}
int toCompBiTree(BiTree T, int i, int(* Visit)(int j, TElemType e))
{
	if (T)
	{
		if (Visit(i, T->data))
			if (toCompBiTree(T->lchild, i*2, Visit))
				if (toCompBiTree(T->rchild, i*2+1, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}

void init(int deep, int width)
{
	for (int i = 0; i < pow(2, deep); ++i)
		for (int j = 0; j < width; ++j)
			mp[i][j] = ' ';
	for (int i = 1; i < pow(2, deep); ++i)
		comp[i] = ' ';
}

int ShowBinaryTree(BiTree T)
{
	int deep = GetBiTDeep(T);
	if (deep > 5)
	{
		printf("The tree is too high.\n");
		return INFEASIBLE;
	}
	int width = 4 * pow(2, deep - 1);
	// printf("width is %d\n", width);
	init(deep,width);
	toCompBiTree(T, 1, defComp);
	// for (int i = 1; i < pow(2, deep); ++i)
	// {
	// 	cout << comp[i];
	// }
	// cout << endl;
	int y = 0;
	int dx = width, fx = width/2, x = fx;
	for (int i = 1; i < pow(2, deep); ++i)
	{
		if (i == 2 || i == 4 || i == 8 || i == 16)
		{
			y += pow(2, deep - int(log(i)/log(2)));
			dx = dx/2;
			fx = fx/2;
			x = fx;
		}
		mp[y][x] = comp[i];
		if (comp[i] != ' ')
		{
			int tx = x, ty = y;
			if (i & 1)
			{
				while(--ty >= 0 && --tx >= 0 && mp[ty][tx] == ' ')
				{
					mp[ty][tx] = '\\';
				}
			}
			else
			{
				while(--ty >= 0 && ++tx <= width && mp[ty][tx] == ' ')
				{
					mp[ty][tx] = '/';
				}
			}
		}
		x += dx;
	}
	for (int i = 0; i < pow(2, deep); ++i)
	{
		for (int j = 0; j < width; ++j)
			cout << mp[i][j];
		cout << endl;
	}
	return OK;
}


int main(int argc, char const *argv[])
{
	BiTree T;
	CreateBiTree(T);
	printf("Pre order traverse is: \n	");
	PreOrderTraverse(T, PrintElement);
	printf("\n");

	printf("In order traverse is: \n	");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	printf("Post order traverse is: \n	");
	PostOrderTraverse(T, PrintElement);
	printf("\n");

	sum = 0;
	printf("Leaf Nodes is: \n	");
	OutputLeafNode(T, PrintElement);
	printf("\n	There are %d Leaf Nodes\n", sum);

	printf("The deep of BiTree is %d\n", GetBiTDeep(T));

	printf("Level order traverse is: \n	");
	LevelOrderTraverse(T, PrintElement);
	printf("\n");

	ShowBinaryTree(T);

	return 0;
}
