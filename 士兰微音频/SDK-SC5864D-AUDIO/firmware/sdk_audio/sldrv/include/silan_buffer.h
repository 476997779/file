/*
 * buffer.h
 */

#ifndef __SILAN_BUFFER_H__
#define __SILAN_BUFFER_H__

#include "silan_types.h"
#include "silan_errno.h"

typedef struct {
	char *base;
	char *lmt;
	char *rd;
	char *wt;
	int   bytes;
}buf_t;

int silan_buf_init(buf_t *buf, char *base, int bytes);

#define silan_buf_try_read(buf, read_p, bytes)      silan_buf_pre_read(buf, read_p, 0, bytes)
int silan_buf_pre_read(buf_t *buf, char **read_p, int offset, int bytes);
int silan_buf_read(buf_t *buf, int bytes);

#define silan_buf_try_write(buf, write_p, bytes)    silan_buf_pre_write(buf, write_p, 0, bytes)
int silan_buf_pre_write(buf_t *buf, char **write_p, int offset, int bytes);
int silan_buf_write(buf_t *buf, int bytes);

int silan_buf_get_fullness(buf_t *buf);
int silan_buf_get_space(buf_t *buf);
int silan_buf_ring_read(buf_t *buf, char *data, int size);
int silan_buf_ring_write(buf_t *buf, char *data, int size);

#endif
