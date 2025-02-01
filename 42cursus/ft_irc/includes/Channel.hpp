#ifndef	CHANNEL_HPP
#define CHANNEL_HPP

class Client;

class Channel {
	public:
		struct ClientChanell {
			Client *client;
			bool o;

			ClientChanell(Client *client);
		};

		Channel(std::string &channel, Client *client);
		~Channel(void);

		// ./class/Channel/Channel.cpp
		void newMember(Client *client, std::string &channel);

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
		std::map<std::string, ClientChanell *> clients;
};

#endif