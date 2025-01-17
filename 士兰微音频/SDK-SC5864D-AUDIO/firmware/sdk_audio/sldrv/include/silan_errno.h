/*
 * silan_errno.h
 */

#ifndef __SILAN_ERRNO_H__
#define __SILAN_ERRNO_H__

#if defined(__CSKY__)
#include "errno.h"

#define ENONE			0
#else
enum {
	ENONE             =  0,  /* No Error */
	EERROR            =  1,  /* Default error */
	EINVAL            =  2,  /* Invalid argument */
	EFAULT            =  3,  /* Bad address */
	ENOMEM            =  4,  /* Out of memory */
	ENOSPC            =  5,  /* No space left on device */
	EIO               =  6,  /* I/O error */
	EFBIG             =  7,  /* File too large */
	EBUSY             =  8,  /* Resource or device busy */
	EAGAIN            =  9,  /* Try again */
	ENODEV            = 10,  /* No such device */
	EACCES            = 11,  /* Permission denied */
	ENOENT            = 12,  /* No such file or directory */
};
#endif

#endif  //__SILAN_ERRNO_H__
