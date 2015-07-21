#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "menuitem.h"

class SettingsMenu : public QObject
{
    Q_OBJECT
public:
    SettingsMenu();
    void addMenu(MenuItem * item);
    void display();
    
private:
    QGraphicsScene m_scene;
    QGraphicsView  m_view;
    int m_itemIndex;
};

#endif // SETTINGSMENU_H
