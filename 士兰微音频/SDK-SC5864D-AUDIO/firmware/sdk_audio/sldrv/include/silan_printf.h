/*
 * silan_printf.h
 */

#ifndef __SILAN_PRINTF_H__
#define __SILAN_PRINTF_H__

#include "silan_config.h"
#include "stdio.h"

void sl_printf (const char *fmt, ...);

#if defined(__XCC__)
void sl_printf (const char *fmt, ...);
#define SL_PRINTF		sl_printf
#define sl_printf		sl_printf
#endif

#if defined(__CSKY__)
#define SL_PRINTF		printf
#endif

#if defined(__CC_ARM)

#ifdef _SUPPORT_PRINTF_RETARGET_
#include "stdio.h"
#define SL_PRINTF		printf
#define sl_printf		printf
#else
#define SL_PRINTF		sl_printf
#endif

#endif

#define _SL_LOG(fmt, ...)   do { \
                           	        SL_PRINTF(fmt "\n", ##__VA_ARGS__); \
                               } while(0)

#if defined(__CC_ARM)
	#define LOG_CORE_HEAD          "[m0]"
#elif defined(__CSKY__)
	#define LOG_CORE_HEAD          "[ck]"
#elif defined(__XCC__)
	#define LOG_CORE_HEAD          "[dsp]"
#else
	#error error.
#endif

#ifndef MODULE_NAME
	#define LOG_HEAD               LOG_CORE_HEAD
	#define DBGLOG_HEAD            LOG_CORE_HEAD
#else
	#define LOG_HEAD               LOG_CORE_HEAD"["MODULE_NAME"]"
	#define DBGLOG_HEAD            LOG_CORE_HEAD"["MODULE_NAME"]"
#endif

#define SL_LOG(fmt, ...)       	   _SL_LOG(LOG_HEAD fmt, ##__VA_ARGS__)

#ifndef __DEBUG__
	#define SL_DBGLOG(fmt, ...)
	#define SL_TRACE()
	#define SL_ASSERT(x)
#else
	#define SL_DBGLOG(fmt, ...)      _SL_LOG(DBGLOG_HEAD fmt, ##__VA_ARGS__)
	#define SL_TRACE()               SL_DBGLOG("<%s> %s,%d", __func__, __FILE__, __LINE__)
	#define SL_ASSERT(x)             do { \
										if (!(x)) { \
                                            SL_PRINTF(DBGLOG_HEAD "ASSERT at <%s> %s,%d\n\n\n\n", \
                                                        __func__, __FILE__, __LINE__); \
											while (1); \
										} \
                                     } while(0)
#endif

#endif  // __SILAN_PRINTF_H__
