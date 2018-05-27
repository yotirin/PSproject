#include <stdio.h>
#include "LogWriter.h"
#include "TypeDefine.h"

namespace LogWriter
{
	/* �O���[�o���ϐ���` */

#ifdef _DEBUG
	/// <summary>
	/// ��񏑂��o�����\�b�h
	/// </summary>
	LogWriteMethod InformationWriteMethod = NULL;

	/// <summary>
	/// �x�������o�����\�b�h
	/// </summary>
	LogWriteMethod WarningWriteMethod = NULL;

	/// <summary>
	/// �G���[�����o�����\�b�h
	/// </summary>
	LogWriteMethod ErrorWriteMethod = NULL;
#endif // _DEBUG

	/* �N���X���\�b�h��` */

	/// <summary>
	/// ���O�o��
	/// </summary>
	/// <param name="type">���O���</param>
	/// <param name="log">���O���e</param>
	/// <returns>��������</returns>
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
	/// ���O�o�͏����ݒ�
	/// </summary>
	/// <param name="type">���O���</param>
	/// <param name="method">���O�o�̓��\�b�h</param>
	/// <returns>��������</returns>
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
	/// ���\�b�h�N���X�̃N���A
	/// </summary>
	void AllWriteMethodClear()
	{
		InformationWriteMethod = NULL;
		WarningWriteMethod = NULL;
		ErrorWriteMethod = NULL;
	}

	/// <summary>
	/// �ݒ肵�����\�b�h�̎擾�i�e�X�g�p�j
	/// </summary>
	/// <param name="type">���O���</param>
	/// <returns>���\�b�h�N���X</returns>
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