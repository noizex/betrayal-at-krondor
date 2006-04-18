/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * Copyright (C) 2005-2006  Guido de Jong <guidoj@users.sf.net>
 */

#ifndef TEXT_AREA_H
#define TEXT_AREA_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "FontResource.h"
#include "Video.h"

class TextArea {
  private:
    unsigned int width;
    unsigned int height;
    FontResource &font;
    std::string text;
    unsigned int color;
  public:
    TextArea(const unsigned int w, const unsigned int h, FontResource &fnt);
    virtual ~TextArea();
    void SetText(const std::string &s);
    void SetColor(const unsigned int c);
    void Draw(Video *video, const unsigned int x, const unsigned int y, const bool italic = false);
};

#endif

