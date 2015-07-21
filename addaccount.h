#ifndef ADDACCOUNT_H
#define ADDACCOUNT_H

#include <QGraphicsScene>
#include <QLineEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include "menuitem.h"
#include "menucontroller.h"

class AddAccount : public QGraphicsScene, public MenuController
{
    Q_OBJECT
public:
    explicit AddAccount(QObject *parent = 0);
    
    AddAccount(QGraphicsView *view, MenuController *parent);
    
    void createMenu();
    
    void createActions();
    
signals:
    
public slots:
    void showScene();
    void okSlot();
    void cancelSlot();
    
private:
    MenuController *m_parent;
    MenuItem *m_userName;
    MenuItem *m_password;
    MenuItem *m_repeat;
    MenuItem *m_accountType;
    MenuItem *m_autoLogin;
    
    MenuItem *m_ok;
    MenuItem *m_cancel;
    
    QLineEdit *m_userNameLineEdit;
    QLineEdit *m_passwordLineEdit;
    QLineEdit *m_repeatLineEdit;
    
    QRadioButton *m_adminRadio;
    QRadioButton *m_userRadio;
};

#endif // ADDACCOUNT_H
