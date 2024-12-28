#include <iostream>
#include <sio_client.h>

using namespace std;
using namespace sio;

class Client {
public:
    Client() {
        client.connect("http://localhost:3000");

        client.set_open_listener([this]() {
            cout << "Connected to server!" << endl;
        });

        client.set_close_listener([this]() {
            cout << "Disconnected from server!" << endl;
        });

        client.socket()->on("message", [&](const message::ptr& msg) {
            if (msg->get_flag() == message::flag_string) {
                cout << "Message from server: " << msg->get_string() << endl;
            }
        });
    }

    void sendMessage(const std::string& message) {
        client.socket()->emit("message", message);
    }

    void waitForInput() {
        std::string input;
        while (true) {
            cout << "Enter message: ";
            getline(cin, input);
            sendMessage(input);
        }
    }

private:
    client client;
};

int main() {
    Client client;
    client.waitForInput();
    return 0;
}