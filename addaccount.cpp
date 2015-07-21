#include "addaccount.h"

AddAccount::AddAccount(QObject *parent) :
    QGraphicsScene(parent)
{
}

AddAccount::AddAccount(QGraphicsView *view, MenuController *parent)
{
    m_parent = parent;
    setScene(this);
    setView(view);
    setSceneRect(-150,-265,300,650);
    createMenu();
    createActions();
}

void AddAccount::createMenu()
{
   m_userName = new MenuItem(getScene(),"用户名称",MenuItem::left);
   m_password = new MenuItem(getScene(),"密码",MenuItem::left);
   m_repeat = new MenuItem(getScene(),"重复密码",MenuItem::left);
   m_accountType = new MenuItem(getScene(),"账户类型");
   m_autoLogin = new MenuItem(getScene(),"自动登陆");
   
   m_ok = new MenuItem(getScene(),"确定");
   m_cancel = new MenuItem(getScene(),"取消");
   
   addMenu(m_userName);
   m_userNameLineEdit = new QLineEdit("");
   m_userNameLineEdit->resize(200,30);
   m_userName->addWidget(m_userNameLineEdit,MenuItem::right);
   addMenu(m_password);
   m_passwordLineEdit = new QLineEdit("");
   m_passwordLineEdit->resize(200,30);
   m_password->addWidget(m_passwordLineEdit,MenuItem::right);
   addMenu(m_repeat);
   m_repeatLineEdit = new QLineEdit("");
   m_repeatLineEdit->resize(200,30);
   m_repeat->addWidget(m_repeatLineEdit,MenuItem::right);
   addMenu(m_accountType);
   m_adminRadio = new QRadioButton("管理员");
   m_adminRadio->resize(90,20);
   m_userRadio = new QRadioButton("普通用户");
   m_userRadio->resize(90,20);
   
   //m_adminRadio->connect(m_adminRadio,SIGNAL(),m_userRadio,SLOT(setChecked(bool)));
   
   m_accountType->addWidget(m_adminRadio,MenuItem::center);
   m_accountType->addWidget(m_userRadio,MenuItem::right);
   
   addMenu(m_autoLogin); 
   addMenu(m_ok,5,0,2);
   addMenu(m_cancel,5,1,2);
}

void AddAccount::createActions()
{
    m_ok->connect(m_ok,SIGNAL(clicked()),this,SLOT(okSlot()));
    m_cancel->connect(m_cancel,SIGNAL(clicked()),this,SLOT(cancelSlot()));
}

void AddAccount::okSlot()
{
    m_parent->display();
}

void AddAccount::cancelSlot()
{
    m_parent->display();
}


void AddAccount::showScene()
{
    display();
}
