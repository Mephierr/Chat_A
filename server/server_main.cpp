#include <iostream>
#include <sio_server.h>

using namespace std;

int main() {
    sio::server server;

    server.set_reuse_addr(true);
    server.set_http_port(3000);
    
    server.on("message", [](sio::event& ev) {
        cout << "Received message: " << ev.get_message()->get_string() << endl;
    });

    server.start();
    cout << "Server is running on port 3000..." << endl;

    while (true) {
        server.poll();
    }

    return 0;
}