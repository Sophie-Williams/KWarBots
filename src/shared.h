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

#ifndef __SHARED_H__
#define __SHARED_H__

#include <QList>
#include <QPoint>
#include <QPixmap>

namespace KWB{

#define SIZE		32
#define adjust_size(x)	float(SIZE) / (x)

typedef QList<QPixmap*> Frames; // to use with animations or multiple sprites

// transform from Map to real coordinates
inline QPoint position(const QPoint &pos){
	QPoint p;

	p.setX(pos.x() * SIZE);
	p.setY(pos.y() * SIZE);

	return p;
}

enum Direction {DirectionUp, DirectionRight, DirectionDown, DirectionLeft}; // order: clockwise

} // namespace

#endif

