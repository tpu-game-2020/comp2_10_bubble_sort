#include "Windows.h"                    // Windows API の機能(NULL)定義
#include <stdbool.h>
#include "../include/libsort.h"


// ソート
void bubble_sort(list* l)
{
	// ToDo: 実装してください
	l->head = NULL;
}


//
// リストの初期化
//
void initialize(list* t)
{
	t->head = NULL;
	t->tail = NULL;
}


//
// 使用メモリの全解放
//
void finalize(list* t)
{
	node* p = t->head;

	while (p)
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
	if (!p) return false;

	p->key = key;
	strcpy_s(p->value, 256, value);

	p->next = t->head;
	p->prev = NULL;
	if (t->head) {
		t->head->prev = p;
	}
	else {
		t->tail = p;
	}
	t->head = p;

	return true;
}


//
// ノードのprev要素の次への追加
//
void indert_next(list* l, node* p, node* prev)
{
	p->prev = prev;
	if (prev) {
		p->next = prev->next;
		prev->next = p;
	}
	else {
		p->next = NULL;
		l->head = p;
	}
}


//
// ノードのリストからの削除
//
void remove_node(list* l, node* p)
{
	// 前の要素の接続の変更
	if (p->prev) {
		p->prev->next = p->next;
	}
	else {
		l->head = p->next;
	}

	// 次の要素の接続の変更
	if (p->next) {
		p->next->prev = p->prev;
	}
	else {
		l->tail = p->prev;
	}

	// 自分の要素の接続の変更
	p->prev = NULL;
	p->next = NULL;
}
