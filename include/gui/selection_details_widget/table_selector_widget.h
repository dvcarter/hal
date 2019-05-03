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

#ifndef TABLE_SELECTOR_WIDGET_H
#define TABLE_SELECTOR_WIDGET_H

#include <QSet>
#include <QStringList>
#include <QTableWidget>
#include <QWidget>
#include <netlist/gate.h>

class table_selector_widget : public QTableWidget
{
    Q_OBJECT
public:
    table_selector_widget(QWidget* parent = nullptr);
    table_selector_widget(std::set<std::shared_ptr<gate>> table_data, QWidget* parent = nullptr);

    void focusOutEvent(QFocusEvent* event);
    void keyPressEvent(QKeyEvent *event);

Q_SIGNALS:
    void gateSelected(std::shared_ptr<gate> selected);

private:
    QSize calculate_actual_table_size();

    void on_item_double_clicked(QTableWidgetItem* item);
};

#endif    // TABLE_SELECTOR_WIDGET_H
