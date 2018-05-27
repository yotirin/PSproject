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

	TEST_CLASS(�P�̃e�X�g_LogWriter)
	{
	private:
		const LogType AllLogType[3] = 
		{
			LogType::InformationLog,
			LogType::WarningLog,
			LogType::ErrorLog,
		};

	public:
		TEST_METHOD_INITIALIZE(�e�X�g���Ƃ̏���������)
		{
			AllWriteMethodClear();
			inputLog1 = NULL;
			inputLog2 = NULL;
			inputLog3 = NULL;
		}

		TEST_METHOD(LogWrite_��񃍃O�ɏ������܂�Ă��邱��)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite(LogType::InformationLog, "Test");

			// �߂�l�͐���
			Assert::AreEqual((int)result, (int)Result::Success);

			Assert::AreEqual(inputLog1, "Test");
			Assert::IsNull(inputLog2);
			Assert::IsNull(inputLog3);
		}

		TEST_METHOD(LogWrite_�x�����O�ɏ������܂�Ă��邱��)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite(LogType::WarningLog, "Test");

			// �߂�l�͐���
			Assert::AreEqual((int)result, (int)Result::Success);

			Assert::IsNull(inputLog1);
			Assert::AreEqual(inputLog2, "Test");
			Assert::IsNull(inputLog3);
		}

		TEST_METHOD(LogWrite_�G���[���O�ɏ������܂�Ă��邱��)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite(LogType::ErrorLog, "Test");

			// �߂�l�͐���
			Assert::AreEqual((int)result, (int)Result::Success);

			Assert::IsNull(inputLog1);
			Assert::IsNull(inputLog2);
			Assert::AreEqual(inputLog3, "Test");
		}

		TEST_METHOD(LogWrite_�ݒ肵�Ă��Ȃ��ꍇ�̓��O���������܂Ȃ�����)
		{
			for each (LogType type in AllLogType)
			{
				Result result = LogWrite(type, "Test");

				// �߂�l�͐���
				Assert::AreEqual((int)result, (int)Result::Success);

				Assert::IsNull(inputLog1);
				Assert::IsNull(inputLog2);
				Assert::IsNull(inputLog3);
			}
		}

		TEST_METHOD(LogWrite_�͈͊O�̌^��ݒ肵���ꍇ�̓G���[���A��)
		{
			SetLogWriteMethod(LogType::InformationLog, TestWriteMethod1);
			SetLogWriteMethod(LogType::WarningLog, TestWriteMethod2);
			SetLogWriteMethod(LogType::ErrorLog, TestWriteMethod3);

			Result result = LogWrite((LogType)-1, "test");

			// �߂�l�͎��s
			Assert::AreEqual((int)result, (int)Result::NotingType);

			// �ǂ̃��O�ɏ�����Ă��Ȃ����Ƃ��m�F
			Assert::IsNull(inputLog1);
			Assert::IsNull(inputLog2);
			Assert::IsNull(inputLog3);
		}

		TEST_METHOD(SetLogWriteMethod_�eWriteMethod�ɒl���ݒ�ł���)
		{
			for each (LogType type in AllLogType)
			{
				Result result = SetLogWriteMethod(type, TestWriteMethod1);

				// �߂�l�͐���
				Assert::AreEqual((int)result, (int)Result::Success);

				// �ݒ�̊m�F
				LogWriteMethod setMethod = GetLogWriteMethod(type);
				Assert::AreEqual((void*)setMethod, (void*)TestWriteMethod1);
			}
		}

		TEST_METHOD(SetLogWriteMethod_�͈͊O�̌^��ݒ肵���ꍇ�̓G���[���A��)
		{
			Result result = SetLogWriteMethod((LogType)-1, TestWriteMethod1);

			// �߂�l�͎��s
			Assert::AreEqual((int)result, (int)Result::NotingType);

			// �S�Ă̐ݒ�̊m�F
			for each (LogType type in AllLogType)
			{
				LogWriteMethod setMethod = GetLogWriteMethod(type);
				Assert::IsNull((void*)setMethod);
			}
		}
	};
}
