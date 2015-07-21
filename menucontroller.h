#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "menuitem.h"
#include <QGraphicsScene>
#include <QGraphicsView>

class MenuController
{
public:
    MenuController();
    
    void setScene(QGraphicsScene *scene);
    
    void setView(QGraphicsView *view);
    
    void addMenu(MenuItem * item);
    
    void addMenu(MenuItem * item,int row);
    
    void addMenu(MenuItem * item,int row,int col,int maxColum);
    
    int m_rowIndex;
    
    void display();
    
    QGraphicsView* getView();
    
    QGraphicsScene* getScene();

private:
    QGraphicsScene *m_scene;
    QGraphicsView  *m_view;
};

#endif // MENUCONTROLLER_H
