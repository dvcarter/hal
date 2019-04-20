#include "graph_widget/layouters/orthogonal_graph_layouter.h"

#include "graph_widget/graphics_scene.h"
#include "graph_widget/graphics_items/graphics_gate.h"
#include "graph_widget/graphics_items/separated_graphics_net.h"
#include "graph_widget/graphics_items/standard_graphics_net.h"
#include "gui_globals.h"

#include "graph_widget/graphics_items/advanced_graphics_gate.h"
#include "graph_widget/graphics_items/standard_graphics_gate.h"

orthogonal_graph_layouter::orthogonal_graph_layouter(graph_context* context, QObject* parent) : graph_layouter(context, parent)
{

}

void orthogonal_graph_layouter::layout()
{
    int x;
    int y;
    int i = 0;
    QList<graphics_gate*> nodes;
    QMap<std::shared_ptr<gate>, graphics_gate*> map;

    for (auto& g : g_netlist->get_gates())
    {
        graphics_gate* node_item = new advanced_graphics_gate(g);
        nodes.append(node_item);
        map.insert(g, node_item);
        x = i * 200 % 20000;
        y = i / 100 * 100;
        node_item->setPos(QPointF(x, y));
        m_scene->addItem(node_item);
        i++;
    }

    //    for (auto n : g_netlist->get_nets())
    //    {
    //        endpoint src_end = n->get_src();
    //        graphics_gate* src_node = map.value(src_end.gate);
    //        if (!src_node)
    //        {
    //            //no src node
    //            separated_graphics_net* net_item = new separated_graphics_net(QString::fromStdString(n->get_name()), n);
    //            for (endpoint dst_end : n->get_dsts())
    //            {
    //                graphics_gate* dst_node = map.value(dst_end.gate);
    //                if (!dst_node)
    //                {
    //                    //no dst node
    //                    continue;
    //                }

    //                QPointF dst_position = dst_node->get_mapped_input_pin_position(QString::fromStdString(dst_end.pin_type));
    //                net_item->add_input(dst_position);
    //            }
    //            m_scene->addItem(net_item);
    //        }
    //        i++;
    //    }
    //}

    for (auto& n : g_netlist->get_nets())
    {
        if (n->is_unrouted())
            continue;

        endpoint src_end        = n->get_src();
        graphics_gate* src_node = map.value(src_end.gate);
        if (!src_node)
        {
            //no src node TODO handle
            continue;
        }

        QPointF src_position            = src_node->get_output_pin_scene_position(QString::fromStdString(src_end.pin_type));
        standard_graphics_net* net_item = new standard_graphics_net(n);
        net_item->setPos(src_position);

        for (endpoint& dst_end : n->get_dsts())
        {
            graphics_gate* dst_node = map.value(dst_end.gate);
            if (!dst_node)
            {
                //no dst node TODO handle
                continue;
            }

            QPointF dst_position = dst_node->get_input_pin_scene_position(QString::fromStdString(dst_end.pin_type));

            //            net_item->line_to(QPointF(net_item->current_scene_position().x() + 2, net_item->current_scene_position().y()));
            //            net_item->line_to(QPointF(net_item->current_scene_position().x(), dst_position.y()));
            //            net_item->line_to(QPointF(dst_position.x(), net_item->current_scene_position().y()));
            //            net_item->move_pen_to(src_position);

            QPointF position = QPointF(src_position.x() + 2, src_position.y());
            net_item->line_to(position);
            position = QPointF(position.x(), dst_position.y());
            net_item->line_to(position);
            net_item->line_to(QPointF(dst_position.x(), position.y()));
            net_item->move_pen_to(src_position);
        }
        net_item->setZValue(-1);
        net_item->finalize();
        m_scene->addItem(net_item);
        i++;
    }
}

void orthogonal_graph_layouter::reset()
{

}

void orthogonal_graph_layouter::add(const QSet<u32> gates, const QSet<u32> nets)
{
    Q_UNUSED(gates)
    Q_UNUSED(nets)
}

void orthogonal_graph_layouter::remove(const QSet<u32> gates, const QSet<u32> nets)
{
    Q_UNUSED(gates)
    Q_UNUSED(nets)
}

void orthogonal_graph_layouter::expand(const u32 from_gate, const u32 via_net, const u32 to_gate)
{
    Q_UNUSED(from_gate)
    Q_UNUSED(via_net)
    Q_UNUSED(to_gate)
}

const QString orthogonal_graph_layouter::name() const
{
    return "Orthogonal Layouter";
}

const QString orthogonal_graph_layouter::description() const
{
    return "<p>A fast and simple layouting strategy, nodes are randomly place in a grid and nets are drawn as orthogonal lines</p>";
}