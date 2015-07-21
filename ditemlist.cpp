#include "ditemlist.h"

DItemList::DItemList()
{
    isToggled = true;
}

void DItemList::paint(QPainter *painter, 
                 const QStyleOptionGraphicsItem *option, 
                 QWidget *widget)
{
    if(isToggled)
    {
        painter->setPen(getBackgroundColor());
        painter->setBrush(getBackgroundColor());
        painter->drawRect(boundX(), boundY(), boundWidth(), boundHeight());
        
        painter->setPen(getTextColor());
        painter->setBrush(getTextColor());
        painter->drawText(boundX(), boundY()+boundHeight()/2,text());
    }
    else
    {
        painter->setPen(getBackgroundColor());
        painter->setBrush(getBackgroundColor());
        painter->drawRect(boundX(), boundY(), boundWidth(), boundHeight());
        
        painter->setPen(getTextColor());
        painter->setBrush(getTextColor());
        painter->drawText(boundX(), boundY()+boundHeight()/2,text());
    }
    
    painter->setPen(QColor(0,0,0,255));
    painter->drawLine(boundX(),boundY()+boundHeight()-1,boundX()+boundWidth(),boundY()+boundHeight()-1);
    
    painter->setPen(QColor(44,44,44,255));
    painter->drawLine(boundX(),boundY()+boundHeight(),boundX()+boundWidth(),boundY()+boundHeight());
}


void DItemList::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isToggled)
    {
        isToggled = false;
        QList<DStaticText*>::iterator i;
        
        for(i=staticTextList.begin();i!=staticTextList.end();i++)
        {
            DStaticText *tempText = *i;
            tempText->setVisible(true);
            tempText->update();
        }
    }
    else
    {
        isToggled = true;
        QList<DStaticText*>::iterator i;
        
        for(i=staticTextList.begin();i!=staticTextList.end();i++)
        {
            DStaticText *tempText = *i;
            tempText->setVisible(false);
            tempText->update();
        }
    }
    update();
}

void DItemList::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    
}

void DItemList::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    
}

void DItemList::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    
}

void DItemList::keyPressEvent(QKeyEvent *event)
{
    
}

void DItemList::keyReleaseEvent(QKeyEvent *event)
{
    
}
