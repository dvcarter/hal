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

#ifndef SCHEDULED_PLUGIN_ITEM_AREA_H
#define SCHEDULED_PLUGIN_ITEM_AREA_H

#include <QFrame>
#include <QList>
#include <QPair>
#include <QVector>

class drop_marker;
class scheduled_plugin_item;

class QVBoxLayout;

class scheduled_plugin_item_area : public QFrame
{
    Q_OBJECT

public:
    explicit scheduled_plugin_item_area(QWidget* parent = nullptr);

    void dragEnterEvent(QDragEnterEvent* event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent* event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QDragLeaveEvent* event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent* event) Q_DECL_OVERRIDE;

    void insert_plugin(const QString& name);

Q_SIGNALS:
    void plugin_added(QString plugin, int index);
    void plugin_moved(int from, int to);
    void plugin_removed(int index);

    void plugin_selected(int index);

    void no_scheduled_plugins();

public Q_SLOTS:
    void handle_item_clicked(scheduled_plugin_item* item);
    void handle_item_drag_started(scheduled_plugin_item* item);
    void handle_item_removed(scheduled_plugin_item* item);

private:
    QVBoxLayout* m_layout;
    QFrame* m_spacer;

    QVector<int> m_y_values;
    QList<QPair<scheduled_plugin_item*, drop_marker*>> m_list;

    drop_marker* m_active_marker;

    bool m_internal_drag_active;
    int m_drag_index;
};

#endif    // SCHEDULED_PLUGIN_ITEM_AREA_H
