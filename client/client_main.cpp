#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Client {
public:
    Client(const std::string& host, const std::string& port)
        : io_service(), socket(io_service) {
        connect(host, port);
    }

    void sendMessage(const std::string& message) {
        boost::asio::write(socket, boost::asio::buffer(message));
    }

    std::string receiveMessage() {
        char reply[1024];
        size_t reply_length = boost::asio::read(socket, boost::asio::buffer(reply, message_length));
        return std::string(reply, reply_length);
    }

private:
    void connect(const std::string& host, const std::string& port) {
        tcp::resolver resolver(io_service);
        tcp::resolver::results_type endpoints = resolver.resolve(host, port);
        boost::asio::connect(socket, endpoints);
    }

    boost::asio::io_service io_service;
    tcp::socket socket;
    const size_t message_length = 1024; // Максимальная длина сообщения
};

int main() {
    try {
        Client client("127.0.0.1", "3000");

        // Отправка сообщения на сервер
        client.sendMessage("Hello from C++ client!\n");

        // Получение ответа от сервера
        std::string reply = client.receiveMessage();
        std::cout << "Reply from server: " << reply << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}