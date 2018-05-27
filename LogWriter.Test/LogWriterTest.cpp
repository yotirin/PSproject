#include "CppUnitTest.h"
#include "LogWriter.h"
#include "LogWriterTest.h"
#include "TypeDefine.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace LogWriter;

namespace LogWriterTest
{
	string inputLog1;
	string inputLog2;
	string inputLog3;
	
	void TestWriteMethod1(string log) 
	{
		inputLog1 = log;
	}

	void TestWriteMethod2(string log)
	{
		inputLog2 = log;
	}

	void TestWriteMethod3(string log)
	{
		inputLog3 = log;
	}

	TEST_CLASS(単体テスト_LogWriter)
	{
	private:
		const LogType AllLogType[3] = 
		{
			LogType::InformationLog,
			LogType::WarningLog,
			LogType::ErrorLog,
		};

	public:
		TEST_METHOD_INITIALIZE(テストごとの初期化処理)
		{
			AllWriteMethodClear();
			inputLog1 = NULL;
			inputLog2 = NULL;
			inputLog3 = NULL;
		}

		TEST_METHOD(LogWrite_情報ログに書き込まれていること)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite(LogType::InformationLog, "Test");

			// 戻り値は成功
			Assert::AreEqual((int)result, (int)Result::Success);

			Assert::AreEqual(inputLog1, "Test");
			Assert::IsNull(inputLog2);
			Assert::IsNull(inputLog3);
		}

		TEST_METHOD(LogWrite_警告ログに書き込まれていること)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite(LogType::WarningLog, "Test");

			// 戻り値は成功
			Assert::AreEqual((int)result, (int)Result::Success);

			Assert::IsNull(inputLog1);
			Assert::AreEqual(inputLog2, "Test");
			Assert::IsNull(inputLog3);
		}

		TEST_METHOD(LogWrite_エラーログに書き込まれていること)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite(LogType::ErrorLog, "Test");

			// 戻り値は成功
			Assert::AreEqual((int)result, (int)Result::Success);

			Assert::IsNull(inputLog1);
			Assert::IsNull(inputLog2);
			Assert::AreEqual(inputLog3, "Test");
		}

		TEST_METHOD(LogWrite_設定していない場合はログを書き込まないこと)
		{
			for each (LogType type in AllLogType)
			{
				Result result = LogWrite(type, "Test");

				// 戻り値は成功
				Assert::AreEqual((int)result, (int)Result::Success);

				Assert::IsNull(inputLog1);
				Assert::IsNull(inputLog2);
				Assert::IsNull(inputLog3);
			}
		}

		TEST_METHOD(LogWrite_範囲外の型を設定した場合はエラーが帰る)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite((LogType)-1, "test");

			// 戻り値は失敗
			Assert::AreEqual((int)result, (int)Result::NotingType);

			// どのログに書かれていないことを確認
			Assert::IsNull(inputLog1);
			Assert::IsNull(inputLog2);
			Assert::IsNull(inputLog3);
		}

		TEST_METHOD(SetLogWriteMethod_各WriteMethodに値が設定できる)
		{
			for each (LogType type in AllLogType)
			{
				Result result = SetLogWriteMethod(type, TestWriteMethod1);

				// 戻り値は成功
				Assert::AreEqual((int)result, (int)Result::Success);

				// 設定の確認
				LogWriteMethod setMethod = GetLogWriteMethod(type);
				Assert::AreEqual((void*)setMethod, (void*)TestWriteMethod1);
			}
		}

		TEST_METHOD(SetLogWriteMethod_範囲外の型を設定した場合はエラーが帰る)
		{
			Result result = SetLogWriteMethod((LogType)-1, TestWriteMethod1);

			// 戻り値は失敗
			Assert::AreEqual((int)result, (int)Result::NotingType);

			// 全ての設定の確認
			for each (LogType type in AllLogType)
			{
				LogWriteMethod setMethod = GetLogWriteMethod(type);
				Assert::IsNull((void*)setMethod);
			}
		}
	};
}
