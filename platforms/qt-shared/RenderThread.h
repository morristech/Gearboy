/* 
 * Gearboy Gameboy Emulator
 * Copyright (C) 2012 Ignacio Sanchez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 * The full license is available at http://www.gnu.org/licenses/gpl.html
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef MYRENDERTHREAD_H
#define MYRENDERTHREAD_H

#include <QThread>
#include "../../src/gearboy.h"

class GLFrame;
class QSize;

class RenderThread : public QThread
{
    Q_OBJECT
public:
    explicit RenderThread(GLFrame *parent = 0);
    void resizeViewport(const QSize &size);
    void run(void);
    void stop(void);

protected:
    void GLInit(void);
    void GLResize(int width, int height);
    void paintGL(void);

private:
    bool m_bDoRendering, m_bDoResize;
    int m_iWidth, m_iHeight, m_iFrameCounter;

    GLFrame *m_pGLFrame;

signals:
public slots:
};

#endif // MYRENDERTHREAD_H