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

#ifndef TREE_NAVIGATION_ITEM_H
#define TREE_NAVIGATION_ITEM_H

#include <QList>
#include <QVariant>
#include <QVector>

class tree_navigation_item
{
public:
    enum class item_type
    {
        gate      = 0,
        net       = 1,
        module = 2,
        structure = 3,
        ignore    = 4
    };

    tree_navigation_item(const QVector<QVariant>& data, item_type type = item_type::ignore, tree_navigation_item* parent = 0);
    ~tree_navigation_item();

    //information access
    int get_child_count() const;
    int get_column_count() const;
    int get_row_number() const;
    tree_navigation_item* get_child(int row);
    tree_navigation_item* get_parent();
    QVariant data(int column) const;
    item_type get_type();

    //information manipulation
    bool insert_child(int row_position, tree_navigation_item* item);
    bool set_data(int column, const QVariant& value);
    bool remove_children(int position, int count);
    bool remove_child(tree_navigation_item* item);

private:
    QList<tree_navigation_item*> m_child_items;
    QVector<QVariant> m_data;
    tree_navigation_item* m_parent_item;
    item_type m_type;
};

#endif    // TREE_NAVIGATION_ITEM_H
