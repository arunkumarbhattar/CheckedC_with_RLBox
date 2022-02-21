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

#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "refbuf.h"
#include "client.h"

#define RAW         1
#define TRANSFORMED 2
#define PLAINTEXT   3

void admin_handle_request(_Ptr<client_t> client, const char *uri : itype(_Ptr<const char>));
void admin_send_response(xmlDocPtr doc : itype(_Ptr<xmlDoc>), client_t *client : itype(_Ptr<client_t>), int response, const char *xslt_template);

#endif  /* __ADMIN_H__ */
