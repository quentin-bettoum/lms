/*
 * Copyright (C) 2015 Emeric Poupon
 *
 * This file is part of LMS.
 *
 * LMS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LMS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LMS.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <filesystem>
#include <vector>

#include <Magick++.h>

#include "cover/CoverArt.hpp"

namespace CoverArt
{

	void init(const std::filesystem::path& path);

	class Image
	{
		public:

			// input
			bool	load(const std::vector<unsigned char>& rawData);
			bool	load(const std::filesystem::path& p);

			Geometry	getSize() const;

			// Operations
			bool	scale(Geometry geometry);

			// output
			std::vector<uint8_t> save(Format format) const;

		private:
			Magick::Image	_image;
	};


} // namespace CoverArt

