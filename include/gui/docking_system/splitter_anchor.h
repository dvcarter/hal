//  MIT License
//
//  Copyright (c) 2019 Ruhr-University Bochum, Germany, Chair for Embedded Security. All Rights reserved.
//  Copyright (c) 2019 Marc Fyrbiak, Sebastian Wallat, Max Hoffmann ("ORIGINAL AUTHORS"). All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#ifndef SPLITTER_ANCHOR_H
#define SPLITTER_ANCHOR_H

#include "hal_content_anchor/hal_content_anchor.h"

#include <QList>
#include <QObject>

class dock_bar;
class splitter;
class content_frame;
class content_widget;

class splitter_anchor : public QObject, public hal_content_anchor
{
    Q_OBJECT

public:
    splitter_anchor(dock_bar* dock_bar, splitter* splitter, QObject* parent = 0);

    virtual void add(content_widget* widget, int index = -1) override;
    virtual void remove(content_widget* widget) override;
    virtual void detach(content_widget* widget) override;
    virtual void reattach(content_widget* widget) override;
    virtual void open(content_widget* widget) override;
    virtual void close(content_widget* widget) override;

    int count();
    void remove_content();

Q_SIGNALS:
    void content_changed();

private:
    dock_bar* m_dock_bar;
    splitter* m_splitter;
    QList<content_frame*> m_detached_frames;
};

#endif    // SPLITTER_ANCHOR_H
