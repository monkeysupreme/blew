#include "blew/blew.h"

namespace blew {

    void Run() {
        auto* app = new Application("Sample App");
        app->Start();
        delete app;
    }

}