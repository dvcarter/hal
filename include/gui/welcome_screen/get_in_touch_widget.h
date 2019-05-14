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

#ifndef GET_IN_TOUCH_WIDGET_H
#define GET_IN_TOUCH_WIDGET_H

#include "QFrame"

class get_in_touch_item;

class QLabel;
class QVBoxLayout;

class get_in_touch_widget : public QFrame
{
    Q_OBJECT

public:
    get_in_touch_widget(QWidget* parent = nullptr);

    void repolish();

public Q_SLOTS:
    void handle_about_item_clicked();
    void handle_cpp_documentation_item_clicked();
    void handle_py_documentation_item_clicked();
    void handle_ticket_item_clicked();

private:
    QVBoxLayout* m_layout;

    get_in_touch_item* m_about_item;
    get_in_touch_item* m_news_item;
    get_in_touch_item* m_forum_item;
    get_in_touch_item* m_cpp_documentation_item;
    get_in_touch_item* m_py_documentation_item;
    get_in_touch_item* m_ticket_item;

    //    QFrame* m_line;
    QLabel* m_core_version_label;
    QLabel* m_gui_version_label;
};

#endif    // GET_IN_TOUCH_WIDGET_H
