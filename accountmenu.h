#ifndef ACCOUNTMENU_H
#define ACCOUNTMENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "menucontroller.h"
#include "addaccount.h"
#include "menuitem.h"

class AccountMenu : public QGraphicsScene, public MenuController
{
    Q_OBJECT
public:
    explicit AccountMenu(QObject *parent = 0);
    
    AccountMenu(QGraphicsView *view,MenuController *parent);
    
    void createMenu();
    
    void createActions();
    
signals:
    
public slots:
    
    void showScene();
    void returnSlot();
    
private:
    MenuController *m_parent;
    MenuItem *m_addButton;
    MenuItem *m_returnToMainMenu;
    AddAccount *m_addAccount;
    
    
};

#endif // ACCOUNTMENU_H
