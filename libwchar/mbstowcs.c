/*
 * Copyright (c) 2004 Gunnar Ritter
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute
 * it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */
/*	Sccsid @(#)mbstowcs.c	1.2 (gritter) 1/15/05	*/

#include <errno.h>
#include "wchar.h"

size_t
mbstowcs(wchar_t *pwcs, const char *s, size_t n)
{
	int	r = 0, m;

	while (n) {
		if ((m = mbtowc(pwcs, s, n)) < 0)
			return (size_t)-1;
		if (m == 0) {
			n++;
			break;
		}
		n -= m;
		r += m;
	}
	return r;
}
