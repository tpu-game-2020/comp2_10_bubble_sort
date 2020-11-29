#pragma once

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct node {
		int key;
		char value[256];
		struct node* next;
		struct node* prev;
	}node;

	typedef struct list {
		node* head;
		node* tail;
	}list;

	// ソート
	void bubble_sort(list* l);

	// リストの初期化
	void initialize(list* l);

	// 使用メモリの全解放
	void finalize(list* l);

	// keyの値を見てノードを追加する
	bool add_node(list* l, int key, const char* value);

	// ノードのprev要素の次への追加
	void indert_next(list* l, node* p, node* prev);
	// ノードのリストからの削除
	void remove_node(list* l, node* p);



	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
