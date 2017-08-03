// ***********************************************************************
// Assembly         : 
// Author           : Tim
// Created          : 07-10-2017
//
// Last Modified By : Tim
// Last Modified On : 08-01-2017
// ***********************************************************************
// <copyright file="main.cpp" company="">
//     Copyright (c) 2017,  eNVy Systems, Inc. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include <QApplication>
#include "rcqhelper.h"
#include "../NvLibQ/nvlibq.h"


/// <summary>
/// Mains the specified argc.
/// </summary>
/// <param name="argc">The argc.</param>
/// <param name="argv">The argv.</param>
/// <returns>int.</returns>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RcQHelper w;
    w.show();

    return a.exec();
}
