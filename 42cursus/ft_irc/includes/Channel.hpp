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
		// Channel(void) {} // ISSO NAO PERMITE Q O std::map CRIE CANAIS VAZIOS E OCUPE MEMORIA??
		Channel(std::string &name, Client *creator);
		~Channel(void);

		void addClient(Client *client);

		// ./class/Channel/utils/utils.cpp
		unsigned int size(void) const;

		std::string name;
		std::vector<ClientChanell> clients;

		bool i;
		bool t;
		bool k;
		bool l;

		std::string topic;
		std::string password;
		unsigned int limit;


		// CRIAR UMA FUNCAO Q CALCULA O TAMANHO DO CANAL OU CRIAR UMA VARIAVEL Q SALVA O TAMANHO DO CANAL???
};

#endif