#ifndef __TYPE_DEFINE__
#define __TYPE_DEFINE__

// windows��
#ifdef _WINDOWS

/// <summary>
/// s08�ő�l
/// </summary>
#define S08_MAX (127)

/// <summary>
/// s08�ŏ��l
/// </summary>
#define S08_MIN (-128)

/// <summary>
/// u08�ő�l
/// </summary>
#define U08_MAX (256)

/// <summary>
/// u08�ŏ��l
/// </summary>
#define U08_MIN (0)

/// <summary>
/// s16�ő�l
/// </summary>
#define S16_MAX (32767)

/// <summary>
/// s16�ŏ��l
/// </summary>
#define S16_MIN (-32768)

/// <summary>
/// u16�ő�l
/// </summary>
#define U16_MAX (65535)

/// <summary>
/// u16�ŏ��l
/// </summary>
#define U16_MIN (0)

/// <summary>
/// s32�ő�l
/// </summary>
#define S32_MAX (2147483647)

/// <summary>
/// s32�ŏ��l
/// </summary>
#define S32_MIN (-2147483648)

/// <summary>
/// u32�ő�l
/// </summary>
#define U32_MAX (4294967295)

/// <summary>
/// u32�ŏ��l
/// </summary>
#define U32_MIN (0)

/// <summary>
/// s64�ő�l
/// </summary>
#define S64_MAX (9223372036854775807)

/// <summary>
/// s64�ŏ��l
/// </summary>
#define S64_MIN (-9223372036854775808)

/// <summary>
/// u64�ő�l
/// </summary>
#define U64_MAX (18446744073709551615)

/// <summary>
/// u64�ŏ��l
/// </summary>
#define U64_MIN (0)

/// <summary>
/// ��������8bit����
/// </summary>
typedef __int8 s08;

/// <summary>
/// �����Ȃ�8bit����
/// </summary>
typedef unsigned __int8 u08;

/// <summary>
/// ��������16bit����
/// </summary>
typedef __int16 s16;

/// <summary>
/// �����Ȃ�16bit����
/// </summary>
typedef unsigned __int16 u16;

/// <summary>
/// ��������32bit����
/// </summary>
typedef __int32 s32;

/// <summary>
/// �����Ȃ�32bit����
/// </summary>
typedef unsigned __int32 u32;

/// <summary>
/// ��������64bit����
/// </summary>
typedef __int64 s64;

/// <summary>
/// �����Ȃ�64bit����
/// </summary>
typedef unsigned __int64 u64;

/// <summary>
/// ������
/// </summary>
typedef char* string;

#endif // _WINDOWS_

#endif // __TYPE_DEFINE__
