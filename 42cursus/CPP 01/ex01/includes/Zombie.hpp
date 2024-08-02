#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void setName(std::string name);

	private:
		std::string _name;

};

#endif