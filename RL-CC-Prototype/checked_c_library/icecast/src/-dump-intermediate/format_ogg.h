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

/* format_ogg.h
**
** vorbis format plugin header
**
*/
#ifndef __FORMAT_OGG_H__
#define __FORMAT_OGG_H__

#include <ogg/ogg.h>
#include "refbuf.h"
#include "format.h"

typedef struct ogg_state_tag
{
    char *mount;
    ogg_sync_state oy;
    int error;

    int codec_count;
    _Ptr<struct ogg_codec_tag> codecs;
    char *artist;
    char *title;
    int log_metadata;
    _Ptr<refbuf_t> file_headers;
    _Ptr<refbuf_t> header_pages;
    _Ptr<refbuf_t> header_pages_tail;
    _Ptr<_Ptr<refbuf_t>> bos_end;
    int bos_completed;
    long bitrate;
    _Ptr<struct ogg_codec_tag> current;
    _Ptr<struct ogg_codec_tag> codec_sync;
} ogg_state_t;


/* per codec/logical structure */
typedef struct ogg_codec_tag
{
    _Ptr<struct ogg_codec_tag> next;
    ogg_stream_state os;
    unsigned headers;
    const char *name;
    void *specific;
    _Ptr<refbuf_t> possible_start;
    _Ptr<refbuf_t> page;

    _Ptr<_Ptr<refbuf_t> (_Ptr<ogg_state_t> ogg_info, _Ptr<struct ogg_codec_tag> codec)> process;
    _Ptr<_Ptr<refbuf_t> (_Ptr<ogg_state_t> ogg_info, _Ptr<struct ogg_codec_tag> codec, ogg_page *page : itype(_Ptr<ogg_page>))> process_page;
    _Ptr<void (_Ptr<ogg_state_t> ogg_info, _Ptr<struct ogg_codec_tag> codec)> codec_free;
} ogg_codec_t;


_Ptr<refbuf_t> make_refbuf_with_page (ogg_page *page);
void format_ogg_attach_header (_Ptr<ogg_state_t> ogg_info, ogg_page *page);
void format_ogg_free_headers (_Ptr<ogg_state_t> ogg_info);
int format_ogg_get_plugin (_Ptr<source_t> source);

#endif  /* __FORMAT_OGG_H__ */
