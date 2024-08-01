#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);

	private:
		std::string _name;

};

#endif