#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string getType(void);
		void setType(std::string type);

	private:
		std::string  type;

};

#endif