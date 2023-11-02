//
//  Flags.h
//  ws06
//
//  Created by Long Hoàng on 2023-10-29.
//


#ifndef SDDS_FLAGS_H
#define SDDS_FLAGS_H

namespace sdds
{
    // Options for displaying the files and directories
    enum class FormatFlags {
        LONG,     // to display in long format
    };

    // Determine the type of filesystem resource
    enum class NodeType {
        DIR,   // Directory
        FILE   // Regular File
    };

    // Options for performing a filesystem operation
    enum class OpFlags {
        RECURSIVE,  // run an operation recursively
    };
}

#endif

