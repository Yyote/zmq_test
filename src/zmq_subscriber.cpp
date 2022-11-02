#include "zmq.hpp"
#include <zmq_addon.hpp>
#include <string>
#include <iostream>

int main ()
{
    int counter = 0;

    zmq::context_t context{1};
    zmq::socket_t subscriber{context, zmq::socket_type::sub};
    subscriber.set(zmq::sockopt::subscribe, "Topic");
    subscriber.connect("tcp://192.168.88.145:8080");

    while (true)
    {
        std::vector<zmq::message_t> recv_msgs;
        zmq::recv_result_t result = zmq::recv_multipart(subscriber, std::back_inserter(recv_msgs), zmq::recv_flags::none);
        std::cout << "DB FLAG "  << counter << " " << std::endl;

        std::cout << "subscriber connected ?  -  " << subscriber.connected() << std::endl;
        // for (int i = 0; i < recv_msgs.size(); i++)
        // {
        //     std::cout << "DATA: " << recv_msgs[i].to_string() << std::endl;
        // }
        // anpa_group.ParseFromArray(recv_msgs[1].data(), recv_msgs[1].size());
        // anpa_group.ParseFromString(recv_msgs[1].to_string());
        std::cout << recv_msgs[0].to_string() << std::endl;
        std::cout << recv_msgs[1].to_string() << std::endl;
        counter++;
    }

    return 0;
}