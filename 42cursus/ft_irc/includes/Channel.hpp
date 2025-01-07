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

		// // Construtor para facilitar a inicialização
		// Endereco(const std::string& r, int n, const std::string& c)
		//     : rua(r), numero(n), cidade(c) {}
	};

	public:
		Channel(void);
		~Channel(void);

		std::string name;
		std::vector<ClientChanell> clients;
};

#endif