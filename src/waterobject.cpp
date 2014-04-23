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

#include <QSize>
#include <QPixmap>

#include "waterobject.h"
#include "imageloader.h"

namespace KWB{

WaterObject::WaterObject(const QString &imageFile, const QPoint &pos, QTimer *timer): Object(imageFile, pos), m_current(0){
	QSize m_size(SIZE, SIZE);

	ImageLoader loader(imageFile);
	m_animation = new Animation(timer);

	// position 0 on m_sprites
	image[0] = loader.retrieve("00", m_size);
	m_animation->addPixmap(&image[0]);
	// position 1 on m_sprites
	image[1] = loader.retrieve("01", m_size);
	m_animation->addPixmap(&image[1]);
	// position 2 on m_sprites
	image[2] = loader.retrieve("02", m_size);
	m_animation->addPixmap(&image[2]);
	// position 3 on m_sprites
	image[3] = loader.retrieve("03", m_size);
	m_animation->addPixmap(&image[3]);

	update();

	connect(timer, SIGNAL(timeout()), this, SLOT(update()));

	setData(0, "Object");
	setData(1, "Water");
	setZValue(2);
}

WaterObject::~WaterObject(){
}

} // namespace

