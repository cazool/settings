/****************************************************************************
**
**  Copyright (C) 2011~2015 Deepin, Inc.
**                2011~2015 Zhe Wang
**
**  Author:     Zhe Wang <wzedmund@gmail.com>
**  Maintainer: 
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include "DButton.h"
#include "DSwitchbutton.h"
#include "DNavigationbar.h"
#include "daccountview.h"
#include "dstatictext.h"
#include "ditemlist.h"
#include "dscrollarea.h"
#include "mainmenu.h"
#include "menuitem.h"

const char *pressIcon[50] = {
    "../myScene/resources/icons/account_press.png",
    "../myScene/resources/icons/display_press.png",
    "../myScene/resources/icons/default_applications_press.png",
    "../myScene/resources/icons/personalization_press.png",
    "../myScene/resources/icons/network_press.png",
    "../myScene/resources/icons/sound_press.png",
    "../myScene/resources/icons/date_time_press.png",
    "../myScene/resources/icons/power_press.png",
    "../myScene/resources/icons/mouse_touchpad_press.png",
    "../myScene/resources/icons/keyboard_press.png",
    "../myScene/resources/icons/shortcuts_press.png",
    "../myScene/resources/icons/grub_press.png",
    "../myScene/resources/icons/system_info_press.png"
};

const char *releaseIcon[50] = {
    "../myScene/resources/icons/account_normal.png",
    "../myScene/resources/icons/display_normal.png",
    "../myScene/resources/icons/default_applications_normal.png",
    "../myScene/resources/icons/personalization_normal.png",
    "../myScene/resources/icons/network_normal.png",
    "../myScene/resources/icons/sound_normal.png",
    "../myScene/resources/icons/date_time_normal.png",
    "../myScene/resources/icons/power_normal.png",
    "../myScene/resources/icons/mouse_touchpad_normal.png",
    "../myScene/resources/icons/keyboard_normal.png",
    "../myScene/resources/icons/shortcuts_normal.png",
    "../myScene/resources/icons/grub_normal.png",
    "../myScene/resources/icons/system_info_normal.png"
};

const char *hoverIcon[50] = {
    "../myScene/resources/icons/account_hover.png",
    "../myScene/resources/icons/display_hover.png",
    "../myScene/resources/icons/default_applications_hover.png",
    "../myScene/resources/icons/personalization_hover.png",
    "../myScene/resources/icons/network_hover.png",
    "../myScene/resources/icons/sound_hover.png",
    "../myScene/resources/icons/date_time_hover.png",
    "../myScene/resources/icons/power_hover.png",
    "../myScene/resources/icons/mouse_touchpad_hover.png",
    "../myScene/resources/icons/keyboard_hover.png",
    "../myScene/resources/icons/shortcuts_hover.png",
    "../myScene/resources/icons/grub_hover.png",
    "../myScene/resources/icons/system_info_hover.png"
};

int main(int argc,char* argv[ ])
{
    QApplication app(argc,argv);
    
    QGraphicsView view;
    view.resize(300, 700);
    view.setBackgroundBrush(QColor(255,255,255,255));
    
    MainMenu *menu = new MainMenu(&view);    
    menu->showScene();
    
    return app.exec();
}

