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
			// 初期化
			array* a = create(1);

			a->nodes[0].key = 1; strcpy_s(a->nodes[0].value, 256, "hello world!");

			// ソート
			bubble_sort(a);

			// 結果の検証
			Assert::AreEqual("hello world!", a->nodes[0].value);

			// 片付け
			finalize(a);
		}

		// 2つの場合を検証する
		TEST_METHOD(TestMethod2)
		{
			// 初期化
			array* a = create(2);

			a->nodes[0].key = 2; strcpy_s(a->nodes[0].value, 256, "world!");
			a->nodes[1].key = 1; strcpy_s(a->nodes[1].value, 256, "hello");

			// ソート
			bubble_sort(a);

			// 結果の検証
			for (int i = 0; i < a->num; i++) {
				const static char* expected[] = {
					"hello" ,
					"world!" };
				Assert::AreEqual(expected[i], a->nodes[i].value);
			}

			// 片付け
			finalize(a);
		}

		// 3つの場合を検証する
		TEST_METHOD(TestMethod3)
		{
			// 初期化
			array* a = create(3);

			a->nodes[0].key = 3; strcpy_s(a->nodes[0].value, 256, "!");
			a->nodes[1].key = 2; strcpy_s(a->nodes[1].value, 256, "world");
			a->nodes[2].key = 1; strcpy_s(a->nodes[2].value, 256, "hello");

			// ソート
			bubble_sort(a);

			// 結果の検証
			for (int i = 0; i < a->num; i++) {
				const static char* expected[] = {
					"hello" ,
					"world",
					"!" };
				Assert::AreEqual(expected[i], a->nodes[i].value);
			}

			// 片付け
			finalize(a);
		}
	};
}
