#include <stdio.h>
#include "LogWriter.h"
#include "TypeDefine.h"

namespace LogWriter
{
	/* グローバル変数定義 */

#ifdef _DEBUG
	/// <summary>
	/// 情報書き出しメソッド
	/// </summary>
	LogWriteMethod InformationWriteMethod = NULL;

	/// <summary>
	/// 警告書き出しメソッド
	/// </summary>
	LogWriteMethod WarningWriteMethod = NULL;

	/// <summary>
	/// エラー書き出しメソッド
	/// </summary>
	LogWriteMethod ErrorWriteMethod = NULL;
#endif // _DEBUG

	/* クラスメソッド定義 */

	/// <summary>
	/// ログ出力
	/// </summary>
	/// <param name="type">ログ種類</param>
	/// <param name="log">ログ内容</param>
	/// <returns>処理結果</returns>
	Result LogWrite(LogType type, string log)
	{
#ifdef _DEBUG
		LogWriteMethod writeMethod = NULL;

		switch (type)
		{
		case LogType::InformationLog:
			writeMethod = InformationWriteMethod;
			break;
		case LogType::WarningLog:
			writeMethod = WarningWriteMethod;
			break;
		case LogType::ErrorLog:
			writeMethod = ErrorWriteMethod;
			break;
		default:
			return Result::NotingType;
		}

		if (writeMethod != NULL) writeMethod(log);

#endif // _DEBUG

		return Result::Success;
	}

	/// <summary>
	/// ログ出力処理設定
	/// </summary>
	/// <param name="type">ログ種類</param>
	/// <param name="method">ログ出力メソッド</param>
	/// <returns>処理結果</returns>
	Result SetLogWriteMethod(LogType type, LogWriteMethod method)
	{
#ifdef _DEBUG
		switch (type)
		{
		case LogType::InformationLog:
			InformationWriteMethod = method;
			break;
		case LogType::WarningLog:
			WarningWriteMethod = method;
			break;
		case LogType::ErrorLog:
			ErrorWriteMethod = method;
			break;
		default:
			return Result::NotingType;
		}
#endif // _DEBUG

		return Result::Success;
	}

#ifdef _DEBUG
	/// <summary>
	/// メソッドクラスのクリア
	/// </summary>
	void AllWriteMethodClear()
	{
		InformationWriteMethod = NULL;
		WarningWriteMethod = NULL;
		ErrorWriteMethod = NULL;
	}

	/// <summary>
	/// 設定したメソッドの取得（テスト用）
	/// </summary>
	/// <param name="type">ログ種類</param>
	/// <returns>メソッドクラス</returns>
	LogWriteMethod GetLogWriteMethod(LogType type)
	{
		switch (type)
		{
		case LogType::InformationLog:
			return InformationWriteMethod;
			break;
		case LogType::WarningLog:
			return WarningWriteMethod;
			break;
		case LogType::ErrorLog:
			return ErrorWriteMethod;
			break;
		default:
			return NULL;
		}
	}
#endif // _DEBUG
}