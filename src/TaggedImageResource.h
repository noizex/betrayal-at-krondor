/*
 * This file is part of xBaK.
 *
 * xBaK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xBaK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xBaK.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) Guido de Jong <guidoj@users.sf.net>
 */

#ifndef TAGGED_IMAGE_RESOURCE_H
#define TAGGED_IMAGE_RESOURCE_H

#include <vector>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "Image.h"
#include "TaggedResource.h"

class TaggedImageResource : public TaggedResource
{
private:
    unsigned int numImages;
    std::vector<Image *> images;
public:
    TaggedImageResource();
    ~TaggedImageResource();
    unsigned int GetNumImages() const;
    Image * GetImage ( unsigned int n ) const;
    void Clear();
    void Load ( FileBuffer *buffer );
    unsigned int Save ( FileBuffer *buffer );
};

#endif
