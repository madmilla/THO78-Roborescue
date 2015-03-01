import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true

    files: [
        "*.cpp",
        "*.h",
    ]

    Depends {
        name: "Qt"
        submodules: ["quick","gui", "widgets"]
    }

    cpp.cxxPrecompiledHeader: "common.h"
}
