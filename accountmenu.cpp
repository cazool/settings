#include "accountmenu.h"


AccountMenu::AccountMenu(QObject *parent) :
    QGraphicsScene(parent)
{
    
}

AccountMenu::AccountMenu(QGraphicsView *view, MenuController *parent)
{
    m_parent = parent;
    setScene(this);
    setView(view);
    setSceneRect(-150,-265,300,650);
    createMenu();
    createActions();
}

void AccountMenu::createMenu()
{
    m_returnToMainMenu = new MenuItem(getScene(),"返回主页");
    addMenu(m_returnToMainMenu);        
    m_addButton = new MenuItem(getScene(),"./resources/icons/add.png","添加账户");
    addMenu(m_addButton);
    
    m_addAccount = new AddAccount(getView(),this);
}

void AccountMenu::createActions()
{
    m_addButton->connect(m_addButton,SIGNAL(clicked()),m_addAccount,SLOT(showScene()));
    m_returnToMainMenu->connect(m_returnToMainMenu,SIGNAL(clicked()),this,SLOT(returnSlot()));
}

void AccountMenu::returnSlot()
{
    m_parent->display();
}

void AccountMenu::showScene()
{
    display();
}
