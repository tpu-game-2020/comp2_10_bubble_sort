#include "Windows.h"                    // Windows API の機能(NULL)定義
#include <stdbool.h>
#include "../include/libsort.h"


// ソート
void bubble_sort(array* a)
{
	// ToDo: 実装してください
	//a->nodes = NULL;
	for (int j = 0; j < a->num - 1; j++)
	{
		for (int i = a->num - 1; i > j; i--)
		{
			if (a->nodes[i].key < a->nodes[i - 1].key)
			{
				//入れ替え
				node temp = a->nodes[i];
				a->nodes[i] = a->nodes[i - 1];
				a->nodes[i - 1] = temp;
			}
		}
	}
}


//
// 配列の初期化
//
array* create(int num)
{
	array* a = (array*)malloc(sizeof(array));
	if (a == NULL) return NULL;

	a->num = num;
	a->nodes = (node*)malloc(sizeof(node) * num);

	return a;
}


//
// 使用メモリの全解放
//
void finalize(array* a)
{
	free(a->nodes);
	free(a);
}
