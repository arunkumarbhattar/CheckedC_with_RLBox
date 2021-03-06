/* Icecast
 *
 * This program is distributed under the GNU General Public License, version 2.
 * A copy of this license is included with this source.
 *
 * Copyright 2000-2004, Jack Moffitt <jack@xiph.org, 
 *                      Michael Smith <msmith@xiph.org>,
 *                      oddsock <oddsock@xiph.org>,
 *                      Karl Heyes <karl@xiph.org>
 *                      and others (see AUTHORS for details).
 */

#ifndef __MD5_H__
#define __MD5_H__

#include "compat.h"

#define HASH_LEN     16

struct MD5Context
{       
    uint32_t     buf[4];
    uint32_t     bits[2];
    unsigned char in[64];
};

void MD5Init(_Ptr<struct MD5Context> context);
void MD5Update(_Ptr<struct MD5Context> context, const unsigned char *buf : itype(_Ptr<const unsigned char>), unsigned len);
void MD5Final(unsigned char digest[HASH_LEN], struct MD5Context *context : itype(_Ptr<struct MD5Context>));


#endif


