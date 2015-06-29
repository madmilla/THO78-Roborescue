#include <QObject>
/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
*  @file    mapwindow.h
*  @date    Last Edit:2015-04-13
*
*  @author  ??
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms, with or without
*	modification, are permitted provided that the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice,
*		this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice,
*		this list of conditions and the following disclaimer in the
*		documentation and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht nor the
*		names of its contributors may be used to endorse or promote products
*		derived from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
*	TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
*	PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED
*	SCIENCES UTRECHT BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
*	OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
*	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
*	OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#include <QObject>
#include <QtWidgets/QMainWindow>

/*
#if !defined(QOBJECT_H)
#QOBJECT_H not defined
#endif
#if defined(QT_NO_QOBJECT)
#QT_NO_QOBJECT not defined
#endif
#if !defined(QOBJECTDEFS_H)
#QOBJECTDEFS_H not defined
#endif
#ifdef Q_MOC_OUTPUT_REVISION
#Q_MOC_OUTPUT_REVISION defined
Q_MOC_OUTPUT_REVISION
#else
#Q_MOC_OUTPUT_REVISION not defined
#endif

/

#ifndef MAPWINDOW_H
#define MAPWINDOW_H


namespace Ui {
class MapWindow;
}

/**
* @class   MapWindow
* @author  ??
* @date    ??
* @brief   ??
*/
class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
   /**
     * @brief MapWindow create
     * @param parent possible parent window
     */
    explicit MapWindow(QWidget *parent = 0);

   /**
     * Deconstructor of the map
     */
   ~MapWindow();

private:
    Ui::MapWindow *ui;
};

#endif // MAPWINDOW_H
