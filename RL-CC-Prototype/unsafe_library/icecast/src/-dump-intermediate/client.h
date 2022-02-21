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
 * Copyright 2011-2012, Philipp "ph3-der-loewe" Schafft <lion@lion.leolix.org>,
 */

/* client.h
**
** client data structions and function definitions
**
*/
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "connection.h"
#include "refbuf.h"
#include "httpp/httpp.h"

typedef struct _client_tag
{
    /* the client's connection */
    _Ptr<connection_t> con;
    /* the client's http headers */
    _Ptr<http_parser_t> parser;

    /* http response code for this client */
    int respcode;

    /* auth completed, 0 not yet, 1 passed */
    int authenticated;

    /* is client getting intro data */
    long intro_offset;

    /* where in the queue the client is */
    _Ptr<refbuf_t> refbuf;

    /* position in first buffer */
    unsigned int pos;

    /* auth used for this client */
    _Ptr<struct auth_tag> auth;

    /* Client username, if authenticated */
    char *username;

    /* Client password, if authenticated */
    char *password;

    /* Format-handler-specific data for this client */
    void *format_data;

    /* function to call to release format specific resources */
    _Ptr<void (_Ptr<struct _client_tag> client)> free_client_data;

    /* write out data associated with client */
    _Ptr<int (_Ptr<struct _client_tag> client)> write_to_client;

    /* function to check if refbuf needs updating */
    _Ptr<int (_Ptr<struct source_tag> source, struct _client_tag *client : itype(_Ptr<struct _client_tag>))> check_buffer;

} client_t;

int client_create (_Ptr<client_t *> c_ptr, _Ptr<connection_t> con, _Ptr<http_parser_t> parser);
void client_destroy(client_t *client);
void client_send_100(_Ptr<client_t> client);
void client_send_404(_Ptr<client_t> client, _Ptr<const char> message);
void client_send_401(_Ptr<client_t> client);
void client_send_403(_Ptr<client_t> client, _Ptr<const char> message);
void client_send_400(_Ptr<client_t> client, const char *message);
void client_send_500(client_t *client : itype(_Ptr<client_t>), const char *message : itype(_Ptr<const char>));
int client_send_bytes (_Ptr<client_t> client, const void *buf, unsigned len);
int client_read_bytes (_Ptr<client_t> client, void *buf, unsigned len);
void client_set_queue (client_t *client, _Ptr<refbuf_t> refbuf);
int client_check_source_auth (_Ptr<client_t> client, _Ptr<const char> mount);
void client_send_error(_Ptr<client_t> client, int status, int plain, const char *message : itype(_Ptr<const char>));

#endif  /* __CLIENT_H__ */
