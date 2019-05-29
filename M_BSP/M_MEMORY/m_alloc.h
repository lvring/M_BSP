#ifndef __M_ALLOC_H
#define __M_ALLOC_H

#include "m_include.h"
#include "m_port.h"


bool m_init(void);
void *m_alloc(size_t num);
void *m_calloc(size_t num, size_t size);
bool m_free(void *ptr);

size_t m_num_free(void);
size_t m_num_used(void);
size_t m_num_fresh(void);
bool m_check(void);

#endif

