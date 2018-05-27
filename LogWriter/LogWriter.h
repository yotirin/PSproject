#ifndef __LOG_WRITER__
#define __LOG_WRITER__

#include "TypeDefine.h"

namespace LogWriter
{
	/// <summary>
	/// ログ書き込みメソッド
	/// </summary>
	typedef void (*LogWriteMethod)(string log);

	/// <summary>
	/// ログ種類
	/// </summary>
	enum LogType
	{
		/// <summary>
		/// 情報
		/// </summary>
		InformationLog,

		/// <summary>
		/// 警告
		/// </summary>
		WarningLog,

		/// <summary>
		/// エラー
		/// </summary>
		ErrorLog,
	};

	/// <summary>
	/// 結果
	/// </summary>
	enum Result
	{
		/// <summary>
		/// 成功
		/// </summary>
		Success,

		/// <summary>
		/// 存在しないタイプ
		/// </summary>
		NotingType,
	};

	/// <summary>
	/// ログ出力
	/// </summary>
	/// <param name="type">ログ種類</param>
	/// <param name="log">ログ内容</param>
	/// <returns>処理結果</returns>
	Result LogWrite(LogType type, string log);

	/// <summary>
	/// ログ出力処理設定
	/// </summary>
	/// <param name="type">ログ種類</param>
	/// <param name="method">ログ出力メソッド</param>
	/// <returns>処理結果</returns>
	Result SetLogWriteMethod(LogType type, LogWriteMethod method);
}

#endif // __LOG_WRITER__

