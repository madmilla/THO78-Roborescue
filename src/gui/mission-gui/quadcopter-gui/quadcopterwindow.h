/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
*  @file quadcopterwindow.h
*  @date Last Edit:	2015-04-13
*
*  @author	Kevin Nijmeijer
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

#ifndef QUADCOPTERWINDOW_H
#define QUADCOPTERWINDOW_H

#include <QtWidgets/QMainWindow>
#include "Listener.h"
#include "StatusText.h"

class Quadcopter;

namespace Ui {
class QuadcopterWindow;
}

/**
* @class  QuadcopterWindow
* @author Kevin Nijmeijer
* @date   April, 2015
* @brief  this class handles ui input from the RosbeeWindow
*/
class QuadCopterWindow : public QMainWindow, public Listener
{
    Q_OBJECT

public:
    /**
    * @brief QuadCopterWindow constructor
    * @param quadcopter A reference to a Quadcopter object
    * @param parent A QWidget parent, default = 0
    */
    explicit QuadCopterWindow( Quadcopter& quadcopter, QWidget *parent = 0);

   /**
    * Deconstructor Window
    */
    ~QuadCopterWindow();

private slots:

    void on_sendMaxAltitudeButton_clicked();

    void on_armButton_clicked();

    void on_takeOff_LandButton_clicked();

    void on_restartButton_clicked();

    void on_abortButton_clicked();


private:
    Ui::QuadcopterWindow *ui;
    Quadcopter& quadcopter;
	
    void notifyListener(Subject&, StatusText statusText) override;
};

#endif // QUADCOPTERWINDOW_H
