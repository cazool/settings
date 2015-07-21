#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "menucontroller.h"
#include "accountmenu.h"

class MainMenu : public QGraphicsScene, public MenuController
{
    Q_OBJECT
public:
    explicit MainMenu(QObject *parent = 0);
    
    MainMenu(QGraphicsView *view);
    
    void createMenu();
    
    void createActions();
    
    void createAccountMenu();
    
signals:
    
public slots:
    void showScene();
    
private:
    AccountMenu *m_accountMenu;
    
    MenuItem *m_accountItem;
    MenuItem *m_displayItem;
    MenuItem *m_networkItem;
    MenuItem *m_settingItem;
    MenuItem *m_powerItem;
    
    MenuItem *m_personalizationItem;
    MenuItem *m_volumeItem;
    MenuItem *m_dateItem;
    MenuItem *m_infoItem;
};

#endif // MAINMENU_H
