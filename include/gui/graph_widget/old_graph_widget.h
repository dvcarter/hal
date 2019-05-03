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

#ifndef OLD_GRAPH_WIDGET_H
#define OLD_GRAPH_WIDGET_H

#include "content_widget/content_widget.h"
#include "graph_widget/graph_graphics_view.h"

class graph_layouter_selection_widget;

class QHBoxLayout;
class QToolButton;
class QSlider;
class QStackedWidget;

class old_graph_widget : public content_widget
{
    Q_OBJECT

public:
    explicit old_graph_widget(QWidget* parent = nullptr);

    virtual void setup_toolbar(toolbar* toolbar) Q_DECL_OVERRIDE;

    void subscribe(QString layouter);

    graph_graphics_view* view() const;
    QString get_layouter();

    void show_view();

public Q_SLOTS:
    void zoom_in(int level = 1);
    void zoom_out(int level = 1);

protected:
    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void update_matrix();
    void show_layout_selection(bool checked);
    //    void toggle_pointer_mode();
    void toggle_antialiasing();

private:
    QStackedWidget* m_stacked_widget;
    graph_layouter_selection_widget* m_selection_widget;
    QWidget* m_view_container;
    QHBoxLayout* m_container_layout;
    graph_graphics_view* m_view;
    QSlider* m_zoom_slider;
    QString m_layouter;
};

#endif // OLD_GRAPH_WIDGET_H
