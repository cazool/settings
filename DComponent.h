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
#ifndef DWIDGET_H
#define DWIDGET_H

#include <QGraphicsItem>
#include <QObject>
#include <QtCore>

#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

class DComponent :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    DComponent();

    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void boundImageToPress(QString imagePath);

    void boundImageToRelease(QString imagePath);

    void boundImageToHover(QString imagePath);

    void setBounds(int x, int y, int w, int h)
    {
        x_axis = x;
        y_axis = y;
        width = w;
        height = h;
    }

    void setPressBackgroundColor(const QColor &color)
    {
        pressBackgroundColor = color;
    }

    void setReleaseBackgroundColor(const QColor &color)
    {
        releaseBackgroundColor = color;
    }

    void setHoverBackgroundColor(const QColor &color)
    {
        hoverBackgroundColor = color;
    }

    void setHoverEnableFlag(bool flag)
    {
         setAcceptHoverEvents(flag);
    }

    void setAdjust(qreal value)
    {
        adjust = value;
    }

    bool isPressed()
    {
        return pressed;
    }

    bool isHovered()
    {
        return hovered;
    }
    
    bool setBackgroundEnable(bool flag)
    {
        backgroundEnabled = flag;
    }
    
    int boundX()
    {
        return x_axis;
    }
    
    int boundY()
    {
        return y_axis;
    }
    
    int boundWidth()
    {
        return width;
    }
    
    int boundHeight()
    {
        return height;
    }
    
    void setText(const QString & text)
    {
        textContent = text;
    }
    
    QString text()
    {
        return textContent;
    }
    
    void setTextColor(const QColor &color)
    {
        textColor = color;
    }
    
    QColor getTextColor()
    {
        return textColor;
    }
    
    void setBackgroundColor(const QColor &color)
    {
        backGroundColor = color;
    }
    
    QColor getBackgroundColor()
    {
        return backGroundColor;
    }
    
    void setPress(bool b)
    {
        pressed = b;
    }
    
    QColor defaultPress = QColor(238, 232, 205,255);
    QColor defaultRelease = Qt::white;
    QColor defaultHover = QColor(238, 232, 205,255);
    QColor defaultTextColor = Qt::black;
    QColor defaultBackgroundColor = QColor(255,255,255,255);

    bool pressed;
    bool hovered;
    bool backgroundEnabled;

    QColor hoverBackgroundColor;
    QColor releaseBackgroundColor;
    QColor pressBackgroundColor;
    
    QColor textColor;
    QColor backGroundColor;

    int x_axis, y_axis, width, height;
    int text_x, text_y;
    qreal adjust;
    QPixmap pressImage;
    QPixmap releaseImage;
    QPixmap hoverImage;
    
    QString textContent;
    
signals:
    
    void clicked();
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
    
};

#endif // DWIDGET_H
