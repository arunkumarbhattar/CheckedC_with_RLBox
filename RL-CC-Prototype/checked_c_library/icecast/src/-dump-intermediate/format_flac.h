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


#ifndef __FORMAT_FLAC_H
#define __FORMAT_FLAC_H

#include "format_ogg.h"

_Ptr<ogg_codec_t> initial_flac_page(_Ptr<format_plugin_t> plugin, ogg_page *page : itype(_Ptr<ogg_page>));

#endif /* __FORMAT_FLAC_H */
