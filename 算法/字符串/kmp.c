#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNext(int *next, char *pstr);
int kmp(char* str, char* pstr, int* next);
int main(int argc, char const *argv[])
{
	char str[100];
	char pstr[50];
	int *next;

	scanf("%s", str);
	scanf("%s", pstr);

	if (strlen(str) < strlen(pstr))
	{	
		printf("pstr is too long\n");
	} 
	else if (strlen(str) == strlen(pstr))
	{
		if (!strcmp(str, pstr))
		{
			printf("pstr equals str\n");
		}
		else
		{
			printf("pstr doesn't equal str\n");
		}
	}
	else
	{
		next = new int[strlen(pstr)];
		getNext(next, pstr);

		int index = kmp(str, pstr, next);
		printf("%d\n", index);
		/**
		 * 验证
		 */
		if (index < 0)
		{
			return 0;
		}
		for (int i = index, j = 0; j < strlen(pstr); i++, j++)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}

	return 0;
}

void getNext(int *next, char *pstr)
{
	int length = strlen(pstr);

	next[0] = -1;//初始化next
	next[1] = 0;
	for (int i = 2; i < length; ++i)
	{
		int j = i - 1;	//初始化待比较的下标
		int k = j;

		//递归比较
		while(1) {
			/**
			 * k!=0，表示next[k]有意义
			 * 因为p[0]-p[next[k]-1]肯定等于p[j-next[k]]-p[j-1]
			 * 所以只要p[next[k]] == p[j]，则next[j+1] = next[k] + 1
			 */
		    if (k && pstr[j] == pstr[next[k]])
			{
				next[i] = next[k] + 1;
				break;
			}
			else if (!k) 
			{
				next[i] = 0;
				break;
			}
			else if(pstr[j] != pstr[next[k]])
			{
				k = next[k];
			}
		}
	}
}
void getNext2(int *next, char *pstr)
{
	// 简化写法
	int length = strlen(pstr);
	int j = 0, k = next[j];
	next[0] = -1;

	/**
	 * 与求getNext的区别：
	 * 其实一开始就令k = next[j]，然后每次加（k+1）就相当于上面next[k] + 1
	 */
	while(j < length) 
	{
		if (k == -1 || pstr[j] = pstr[k])
		{
			next[j++] = k++;
		}
	    else
	    {
	    	k = next[k];
	    }
	}
}
int kmp(char* str, char* pstr, int* next)
{
	int i = 0, j = 0;
	/**
	 * 1.初始化：i为原串下标，j为模式串下标
	 * 2.如果i < 模式串长度，继续比较(3)，否则退出返回-1
	 * 3.如果j == -1代表完全失配，i往后移，j置0重新来
	 * 4.如果当前str[i] == pstr[j]，代表当前可配对，i和j均向后移一位
	 * 		4.1如果模式串已经匹配完成，则可以返回，否则继续匹配
	 * 5.如果3和4均不满足，意味着当前匹配失败，模式串移动至next[j]位置，原串不动，继续匹配
	 */
	while(i < strlen(str))
	{
		if (j == -1 || str[i] == pstr[j])
		{
			i++, j++;
			if (j == strlen(pstr))
			{
				return i - j;
			}
		}
		else
		{
			j = next[j];
		}
	}
	return -1;
}