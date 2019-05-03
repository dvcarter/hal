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

#ifndef GRAPH_LAYOUTER_MANAGER_H
#define GRAPH_LAYOUTER_MANAGER_H

#include <QList>
#include <QObject>
#include <QPair>

class graph_layouter;
class graphics_scene;

class graph_layouter_manager : public QObject
{
    Q_OBJECT

public:
    static graph_layouter_manager& get_instance();
    ~graph_layouter_manager();

    graphics_scene* subscribe(QString layouter);
    void unsubscribe(QString layouter);

    QStringList get_layouters();
    QString get_name(QString layouter);
    QString get_description(QString layouter);

private:
    explicit graph_layouter_manager(QObject* parent = nullptr);

    QList<QPair<graph_layouter*, int>> m_layouters;
};

#endif // GRAPH_LAYOUTER_MANAGER_H
