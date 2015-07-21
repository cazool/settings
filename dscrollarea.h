#ifndef DSCROLLAREA_H
#define DSCROLLAREA_H

#include "DComponent.h"
#include <QGraphicsItem>

class DScrollArea : public DComponent
{
public:
    DScrollArea();
    
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    
    void createVerticalScrollBar();
    
    void createHorizontalScrollBar();
    
protected:
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    
private:
    int m_xOffset, m_yOffset;
    int m_xPos, m_yPos;
    int m_xPress, m_yPress;
    
    bool vertialBarEnable;
    bool horizontalBarEnable;
};

#endif // DSCROLLAREA_H
