/****************************************************************************
**
**  Copyright (C) 2011~2015 Deepin, Inc.
**                2011~2015 Zhe Wang
**
**  Author:     Zhe Wang <wzedmund@gmail.com>
**  Maintainer: 
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/
#include "dstatictext.h"
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

DStaticText::DStaticText()
{
    
}


void DStaticText::paint(QPainter *painter, 
                   const QStyleOptionGraphicsItem *option, 
                   QWidget *widget)
{
    painter->setPen(QColor(22,22,22,255));
    painter->setBrush(QColor(22,22,22,255));
    painter->drawRect(boundX(), boundY(), boundWidth(), boundHeight());
    
    painter->setPen(getTextColor());
    painter->setBrush(getTextColor());
    painter->drawText(boundX(), boundY()+boundHeight()-10,text());
}

int DStaticText::size()
{
    return text().size();
}
