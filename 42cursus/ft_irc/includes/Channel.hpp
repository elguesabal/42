#ifndef	CHANNEL_HPP
#define CHANNEL_HPP

class Client;

// i t k o l

class Channel {

	struct ClientChanell {
		Client *client;
		bool o;

		ClientChanell(Client *client);
	};

	public:
		Channel(Client *client);
		~Channel(void);

		// ./class/Channel/Channel.cpp
		void newMember(Client *client);

		// ./class/Channel/utils/utils.cpp
		unsigned int size(void) const;

		// INFORMACOES DOS CANAL
		bool i;
		bool t;
		bool k;
		bool l;
		std::string topic;
		std::string password;
		unsigned int limit;

		// INFORMACOES DOS CLIENTES
		std::vector<ClientChanell *> clients;
		std::map<std::string, ClientChanell *> nickClient;
};

#endif