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
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "Utility.h"
#include "qdebug.h"
namespace Utility{
/**
 * @brief opcode decode opcodes
 * @param string the entire string from the port
 * @return the 6 char opcode
 */
QString opcode(char *string){
    QString code;
    for(int i=0;i<6;i++){
        code.append(string[i]);
        if(string[i] == '\0') return "String too short to decode";
    }
    return code;
}

/**
 * @brief username decode the username
 * @param string the entire string from the port
 * @return the username
 */
QString username(char *string){
    QString name;
    const char comp = '>';
    if(string[6] != '<') {return "Missing <";}
    for(int i=7;i<1023;i++){
        if(string[i] == '\0') break;
        if(string[i] == comp) return name;
        name.append(string[i]);
    }
    return "No name found";
}

/**
 * @brief convert convert a QString into a char*
 * @param str the string to convert
 * @return the char* version of the string
 */
const char* convert(QString str){
   QByteArray ba = str.toLocal8Bit();
   return ba.data();
}

/**
 * @brief convert convert a std::string into a char*
 * @param str the string to convert
 * @return the char* version of the string
 */
const char* convert(std::string str){
    return str.c_str();
}

/**
 * @brief immediate get the immediate field of a transmission
 * @param string the buffer stream
 * @return the immediate value
 */
QString immediate(char* string){
    const char comp = '>';
    bool detected = false;
    int i;
    QString imm;
    for (i=0;i<1023;i++){
        if(string[i] == '\0') break;
        if(string[i] == comp && !detected){
            detected = true;
            continue;
        }
        if(detected){
            imm.append(string[i]);
        }
    }

    if(!detected) return "Invalid string";
    else return imm;
}

void debugEnable(){
    use_debug_mode = true;
}

void debugDisable(){
    use_debug_mode = false;
}

bool debug(QString str){
    if(!use_debug_mode) return false;
    QTextStream out(stdout);
    out << str << endl;
    return true;
}
}

