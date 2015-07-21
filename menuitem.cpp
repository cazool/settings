#include "menuitem.h"

MenuItem::MenuItem()
{
    boundImageToRightArrow();
    m_iconFlag = false;
    m_textHeightAdjust = 5;
    m_paintEnable = true;
}

MenuItem::MenuItem(QGraphicsScene *scene,QString name)
{
    m_scene = scene;
    setText(name);
    m_iconFlag = false;
    m_scene->addItem(this);
    m_textHeightAdjust = 5;
    m_paintEnable = true;
    m_align = left;
}

MenuItem::MenuItem(QGraphicsScene *scene,QString imagePath, QString name)
{
    m_scene = scene;
    boundImageToPress(imagePath);
    boundImageToRelease(imagePath);
    boundImageToHover(imagePath);
    boundImageToRightArrow();
    setText(name);
    m_iconFlag = true;
    m_scene->addItem(this);
    m_textHeightAdjust = 5;
    m_paintEnable = true;
    m_align = left;
}

MenuItem::MenuItem(QGraphicsScene *scene,QString name, MenuItem::Alignment align)
{
    m_scene = scene;
    setText(name);
    m_iconFlag = false;
    m_scene->addItem(this);
    m_textHeightAdjust = 5;
    m_paintEnable = true;
    m_align = align;
}

MenuItem::MenuItem(QGraphicsScene *scene,QString imagePath, QString name, MenuItem::Alignment align)
{
    m_scene = scene;
    boundImageToPress(imagePath);
    boundImageToRelease(imagePath);
    boundImageToHover(imagePath);
    boundImageToRightArrow();
    setText(name);
    m_iconFlag = true;
    m_scene->addItem(this);
    m_textHeightAdjust = 5;
    m_paintEnable = true;
    m_align = align;
}

void MenuItem::setAlignment(MenuItem::Alignment align)
{
    switch(align)
    {
    case center:
        m_iconX = 0;
        m_iconY = -releaseImage.height()/2;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = m_textHeightAdjust;
        break;
    case left:
        m_iconX = -width/2+MARGIN_EDGE;
        m_iconY = -releaseImage.height()/2;
        m_textX = m_iconX + releaseImage.width() + MARGIN_ICON_TEXT;
        m_textY = m_textHeightAdjust;
        break;
    case right:
        m_iconX = width/4;
        m_iconY = -releaseImage.height()/2;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = m_textHeightAdjust;
        break;
    case top:
        m_iconX = 0;
        m_iconY = -boundHeight()/2 + MARGIN_EDGE;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = -boundHeight()/2 + HEIGHT_TEXT + m_textHeightAdjust;
        break;
    case topLeft:
        m_iconX = -width/2+MARGIN_EDGE;
        m_iconY = -boundHeight()/2 + MARGIN_EDGE;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = -boundHeight()/2 + HEIGHT_TEXT + m_textHeightAdjust;
        break;
    case topRight:
        m_iconX = width/4;
        m_iconY = -boundHeight()/2 + MARGIN_EDGE;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = -boundHeight()/2 + HEIGHT_TEXT + m_textHeightAdjust;
        break;
    case bottom:
        m_iconX = 0;
        m_iconY = releaseImage.height()/2 - boundHeight()/2 - MARGIN_EDGE;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = boundHeight()/2 - m_textHeightAdjust;
        break;
    case bottomLeft:
        m_iconX = -width/2+MARGIN_EDGE;
        m_iconY = releaseImage.height()/2 - boundHeight()/2 - MARGIN_EDGE;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = boundHeight()/2 - m_textHeightAdjust;
        break;
    case bottomRight:
        m_iconX = width/4;
        m_iconY = releaseImage.height()/2 - boundHeight()/2 - MARGIN_EDGE;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = boundHeight()/2 - m_textHeightAdjust;
        break;
    default:
        m_iconX = 0;
        m_iconY = -releaseImage.height()/2;
        m_textX = m_iconX + releaseImage.width() +MARGIN_ICON_TEXT;
        m_textY = m_textHeightAdjust;
        break;
    }
}

void MenuItem::createItem()
{
    setAlignment(m_align);
}

void MenuItem::addWidget(QWidget *widget)
{
    m_proxyWidget = new QGraphicsProxyWidget(this);
    m_proxyWidget->setWidget(widget);
}

void MenuItem::addWidget(QWidget *widget, MenuItem::Alignment align)
{
    switch(align)
    {
    case center:
        widget->setGeometry(-widget->width()/2, -widget->height()/2,
                            widget->width(),widget->height());
        break;
    case left:
        widget->setGeometry(-width/2+MARGIN_EDGE,-widget->height()/2,
                            widget->width(),widget->height());
        break;
    case right:
        widget->setGeometry(width/2-widget->width()-MARGIN_EDGE, -widget->height()/2,
                            widget->width(),widget->height());
        break;
    case top:
        widget->setGeometry(-widget->width()/2, - height/2 + MARGIN_EDGE,
                            widget->width(),widget->height());
        break;
    case topLeft:
        widget->setGeometry(-width/2+MARGIN_EDGE, - height/2 + MARGIN_EDGE,
                            widget->width(),widget->height());
        break;
    case topRight:
        widget->setGeometry(width/2-widget->width()-MARGIN_EDGE, - height/2 + MARGIN_EDGE,
                            widget->width(),widget->height());
        break;
    case bottom:
        widget->setGeometry(-widget->width()/2, widget->height() - height/2 - MARGIN_EDGE,
                            widget->width(),widget->height());
        break;
    case bottomLeft:
        widget->setGeometry(-width/2+MARGIN_EDGE, widget->height() - height/2 - MARGIN_EDGE,
                            widget->width(),widget->height());
        break;
    case bottomRight:
        widget->setGeometry(width/2-widget->width()-MARGIN_EDGE, widget->height() - height/2 - MARGIN_EDGE,
                            widget->width(),widget->height());
        break;
    default:
        widget->setGeometry(-widget->width()/2, -widget->height()/2,
                            widget->width(),widget->height());
        break;
    }
    m_proxyWidget = new QGraphicsProxyWidget(this);
    m_proxyWidget->setWidget(widget);
}

void MenuItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    if(m_paintEnable)
    {
        if(pressed)
        {
            if(backgroundEnabled)
            {
                painter->setPen(pressBackgroundColor);
                painter->setBrush(pressBackgroundColor);
                painter->drawRect(x_axis, y_axis, width, height);
            }
            painter->drawPixmap(m_iconX,m_iconY,
                                releaseImage.width(),releaseImage.height(),pressImage);
        }
        else if(hovered)
        {
            if(backgroundEnabled)
            {
                painter->setPen(hoverBackgroundColor);
                painter->setBrush(hoverBackgroundColor);
                painter->drawRect(x_axis, y_axis, width, height);
            }
            painter->drawPixmap(m_iconX,m_iconY,
                                releaseImage.width(),releaseImage.height(),hoverImage);
        }
        else
        {
            if(backgroundEnabled)
            {
                painter->setPen(releaseBackgroundColor);
                painter->setBrush(releaseBackgroundColor);
                painter->drawRect(x_axis, y_axis, width, height);
            }
            painter->drawPixmap(m_iconX,m_iconY,
                                releaseImage.width(),releaseImage.height(),releaseImage);
        }
        
        
        if(m_iconFlag)
            painter->drawPixmap(width/2-30,-m_rightArrowImage.height()/2,
                            m_rightArrowImage.width(),m_rightArrowImage.height(),m_rightArrowImage);
        
        painter->setPen(getTextColor());
        painter->setBrush(getTextColor());
        
        painter->drawText(m_textX, m_textY,text());
        
        painter->setPen(Qt::lightGray);
        painter->drawLine(boundX(),boundY()+boundHeight()-1,boundX()+boundWidth(),boundY()+boundHeight()-1);
     }
}

void MenuItem::boundImageToRightArrow()
{
    m_rightArrowImage.load("../myScene/resources/images/right_arrow.png");
}
