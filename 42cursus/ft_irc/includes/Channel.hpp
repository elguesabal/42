#ifndef	CHANNEL_HPP
#define CHANNEL_HPP

class Client;

class Channel {

	struct ClientChanell {
		Client *client;
		// bool i;
		// bool t; // ESSES 3 NAO DEVERIAM PERTENCER AO CANAL??
		// bool k;
		bool o;
		bool l;

		ClientChanell(Client *client);
	};

	public:
		Channel(void) {} // ISSO NAO PERMITE Q O std::map CRIE CANAIS VAZIOS E OCUPE MEMORIA??
		Channel(std::string &name);
		~Channel(void);

		std::string name;
		std::vector<ClientChanell> clients;



		bool i;
		bool t;
		bool k;
};

#endif