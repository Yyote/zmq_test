#include "zmq.hpp"
#include <string>
#include <iostream>

int main ()
{
    zmq::context_t context{1};
    zmq::socket_t publisher{context, zmq::socket_type::pub};
    publisher.bind("tcp://192.168.88.145:8080");

    std::string message_str;
    message_str = "Hello World";

    zmq_sleep(2);

    while(true)
    {
        zmq::message_t message(message_str.size());
        std::memcpy (message.data (), message_str.data(), message_str.size());
        std::cout << "DATA SIZE " << message_str.size() << std::endl;


        publisher.send(zmq::str_buffer("Topic"), zmq::send_flags::sndmore);
        publisher.send(message);
        zmq_sleep(1);
    }

    return 0;
}