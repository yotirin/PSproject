#ifndef __LOG_WRITER_TEST__
#define __LOG_WRITER_TEST__

#include "LogWriter.h"

namespace LogWriter
{
	LogWriteMethod GetLogWriteMethod(LogType type);
	void AllWriteMethodClear();
}

#endif // __LOG_WRITER_TEST__
