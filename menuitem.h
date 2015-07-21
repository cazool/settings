#ifndef MENUITEM_H
#define MENUITEM_H

#include "DComponent.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsProxyWidget>

#define MARGIN_EDGE 5
#define MARGIN_ICON_TEXT 10
#define HEIGHT_TEXT 20

class MenuItem : public DComponent
{
public:
    
    enum Alignment
    {
        center = 0,
        left = 1,
        right = 2,
        top = 3,
        bottom = 4,
        topRight = 5,
        topLeft = 6,
        bottomLeft = 7,
        bottomRight = 8
    };
    
    enum Arrow
    {
        arrowLeft = 0,
        arrowRight = 1,
        arrowUp = 2,
        arrowDown = 3
    };
    
    MenuItem();
    
    MenuItem(QGraphicsScene *scene,QString name);
    
    MenuItem(QGraphicsScene *scene,QString imagePath, QString name);
    
    MenuItem(QGraphicsScene *scene,QString name, MenuItem::Alignment align);
    
    MenuItem(QGraphicsScene *scene,QString imagePath, QString name, MenuItem::Alignment align);
    
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    
    void setAlignment(MenuItem::Alignment align);
    
    void addWidget(QWidget *widget);
    
    void addWidget(QWidget *widget, MenuItem::Alignment align);
    
    void createItem();

private:
    void boundImageToRightArrow();
    bool m_iconFlag;
    QGraphicsScene *m_scene;
    QGraphicsProxyWidget* m_proxyWidget;
    QPixmap m_rightArrowImage;
    
    int m_textX, m_textY;
    int m_iconX, m_iconY;
    
    int m_textHeightAdjust;
    
    bool m_paintEnable;
    
    MenuItem::Alignment m_align;
};

#endif // MENUITEM_H
