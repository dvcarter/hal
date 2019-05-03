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

#ifndef __HAL_GRAPH_MODEL_H__
#define __HAL_GRAPH_MODEL_H__

#include "graph_model_item.h"
#include "netlist/gate.h"
#include "netlist/net.h"
#include "netlist/netlist.h"
#include <QAbstractItemModel>
#include <QList>
#include <QModelIndex>
#include <QObject>
#include <QStringList>
#include <QVariant>

/*the table-model for the netlist*/
class graph_model : public QAbstractItemModel
{
    Q_OBJECT
public:
    /*all the things that are needed for the tablem-model*/
    explicit graph_model(QObject* parent = 0);

    QVariant data(const QModelIndex& index, int role) const Q_DECL_OVERRIDE;

    Qt::ItemFlags flags(const QModelIndex& index) const Q_DECL_OVERRIDE;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QModelIndex parent(const QModelIndex& index) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;

    /*maps the graph into the model*/
    void setupModelData(std::shared_ptr<netlist> g);

    /*removes all the items from the model*/
    void clear();

private:
    QStringList m_columns;

    QList<graph_model_item*> m_items;
};

#endif    //__HAL_GRAPH_MODEL_H__
