/*
 *	Copyright 2009-2010 Rodrigo Gonçalves de Oliveira <mdkcore@gmail.com - rodrigo.golive@gmail.com>
 *	http://thecoreme.org/blog/projects/kwarbots
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __IMAGELOADER_H__
#define __IMAGELOADER_H__

#include <QColor>
#include <QPixmap>
#include <QString>
#include <QSvgRenderer>

namespace KWB{

// this class load the images from an SVG file
class ImageLoader{
	public:
		ImageLoader(const QString&);
		QPixmap retrieve(const QString&, const QSize&, const QColor& = Qt::transparent);
		QPixmap retrieve(const QString&, const QSize&, const QColor&, const QColor&);

	private:
		QSvgRenderer *m_svg;
		QColor m_base, m_alternate, m_alternate2;
		QString m_fileName;
};

} // namespace

#endif

