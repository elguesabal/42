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
		Channel(std::string &name, Client *client);
		~Channel(void);

		// ./class/Channel/Channel.cpp
		void newMember(Client *client);

		// ./class/Channel/utils/utils.cpp
		unsigned int size(void) const;

		std::string name; // TIRAR ISSO PQ ACHO Q NAO VAI SER UTIL
		std::vector<ClientChanell *> clients;
		std::map<std::string, ClientChanell *> nickClient;

		bool i;
		bool t;
		bool k;
		bool l;

		std::vector<std::string> operators;
		std::string topic;
		std::string password;
		unsigned int limit;


		// CRIAR UMA FUNCAO Q CALCULA O TAMANHO DO CANAL OU CRIAR UMA VARIAVEL Q SALVA O TAMANHO DO CANAL???
};

#endif