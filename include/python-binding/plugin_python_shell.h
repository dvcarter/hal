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

#include "pragma_once.h"
#ifndef __HAL_PLUGIN_PYTHON_SHELL_H__
#define __HAL_PLUGIN_PYTHON_SHELL_H__

#include "core/interface_interactive_ui.h"

class plugin_python_shell : virtual public i_interactive_ui
{
public:
    plugin_python_shell() = default;

    ~plugin_python_shell() = default;

    /*
     *      interface implementations
     */

    /**
     * Get the name of the plugin.
     *
     * @returns Plugin name.
     */
    std::string get_name() override;

    /**
     * Get the version of the plugin.
     *
     * @returns Plugin version.
     */
    std::string get_version() override;

    /**
     * Get the plugin types.
     *
     * @returns Set of types.
     */
    std::set<interface_type> get_type() override;

    /**
     * Excutes the plugin with given command line parameters.
     *
     * @param[in] args - The command line parameters.
     * @returns True on success.
     */
    bool exec(program_arguments& args) override;
};

#endif /* __HAL_PLUGIN_HELLOWORLD__ */
