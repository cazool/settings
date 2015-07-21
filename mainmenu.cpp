#include "mainmenu.h"

MainMenu::MainMenu(QObject *parent) :
    QGraphicsScene(parent)
{
}

MainMenu::MainMenu(QGraphicsView *view)
{
    setScene(this);
    setView(view);
    setSceneRect(-150,-265,300,650);
    createMenu();
    createAccountMenu();
    createActions();
}

void MainMenu::createMenu()
{
    m_displayItem = new MenuItem(getScene(),"./resources/icons/display.png","显示");
    m_accountItem = new MenuItem(getScene(),"./resources/icons/account.png","账户");
    m_networkItem = new MenuItem(getScene(),"./resources/icons/network.png","网络");
    m_settingItem = new MenuItem(getScene(),"./resources/icons/settings.png","设置");
    m_powerItem = new MenuItem(getScene(),"./resources/icons/power.png","电源");
    
    m_personalizationItem = new MenuItem(getScene(),"./resources/icons/personalization.png","个性化");
    m_volumeItem = new MenuItem(getScene(),"./resources/icons/volume.png","声音");;
    m_dateItem = new MenuItem(getScene(),"./resources/icons/date.png","日期和时间");;
    m_infoItem = new MenuItem(getScene(),"./resources/icons/info.png","信息");;
    

    addMenu(m_displayItem);
    addMenu(m_accountItem);
    addMenu(m_networkItem);
    addMenu(m_settingItem);
    addMenu(m_powerItem);
    
    addMenu(m_personalizationItem);
    addMenu(m_volumeItem);
    addMenu(m_dateItem);
    addMenu(m_infoItem);
}

void MainMenu::createActions()
{
    m_accountItem->connect(m_accountItem,SIGNAL(clicked()),m_accountMenu,SLOT(showScene()));
}

void MainMenu::createAccountMenu()
{
    m_accountMenu = new AccountMenu(getView(),this);
}

void MainMenu::showScene()
{
    display();
}
