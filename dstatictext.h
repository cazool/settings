#ifndef DSTATICTEXT_H
#define DSTATICTEXT_H

#include "DComponent.h"
#include <QGraphicsItem>

class DStaticText : public DComponent
{
public:
    DStaticText();
    
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
 
   
    
    int size();
    
private:
    
};

#endif // DSTATICTEXT_H
