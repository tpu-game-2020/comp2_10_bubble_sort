#pragma once

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct node {
		int key;
		char value[256];
	}node;

	typedef struct array {
		int    num;
		node*  nodes;
	}array;

	// 配列の初期化
	array *create(int num);

	// 使用メモリの全解放
	void finalize(array* a);

	// ソート
	void bubble_sort(array* a);


	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
