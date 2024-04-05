#include <hv/WebSocketServer.h>

#include "Net.hpp"

#include <chrono>
#include <iostream>
#include <thread>

void handleInput(Net & net) {
	std::string input;
	std::cout << "enter messages: " << std::endl;
	while (true) {
		std::getline(std::cin, input);
		if (input == "")
			exit(0);
		auto sendInput = [&input](const WebSocketChannelPtr & channel) {
			channel->send(input);
		};
		net.map(sendInput);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

int main() {
	Net net;

	hv::WebSocketService ws;

	ws.onopen = [&net](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
		net.add(channel);
		channel->send("Pseudo ?");
	};
	ws.onmessage = [&net](const WebSocketChannelPtr& channel, const std::string& msg) {
		auto sendInput = [msg, channel, &net](const WebSocketChannelPtr& client){
			if(client!=channel){
				client->send("["+net.findName(channel)+"] "+msg);
			}
		};
		if(net.isPending(channel)){
			if(net.giveName(channel, msg)){
				std::cout << "Client " << msg << " connected !" << std::endl;
			}
		}else{
			net.map(sendInput);
		}
	};
	ws.onclose = [&net](const WebSocketChannelPtr& channel) {
		net.del(channel);
		std::cout << "client disconnected" << std::endl;
	};

	hv::WebSocketServer server;
	server.registerWebSocketService(&ws);
	server.setPort(9000);
	std::cout << "waiting for clients..." << std::endl;
	std::thread inputThread(handleInput, std::ref(net));
	server.run();

	return 0;
}

