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

#include <iomanip>
#include <sstream>

#include "FileManager.h"
#include "ScreenResource.h"
#include "Zone.h"

Zone::Zone()
: horizon()
, terrain(0)
{
}

Zone::~Zone()
{
  if (terrain) {
    delete terrain;
  }
}

void
Zone::Load(const unsigned int n)
{
  std::stringstream horizonStream;
  horizonStream << "Z" << std::setw(2) << std::setfill('0') << n << "H.BMX";
  FileManager::GetInstance()->Load(&horizon, horizonStream.str());

  static const int TERRAIN_IMAGE_WIDTH = 172;
  static const int TERRAIN_IMAGE_HEIGHT = 130;
  std::stringstream textureStream;
  textureStream << "Z" << std::setw(2) << std::setfill('0') << n << "L.SCX";
  ScreenResource textures;
  FileManager::GetInstance()->Load(&textures, textureStream.str());
  if (terrain) {
    delete terrain;
  }
  terrain = new Image(TERRAIN_IMAGE_WIDTH, TERRAIN_IMAGE_HEIGHT, textures.GetImage()->GetPixels());
}

Image *
Zone::GetHorizon(const unsigned int n)
{
  return horizon.GetImage(n);
}

Image *
Zone::GetTerrain()
{
  return terrain;
}
