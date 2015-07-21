#include "menucontroller.h"

MenuController::MenuController()
{
    m_rowIndex = 0;
}

void MenuController::addMenu(MenuItem * item)
{
    item->setPos(0, -250 + m_rowIndex*60);
    item->setBounds(-150,-30,300,60);
    item->setHoverEnableFlag(true);
    item->setBackgroundEnable(true);
    m_rowIndex++;
    item->createItem();
}

void MenuController::addMenu(MenuItem * item,int row)
{
    item->setPos(0, -250 + row*60);
    item->setBounds(-150,-30,300,60);
    item->setHoverEnableFlag(true);
    item->setBackgroundEnable(true);
    item->createItem();
}

void MenuController::addMenu(MenuItem * item,int row,int col,int maxColum)
{
    item->setPos(0, -250 + row*60);
    item->setBounds(-150+col*(300/maxColum),-30,300*(col+1)/maxColum,60);
    item->setHoverEnableFlag(true);
    item->setBackgroundEnable(true);
    item->createItem();
}

QGraphicsView *MenuController::getView()
{
    return m_view;
}

QGraphicsScene *MenuController::getScene()
{
    return m_scene;
}

void MenuController::setScene(QGraphicsScene *scene)
{
    m_scene = scene;
}

void MenuController::setView(QGraphicsView *view)
{
    m_view = view;
}

void MenuController::display()
{
    m_view->setScene(m_scene);
    m_view->show();
}
