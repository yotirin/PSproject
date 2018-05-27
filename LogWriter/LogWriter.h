#ifndef __LOG_WRITER__
#define __LOG_WRITER__

#include "TypeDefine.h"

namespace LogWriter
{
	/// <summary>
	/// ���O�������݃��\�b�h
	/// </summary>
	typedef void (*LogWriteMethod)(string log);

	/// <summary>
	/// ���O���
	/// </summary>
	enum LogType
	{
		/// <summary>
		/// ���
		/// </summary>
		InformationLog,

		/// <summary>
		/// �x��
		/// </summary>
		WarningLog,

		/// <summary>
		/// �G���[
		/// </summary>
		ErrorLog,
	};

	/// <summary>
	/// ����
	/// </summary>
	enum Result
	{
		/// <summary>
		/// ����
		/// </summary>
		Success,

		/// <summary>
		/// ���݂��Ȃ��^�C�v
		/// </summary>
		NotingType,
	};

	/// <summary>
	/// ���O�o��
	/// </summary>
	/// <param name="type">���O���</param>
	/// <param name="log">���O���e</param>
	/// <returns>��������</returns>
	Result LogWrite(LogType type, string log);

	/// <summary>
	/// ���O�o�͏����ݒ�
	/// </summary>
	/// <param name="type">���O���</param>
	/// <param name="method">���O�o�̓��\�b�h</param>
	/// <returns>��������</returns>
	Result SetLogWriteMethod(LogType type, LogWriteMethod method);
}

#endif // __LOG_WRITER__

