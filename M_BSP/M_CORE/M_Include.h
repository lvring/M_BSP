#ifndef __M_INCLUDE_H
#define __M_INCLUDE_H
#ifdef __cplusplus  
extern "C" {  
#endif  
	#include <string.h>
	
	#include <stdarg.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stddef.h>
	#include <stdlib.h>
	#include <math.h>
	#include <stdarg.h>
	#include <time.h>
	#include <stdio.h>
	#include "printf.h"


	#define RTE_ALIGN_32BYTES(buf) buf __attribute__ ((aligned (32)))
	
	
	#ifndef UNUSED
	#define UNUSED(x) ((void)(x))
	#endif
#ifdef __cplusplus  
}  
#endif  
#endif
