/** <Tools to work with server-client communications and converting to char*>
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
* along with this program.  If not, see <http:///www.gnu.org/licenses/>.
*/


#ifndef UTILITY_H
#define UTILITY_H

#include "QString"
#include <iostream>
#include <QTextStream>

namespace Utility
{
    /// Code extractors
    QString opcode(char *string);
    QString username(char *string);
    QString immediate(char* string);

    /// Conversions
    const char* convert(QString str);
    const char* convert(std::string str);

    ///Debug options
    void debugEnable();
    void debugDisable();
    bool debug(QString str);

    static bool use_debug_mode = false;

}

#endif /// UTILITY_H
