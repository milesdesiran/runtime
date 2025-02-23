/**
 * \file
 */

#ifndef __MONO_UTILS_MONO_THREADS_DEBUG_H__
#define __MONO_UTILS_MONO_THREADS_DEBUG_H__

#include <config.h>
#include <glib.h>
#if defined (HOST_ANDROID)
#include <android/log.h>
#endif

/* Logging - enable them below if you need specific logging for the category you need */
#define MOSTLY_ASYNC_SAFE_FPRINTF(handle, ...) do { \
	g_async_safe_fprintf (handle, __VA_ARGS__); \
} while (0)

#if defined (HOST_ANDROID)
#define MOSTLY_ASYNC_SAFE_PRINTF(...) do { \
	__android_log_print (ANDROID_LOG_ERROR, "THREAD", __VA_ARGS__); \
} while (0)
#else
#define MOSTLY_ASYNC_SAFE_PRINTF(...) MOSTLY_ASYNC_SAFE_FPRINTF(1, __VA_ARGS__);
#endif

#if 1
#define THREADS_DEBUG(...)
#else
#define THREADS_DEBUG MOSTLY_ASYNC_SAFE_PRINTF
#endif

#if 1
#define THREADS_STW_DEBUG(...)
#else
#define THREADS_STW_DEBUG MOSTLY_ASYNC_SAFE_PRINTF
#endif

#if 1
#define THREADS_SUSPEND_DEBUG(...)
#else
#define THREADS_SUSPEND_DEBUG MOSTLY_ASYNC_SAFE_PRINTF
#endif

#if 1
#define THREADS_STATE_MACHINE_DEBUG(...)
#else
#define THREADS_STATE_MACHINE_DEBUG_ENABLED
#define THREADS_STATE_MACHINE_DEBUG MOSTLY_ASYNC_SAFE_PRINTF
#endif

#if 1
#define THREADS_INTERRUPT_DEBUG(...)
#else
#define THREADS_INTERRUPT_DEBUG MOSTLY_ASYNC_SAFE_PRINTF
#endif

#endif /* __MONO_UTILS_MONO_THREADS_DEBUG_H__ */
