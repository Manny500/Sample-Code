/** <Start the event loop of the client>
* Copyright (C) <2015-04-17>  <Manuel Tenorio>

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "CatanFace.h"
#include "CrazyFace.h"
#include "CloudGaming.h"
#include "ChangeSuit.h"
#include "Drop.h"
#include "SplashScreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SplashScreen splashy;
    splashy.show();


    return a.exec();
}
