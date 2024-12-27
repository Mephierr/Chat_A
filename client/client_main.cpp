#include <iostream>
#include <sio_client.h>

using namespace std;

int main() {
    sio::client client;

    client.connect("http://localhost:3000");

    client.on("connect", [&client]() {
        cout << "Connected to server!" << endl;
        client.emit("message", "Hello from client!");
    });

    client.on("disconnect", []() {
        cout << "Disconnected from server!" << endl;
    });

    // Keep the client running
    while (true) {
        client.sync();
    }

    return 0;
}