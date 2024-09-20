/****************************************************************

The author of this software is David M. Gay.

Copyright (C) 1998 by Lucent Technologies
All Rights Reserved

Permission to use, copy, modify, and distribute this software and
its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the name of Lucent or any of its entities
not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior
permission.

LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY
SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.

****************************************************************/

/*
Copyright (C) 2023-2024 Six Impossible Things Before Breakfast Limited.
This file is licensed under The 3-Clause BSD License, with full text available at the end of the file.
Contributors: Sherry Ignatchenko, Serhii Iliukhin
*/

#ifndef sixit_dmath_bsd_gdtoa_h_included
#define sixit_dmath_bsd_gdtoa_h_included

#ifndef UShort
typedef unsigned short UShort;
#endif

#ifndef ANSI
#define ANSI(x) x
#define Void void
#endif /* ANSI */

#ifndef CONST
#define CONST const
#endif /* CONST */

 enum {	/* return values from strtodg */
	STRTOG_Zero	= 0,
	STRTOG_Normal	= 1,
	STRTOG_Denormal	= 2,
	STRTOG_Infinite	= 3,
	STRTOG_NaN	= 4,
	STRTOG_NaNbits	= 5,
	STRTOG_NoNumber	= 6,
	STRTOG_Retmask	= 7,

	/* The following may be or-ed into one of the above values. */

	STRTOG_Neg	= 0x08,
	STRTOG_Inexlo	= 0x10,
	STRTOG_Inexhi	= 0x20,
	STRTOG_Inexact	= 0x30,
	STRTOG_Underflow= 0x40,
	STRTOG_Overflow	= 0x80
	};

 typedef struct
FPI {
	int nbits;
	int emin;
	int emax;
	int rounding;
	int sudden_underflow;
	} FPI;

enum {	/* FPI.rounding values: same as FLT_ROUNDS */
	FPI_Round_zero = 0,
	FPI_Round_near = 1,
	FPI_Round_up = 2,
	FPI_Round_down = 3
	};

#ifdef __cplusplus
extern "C" {
#endif

extern char* dtoa  ANSI((double d, int mode, int ndigits, int *decpt,
			int *sign, char **rve));
extern void freedtoa ANSI((char*));
extern float  _strtof ANSI((CONST char *, char **));
extern double _strtod ANSI((CONST char *, char **));

extern char*	g_ddfmt  ANSI((char*, double*, int, unsigned));
extern char*	g_dfmt   ANSI((char*, double*, int, unsigned));
extern char*	g_ffmt   ANSI((char*, float*,  int, unsigned));
extern char*	g_Qfmt   ANSI((char*, void*,   int, unsigned));
extern char*	g_xfmt   ANSI((char*, void*,   int, unsigned));
extern char*	g_xLfmt  ANSI((char*, void*,   int, unsigned));

extern int	strtoId  ANSI((CONST char*, char**, double*, double*));
extern int	strtoIdd ANSI((CONST char*, char**, double*, double*));
extern int	strtoIf  ANSI((CONST char*, char**, float*, float*));
extern int	strtoIQ  ANSI((CONST char*, char**, void*, void*));
extern int	strtoIx  ANSI((CONST char*, char**, void*, void*));
extern int	strtoIxL ANSI((CONST char*, char**, void*, void*));
extern int	strtord  ANSI((CONST char*, char**, int, double*));
extern int	strtordd ANSI((CONST char*, char**, int, double*));
extern int	strtorf  ANSI((CONST char*, char**, int, float*));
extern int	strtorQ  ANSI((CONST char*, char**, int, void*));
extern int	strtorx  ANSI((CONST char*, char**, int, void*));
extern int	strtorxL ANSI((CONST char*, char**, int, void*));
#if 1
extern int	_strtodI  ANSI((CONST char*, char**, double*));
extern int	strtopd  ANSI((CONST char*, char**, double*));
extern int	strtopdd ANSI((CONST char*, char**, double*));
extern int	strtopf  ANSI((CONST char*, char**, float*));
extern int	strtopQ  ANSI((CONST char*, char**, void*));
extern int	strtopx  ANSI((CONST char*, char**, void*));
extern int	strtopxL ANSI((CONST char*, char**, void*));
#else
#define strtopd(s,se,x) strtord(s,se,1,x)
#define strtopdd(s,se,x) strtordd(s,se,1,x)
#define strtopf(s,se,x) strtorf(s,se,1,x)
#define strtopQ(s,se,x) strtorQ(s,se,1,x)
#define strtopx(s,se,x) strtorx(s,se,1,x)
#define strtopxL(s,se,x) strtorxL(s,se,1,x)
#endif

#ifdef __cplusplus
}
#endif

#endif //sixit_dmath_bsd_gdtoa_h_included

/*
The 3-Clause BSD License

Copyright (C) 2023-2024 Six Impossible Things Before Breakfast Limited.

Contributors: Sherry Ignatchenko, Serhii Iliukhin

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

