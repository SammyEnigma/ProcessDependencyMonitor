/*
 * MIT License

 * Copyright (c) 2020 Alexander Kirsanov

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#ifndef TOOLHELPMANAGER_HPP
#define TOOLHELPMANAGER_HPP

#include "OSWrapper.hpp"

class ToolHelpManager : public OSWrapper
{
public:
    ToolHelpManager();
    QList<OSProcessInfo> processes() override;

    bool getIsAdministrator() const;

protected:
    OSProcessInfo processByPIDImpl(int64_t pid) override;

private:
    OSProcessInfo _processByPID(int64_t pid);

    QList<OSProcessInfo> _processes;

    void addDep(QList<OSProcessDependence>& list, const OSProcessDependence& dep);

    SpecialDirs getSpecialDir(const QString& path);

    QRegExp _rxInSystem32;
    QRegExp _rxInSysWOW64;
    QRegExp _rxInWindows;

    bool _isAdministrator = false;
};

#endif // TOOLHELPMANAGER_HPP
