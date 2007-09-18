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
 * Copyright (C) 2005-2007  Guido de Jong <guidoj@users.sf.net>
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "FileManager.h"
#include "Pointer.h"

Pointer::Pointer(const std::string &resname)
        : Subject()
        , visible(false)
        , xPos(0)
        , yPos(0)
        , pointerType(PT_SWORD)
        , pointerImages()
        , dragImage(0)
        , dragOffsetX(0)
        , dragOffsetY(0)
{
    FileManager::GetInstance()->Load(&pointerImages, resname);
}

Pointer::~Pointer()
{}

int
Pointer::GetXPos() const
{
    return xPos;
}

int
Pointer::GetYPos() const
{
    return yPos;
}

void
Pointer::SetPointerType(PointerType pt)
{
    pointerType = pt;
    Notify();
}

void
Pointer::SetPosition(const int x, const int y)
{
    xPos = x;
    yPos = y;
    Notify();
}

void
Pointer::SetVisible(const bool vis)
{
    visible = vis;
    Notify();
}

void
Pointer::SetDragImage(Image *img, const int x, const int y)
{
    dragImage = img;
    dragOffsetX = x;
    dragOffsetY = y;
}

void
Pointer::Draw()
{
    if (visible)
    {
        if (dragImage)
        {
            dragImage->Draw(xPos + dragOffsetX, yPos + dragOffsetY, 0);
        }
        pointerImages.GetImage((int)pointerType)->Draw(xPos, yPos, 0);
    }
}