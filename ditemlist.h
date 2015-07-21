#ifndef DCOMBOBOX_H
#define DCOMBOBOX_H

#include "DComponent.h"
#include "dstatictext.h"
#include <QGraphicsItem>

class DItemList : public DComponent
{
public:
    DItemList();
    
    void addItem(DStaticText * text)
    {
        staticTextList.append(text);
        text->setVisible(false);
    }
    
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    
    
    
private:
    QList<DStaticText*> staticTextList; 
    
    bool isToggled;
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    
};

#endif // DCOMBOBOX_H
