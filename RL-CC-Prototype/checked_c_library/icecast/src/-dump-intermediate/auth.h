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

#ifndef __AUTH_H__
#define __AUTH_H__

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

struct source_tag;
struct auth_tag;

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "cfgfile.h"
#include "client.h"
#include "thread/thread.h"

typedef enum
{
    AUTH_UNDEFINED,
    AUTH_OK,
    AUTH_FAILED,
    AUTH_FORBIDDEN,
    AUTH_USERADDED,
    AUTH_USEREXISTS,
    AUTH_USERDELETED
} auth_result;

typedef struct auth_client_tag
{
    char        *mount;
    client_t    *client;
    _Ptr<void (_Ptr<struct auth_tag> auth, _Ptr<struct auth_client_tag> auth_user)> process;
    _Ptr<struct auth_client_tag> next;
} auth_client;


typedef struct auth_tag
{
    char *mount;

    /* Authenticate using the given username and password */
    _Ptr<auth_result (_Ptr<auth_client> aclient)> authenticate;
    _Ptr<auth_result (_Ptr<auth_client> auth_user)> release_listener;

    /* auth handler for authenicating a connecting source client */
    _Ptr<void (_Ptr<auth_client> auth_user)> stream_auth;

    /* auth handler for source startup, no client passed as it may disappear */
    _Ptr<void (_Ptr<auth_client> auth_user)> stream_start;

    /* auth handler for source exit, no client passed as it may disappear */
    _Ptr<void (_Ptr<auth_client> auth_user)> stream_end;

    /* auth state-specific free call */
    _Ptr<void (_Ptr<struct auth_tag> self)> free;

    _Ptr<auth_result (_Ptr<struct auth_tag> auth, const char *username : itype(_Ptr<const char>), const char *password : itype(_Ptr<const char>))> adduser;
    _Ptr<auth_result (_Ptr<struct auth_tag> auth, const char *username : itype(_Ptr<const char>))> deleteuser;
    _Ptr<auth_result (_Ptr<struct auth_tag> auth, xmlNodePtr srcnode : itype(_Ptr<xmlNode>))> listuser;

    mutex_t lock;
    int running;
    int refcount;
    int allow_duplicate_users;

    _Ptr<thread_type> thread;

    /* per-auth queue for clients */
    _Ptr<auth_client> head;
_Ptr<_Ptr<auth_client>> tailp;
    int pending_count;

    void *state;
    char *type;
} auth_t;

void auth_add_listener (_Ptr<const char> mount, _Ptr<client_t> client);
int  auth_release_listener (client_t *client : itype(_Ptr<client_t>));

void auth_initialise (void);
void auth_shutdown (void);

auth_t *auth_get_authenticator(xmlNodePtr node : itype(_Ptr<xmlNode>)) : itype(_Ptr<auth_t>);
void    auth_release (_Ptr<auth_t> authenticator);

/* call to trigger an event when a stream starts */
void auth_stream_start (_Ptr<struct _mount_proxy> mountinfo, const char *mount : itype(_Ptr<const char>));

/* call to trigger an event when a stream ends */
void auth_stream_end (_Ptr<struct _mount_proxy> mountinfo, const char *mount : itype(_Ptr<const char>));

/* call to trigger an event to authenticate a source client */
int auth_stream_authenticate (_Ptr<client_t> client, _Ptr<const char> mount, _Ptr<struct _mount_proxy> mountinfo);

/* called from auth thread, after the client has successfully authenticated
 * and requires adding to source or fserve. */
int auth_postprocess_listener (_Ptr<auth_client> auth_user);

#endif


