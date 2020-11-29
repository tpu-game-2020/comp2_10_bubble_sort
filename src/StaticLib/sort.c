#include "Windows.h"                    // Windows API の機能(NULL)定義
#include <stdbool.h>
#include "../include/libsort.h"


// ソート
void bubble_sort(list* l)
{
	// ToDo: 実装してください
	l->root = NULL;
}


//
// リストの初期化
//
void initialize(list* t)
{
	t->root = NULL;
}

//
// 使用メモリの全解放
//
void finalize(list* t)
{
	node* p = t->root;

	while (p != NULL)
	{
		node* n = p->next;
		free(p);
		p = n;
	}
}

//
// keyの値を見てノードを追加する
//
bool add_node(list* t, int key, const char* value)
{
	node* p = (node*)malloc(sizeof(node));
	if (p == NULL) return false;

	p->key = key;
	strcpy_s(p->value, 256, value);

	return true;
}
