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

#ifndef EXPANDING_LIST_WIDGET_H
#define EXPANDING_LIST_WIDGET_H

#include <QScrollArea>

class expanding_list_button;
class expanding_list_item;

class QFrame;
class QVBoxLayout;

class expanding_list_widget : public QScrollArea
{
    Q_OBJECT

public:
    expanding_list_widget(QWidget* parent = 0);

    //    bool eventFilter(QObject* object, QEvent* event) Q_DECL_OVERRIDE;

    void append_item(expanding_list_button* button, expanding_list_button* parent_button = 0);
    void select_button(expanding_list_button* button);
    void select_item(int index);

    void repolish();

Q_SIGNALS:
    void button_selected(expanding_list_button* button);

public Q_SLOTS:
    void handle_clicked();

private:
    QFrame* m_content;
    QVBoxLayout* m_content_layout;
    QFrame* m_spacer;

    QList<expanding_list_item*> m_items;

    expanding_list_button* m_selected_button;
    expanding_list_item* m_extended_item;

    int m_item_width;
    int m_offset;
};

#endif    // EXPANDING_LIST_WIDGET_H
