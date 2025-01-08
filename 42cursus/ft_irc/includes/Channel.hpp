#ifndef	CHANNEL_HPP
#define CHANNEL_HPP

class Client;

class Channel {

	struct ClientChanell {
		Client *client;
		bool i;
		bool t;
		bool k;
		bool o;
		bool l;

		ClientChanell(Client *client);
	};

	public:
		Channel(void);
		~Channel(void);

		std::string name;
		std::vector<ClientChanell> clients;
};

#endif