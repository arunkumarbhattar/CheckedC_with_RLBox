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
 * Copyright 2012-2014, Philipp "ph3-der-loewe" Schafft <lion@lion.leolix.org>,
 */

#ifndef __UTIL_H__
#define __UTIL_H__

#define XSLT_CONTENT 1
#define HTML_CONTENT 2

#define READ_ENTIRE_HEADER 1
#define READ_LINE 0

#define MAX_LINE_LEN 512

int util_timed_wait_for_fd(sock_t fd, int timeout);
int util_read_header(sock_t sock, char *buff : itype(_Ptr<char>), unsigned long len, int entire);
int util_check_valid_extension(const char *uri : itype(_Ptr<const char>));
char *util_get_extension(const char *path : itype(_Ptr<const char>)) : itype(_Ptr<char>);
_Ptr<char> util_get_path_from_uri(_Ptr<char> uri);
char *util_get_path_from_normalised_uri(const char *uri : itype(_Ptr<const char>)) : itype(_Ptr<char>);
_Ptr<char> util_normalise_uri(const char *uri : itype(_Ptr<const char>));
char *util_base64_encode(const char *data : itype(_Ptr<const char>)) : itype(_Ptr<char>);
char *util_base64_decode(const char *input : itype(_Ptr<const char>)) : itype(_Ptr<char>);
char *util_bin_to_hex(unsigned char *data : itype(_Ptr<unsigned char>), int len) : itype(_Ptr<char>);

char *util_url_unescape(const char *src : itype(_Ptr<const char>)) : itype(_Ptr<char>);
char *util_url_escape(const char *src : itype(_Ptr<const char>)) : itype(_Ptr<char>);

/* Function to build up a HTTP header.
 * out is the pointer to storage.
 * len is the total length of out.
 * offset is the offset in out we should start writing at if offset >= 0.
 * In this case the 'used' length is len-offset.
 * If offset is -1 we append at the end of out.
 * In this case the used length is len-strlen(out).
 * cache is a bool. If set allow the client to cache the content (static data).
 * if unset we will send no-caching headers.
 * status is the HTTP status code. If -1 no HTTP status header is generated.
 * statusmsg is the status header text. If NULL a default one
 * is used for the given status code. This is ignored if status is -1.
 * contenttype is the value for the Content-Type header.
 * if NULL no such header is generated.
 * charset is the charset for the object. If NULL no header is generated
 * or default is used.
 * datablock is random data added to the request.
 * If datablock is non NULL the end-of-header is appended as well as this datablock.
 * If datablock is NULL no end-of-header nor any data is appended.
 * Returns the number of bytes written or -1 on error.
 */
struct source_tag; /* use forward decleration so we do not need to
                    * include <source.h> that would cause other conflicts. */
ssize_t util_http_build_header(char *out : itype(_Ptr<char>), size_t len, ssize_t offset, int cache, int status, const char *statusmsg : itype(_Ptr<const char>), const char *contenttype : itype(_Ptr<const char>), const char *charset : itype(_Ptr<const char>), const char *datablock : itype(_Ptr<const char>), _Ptr<struct source_tag> source);

/* String dictionary type, without support for NULL keys, or multiple
 * instances of the same key */
typedef struct _util_dict {
  char *key;
  char *val;
  _Ptr<struct _util_dict> next;
} util_dict;

_Ptr<util_dict> util_dict_new(void);
void util_dict_free(_Ptr<util_dict> dict);
/* dict, key must not be NULL. */
int util_dict_set(_Ptr<util_dict> dict, const char *key : itype(_Ptr<const char>), const char *val : itype(_Ptr<const char>));
const char *util_dict_get(_Ptr<util_dict> dict, const char *key : itype(_Ptr<const char>)) : itype(_Ptr<const char>);
char *util_dict_urlencode(_Ptr<util_dict> dict, char delim) : itype(_Ptr<char>);

#ifndef HAVE_LOCALTIME_R
struct tm *localtime_r (const time_t *timep, struct tm *result);
#endif
char *util_conv_string(const char *string, const char *in_charset : itype(_Ptr<const char>), const char *out_charset : itype(_Ptr<const char>)) : itype(_Ptr<char>);

int get_line(_Ptr<FILE> file, char *buf : itype(_Ptr<char>), size_t siz);
#endif  /* __UTIL_H__ */
