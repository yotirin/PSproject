#ifndef __TYPE_DEFINE__
#define __TYPE_DEFINE__

// windows時
#ifdef _WINDOWS

/// <summary>
/// s08最大値
/// </summary>
#define S08_MAX (127)

/// <summary>
/// s08最小値
/// </summary>
#define S08_MIN (-128)

/// <summary>
/// u08最大値
/// </summary>
#define U08_MAX (256)

/// <summary>
/// u08最小値
/// </summary>
#define U08_MIN (0)

/// <summary>
/// s16最大値
/// </summary>
#define S16_MAX (32767)

/// <summary>
/// s16最小値
/// </summary>
#define S16_MIN (-32768)

/// <summary>
/// u16最大値
/// </summary>
#define U16_MAX (65535)

/// <summary>
/// u16最小値
/// </summary>
#define U16_MIN (0)

/// <summary>
/// s32最大値
/// </summary>
#define S32_MAX (2147483647)

/// <summary>
/// s32最小値
/// </summary>
#define S32_MIN (-2147483648)

/// <summary>
/// u32最大値
/// </summary>
#define U32_MAX (4294967295)

/// <summary>
/// u32最小値
/// </summary>
#define U32_MIN (0)

/// <summary>
/// s64最大値
/// </summary>
#define S64_MAX (9223372036854775807)

/// <summary>
/// s64最小値
/// </summary>
#define S64_MIN (-9223372036854775808)

/// <summary>
/// u64最大値
/// </summary>
#define U64_MAX (18446744073709551615)

/// <summary>
/// u64最小値
/// </summary>
#define U64_MIN (0)

/// <summary>
/// 符号あり8bit整数
/// </summary>
typedef __int8 s08;

/// <summary>
/// 符号なし8bit整数
/// </summary>
typedef unsigned __int8 u08;

/// <summary>
/// 符号あり16bit整数
/// </summary>
typedef __int16 s16;

/// <summary>
/// 符号なし16bit整数
/// </summary>
typedef unsigned __int16 u16;

/// <summary>
/// 符号あり32bit整数
/// </summary>
typedef __int32 s32;

/// <summary>
/// 符号なし32bit整数
/// </summary>
typedef unsigned __int32 u32;

/// <summary>
/// 符号あり64bit整数
/// </summary>
typedef __int64 s64;

/// <summary>
/// 符号なし64bit整数
/// </summary>
typedef unsigned __int64 u64;

/// <summary>
/// 文字列
/// </summary>
typedef char* string;

#endif // _WINDOWS_

#endif // __TYPE_DEFINE__
