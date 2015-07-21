#include "settingsmenu.h"

SettingsMenu::SettingsMenu()
{
    m_scene.setSceneRect(-150,-300,300,600);
    m_view.resize(300, 700);
    m_view.setBackgroundBrush(QColor(255,255,255,255));
    m_itemIndex = 0;
}

void SettingsMenu::addMenu(MenuItem * item)
{
    item->setPos(0, -250 + m_itemIndex*60);
    item->setBounds(-150,-30,300,60);
    item->setHoverEnableFlag(true);
    item->setBackgroundEnable(true);
    m_scene.addItem(item);
    m_itemIndex++;
}

void SettingsMenu::display()
{
    m_view.setScene(&m_scene);
    m_view.show();
}
