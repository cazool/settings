#include "dscrollarea.h"

DScrollArea::DScrollArea()
{
    m_xPos = 0;
    m_yPos = 0;
    horizontalBarEnable = false;
    vertialBarEnable = false;
}

void DScrollArea::paint(QPainter *painter, 
                   const QStyleOptionGraphicsItem *option, 
                   QWidget *widget)
{
    painter->setPen(QColor(22,22,22,255));
    painter->setBrush(QColor(22,22,22,255));
    painter->drawRect(boundX(), boundY(), boundWidth(), boundHeight());
    
    if(m_xPos>boundX()&&m_xPos<boundX()+boundWidth()&&
       m_yPos>boundY()&&m_yPos<boundY()+boundHeight())
    {
        painter->setPen(getTextColor());
        painter->setBrush(getTextColor());
        painter->drawText(boundX(), m_yPos,"non-static data");
    }
}

void DScrollArea::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setPress(true);
    if(horizontalBarEnable)
        m_xPress = event->pos().x();
    if(vertialBarEnable)
        m_yPress = event->pos().y();
}

void DScrollArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isPressed())
    {
        if(horizontalBarEnable)
        {
            m_xOffset = event->pos().x() - m_xPress;
            m_xPos += m_xOffset;
            m_xPress = event->pos().x();
        }
        
        if(vertialBarEnable)
        {
            m_yOffset = event->pos().y() - m_yPress;
            m_yPos += m_yOffset;
            m_yPress = event->pos().y();
        }
        update(); 
    }
}

void DScrollArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(isPressed())
    {
        setPress(false);
    }
}

void DScrollArea::createHorizontalScrollBar()
{
    horizontalBarEnable = true;
}

void DScrollArea::createVerticalScrollBar()
{
    vertialBarEnable = true;
}
