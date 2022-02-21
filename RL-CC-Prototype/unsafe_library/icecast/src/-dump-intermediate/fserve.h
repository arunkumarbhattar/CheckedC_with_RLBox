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

#ifndef __FSERVE_H__
#define __FSERVE_H__

#include <stdio.h>
#include "cfgfile.h"

typedef _Ptr<void (client_t * : itype(_Ptr<client_t>), void *)> fserve_callback_t;

typedef struct _fserve_t
{
    client_t *client;

    _Ptr<FILE> file;
    int ready;
    _Ptr<void (client_t * : itype(_Ptr<client_t>), void *)> callback;
    void *arg;
    _Ptr<struct _fserve_t> next;
} fserve_t;

void fserve_initialize(void);
void fserve_shutdown(void);
int fserve_client_create(_Ptr<client_t> httpclient, const char *path : itype(_Ptr<const char>));
int fserve_add_client (client_t *client : itype(_Ptr<client_t>), _Ptr<FILE> file);
void fserve_add_client_callback (client_t *client : itype(_Ptr<client_t>), fserve_callback_t callback, void *arg);
char *fserve_content_type(_Ptr<const char> path) : itype(_Ptr<char>);
void fserve_recheck_mime_types (_Ptr<ice_config_t> config);


#endif


