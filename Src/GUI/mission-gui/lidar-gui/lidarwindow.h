/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
*  @file lidarwindow.h
*  @date Last Edit:	2015-04-13
*
*  @author  Thijs van Tiem
*
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

#ifndef LIDARWINDOW_H
#define LIDARWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include <QtCore/QObject>
#include "Lidar.h"

namespace Ui {
class LidarWindow;
}

/**
* @class  LidarWindow
* @author Thijs van Tiem  (thijsvantiem@gmail.com)
* @date   April, 2015
* @brief  the class that handles the lidarwindow and the buttons on it.
*/
class LidarWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    *  Creates the lidar object en sets the qwidget parent
    *	 @param lidar * l create the lidar object
    *  @param QWidget * Parent tells if there are parents or not. there are no parents here.
    **/
    explicit LidarWindow(Lidar & lider, QWidget *parent = 0);

    /**
    *  Deconstructor lidarwindow();
    **/
    ~LidarWindow();

private slots:


    void handleButtonLidar();


private:
    Ui::LidarWindow *ui;
    Lidar & lidar;
};

#endif // LIDARWINDOW_H
