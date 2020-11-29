#include "pch.h"

// メモリリークのキャプチャ
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CppUnitTest.h"
#include "../include/libsort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_MODULE_CLEANUP(test_module_cleanup) {
		Assert::IsFalse(_CrtDumpMemoryLeaks());// メモリリークチェック
	}

	TEST_CLASS(UnitTest)
	{
	public:

		// 一つだけの場合を検証する
		TEST_METHOD(TestMethod1)
		{
			list l;

			// 初期化
			initialize(&l);

			add_node(&l, 1, "hello world!");

			// ソート
			bubble_sort(&l);

			// 結果の検証
			Assert::AreEqual("hello world!", l.root->value);

			// 片付け
			finalize(&l);
		}

		// 2つの場合を検証する
		TEST_METHOD(TestMethod2)
		{
			list l;

			// 初期化
			initialize(&l);

			add_node(&l, 2, "world!");
			add_node(&l, 1, "hello");

			// ソート
			bubble_sort(&l);

			// 結果の検証
			int i = 0;
			for (node* p = l.root; p != NULL; p = p->next) {
				const static char* expected[] = {
					"hello" ,
					"world!" };
				Assert::AreEqual(expected[i], l.root->value);
				i++;
			}
			Assert::AreEqual(2, i);// 要素が2個で来ているはず

			// 片付け
			finalize(&l);
		}

		// 3つの場合を検証する
		TEST_METHOD(TestMethod3)
		{
			list l;

			// 初期化
			initialize(&l);

			add_node(&l, 2, "world");
			add_node(&l, 3, "!");
			add_node(&l, 1, "hello");

			// ソート
			bubble_sort(&l);

			// 結果の検証
			int i = 0;
			for (node* p = l.root; p != NULL; p = p->next) {
				const static char* expected[] = {
					"hello" ,
					"world",
					"!"};
			Assert::AreEqual(expected[i], l.root->value);
				i++;
			}
			Assert::AreEqual(3, i);// 要素が3個で来ているはず

			// 片付け
			finalize(&l);
		}
	};
}
