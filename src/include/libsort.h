#pragma once

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct node {
		int key;
		char value[256];
		struct node* next;
	}node;

	typedef struct list {
		node* root;
	}list;

	// ソート
	void bubble_sort(list* l);

	// リストの初期化
	void initialize(list* t);

	// 使用メモリの全解放
	void finalize(list* t);

	// keyの値を見てノードを追加する
	bool add_node(list* t, int key, const char* value);



	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif