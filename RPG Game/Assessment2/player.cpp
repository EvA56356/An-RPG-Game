//=======================
//		player.cpp
//=======================


#include "player.h"


// character's HP and MP resume
void player::reFill()
{
	HP = HPmax;		// HP and MP fully recovered
	MP = MPmax;
}

// report whether character is dead
bool player::death()
{
	return playerdeath;
}

// check whether character is dead
void player::isDead()
{
	if (HP <= 0)		// HP less than 0, character is dead
	{
		cout << name << " is Dead." << endl;
		system("pause");
		playerdeath = 1;	// give the label of death value 1
	}
}

// consume heal, irrelevant to job
bool player::useHeal()
{
	if (bag.nOfHeal() > 0)
	{
		HP = HP + 100;
		if (HP > HPmax)		// HP cannot be larger than maximum value
			HP = HPmax;		// so assign it to HPmax, if necessary
		cout << name << " used Heal, HP increased by 100." << endl;
		bag.useHeal();		// use heal
		system("pause");
		return 1;	// usage of heal succeed
	}
	else				// If no more heal in bag, cannot use
	{
		cout << "Sorry, you don't have heal to use." << endl;
		system("pause");
		return 0;	// usage of heal failed
	}
}

// consume magic water, irrelevant to job
bool player::useMW()
{
	if (bag.nOfMW() > 0)
	{
		MP = MP + 100;
		if (MP > MPmax)
			MP = MPmax;
		cout << name << " used Magic Water, MP increased by 100." << endl;
		bag.useMW();
		system("pause");
		return 1;	// usage of magic water succeed
	}
	else
	{
		cout << "Sorry, you don't have magic water to use." << endl;
		system("pause");
		return 0;	// usage of magic water failed
	}
}

// possess opponent's items after victory
void player::transfer(player& p)
{
	cout << name << " got" << p.bag.nOfHeal() << " Heal, and " << p.bag.nOfMW() << " Magic Water." << endl;
	system("pause");
	//	3_???????????
	bag.set(bag.nOfHeal() + p.bag.nOfHeal(), bag.nOfMW() + p.bag.nOfMW());
	// set the character's bag, get opponent's items
}

// display character's job
void player::showRole()
{
	switch (role)
	{
	case sw:
		cout << "Swordsman";
		break;
	case ar:
		cout << "Archer";
		break;
	case mg:
		cout << "Mage";
		break;
	default:
		break;
	}
}


// display character's job
void showinfo(player& p1, player& p2)
{
	system("cls");
	cout << "##############################################################" << endl;
	cout << "# Player" << setw(13) << p1.name << setw(10) << "#"
		<< " Opponent" << setw(13) << p2.name << setw(9) << "#" << endl;
	cout << "#-----------------------------#------------------------------#" << endl;
	cout << "# LV. " << p1.LV << setw(24) << "#" << " LV. " << p2.LV << setw(25) << "#" << endl;
	cout << "#-----------------------------#------------------------------#" << endl;
	cout << "# Job: " << setw(12);
	p1.showRole();
	cout << setw(12) << "#";
	cout << " Job: " << setw(12);
	p2.showRole();
	cout << setw(13) << "#" << endl;
	cout << "#-----------------------------#------------------------------#" << endl;
	cout << "# HP " << setw(3) << (p1.HP <= 999 ? p1.HP : 999) << '/' << setw(3) << (p1.HPmax <= 999 ? p1.HPmax : 999)
		<< " | MP " << setw(3) << (p1.MP <= 999 ? p1.MP : 999) << '/' << setw(3) << (p1.MPmax <= 999 ? p1.MPmax : 999)
		<< "     # HP " << setw(3) << (p2.HP <= 999 ? p2.HP : 999) << '/' << setw(3) << (p2.HPmax <= 999 ? p2.HPmax : 999)
		<< " | MP " << setw(3) << (p2.MP <= 999 ? p2.MP : 999) << '/' << setw(3) << (p2.MPmax <= 999 ? p2.MPmax : 999) << "      #" << endl;
	cout << "# AP " << setw(4) << (p1.AP <= 999 ? p1.AP : 999) << setw(5) << '|'
		<< " DP " << setw(6) << (p1.DP <= 999 ? p1.DP : 999)
		<< setw(7) << "#"
		<< " AP " << setw(4) << (p2.AP <= 999 ? p2.AP : 999) << setw(5) << '|'
		<< " DP " << setw(6) << (p2.DP <= 999 ? p2.DP : 999)
		<< setw(8) << "#" << endl;
	cout << "# EXP" << setw(4) << p1.EXP << setw(5) << '|';
	cout << " speed " << setw(3) << (p1.speed <= 999 ? p1.speed : 999) << setw(7) << "#";
	cout << " EXP" << setw(4) << p2.EXP << setw(5) << '|';
	cout << " speed " << setw(3) << (p2.speed <= 999 ? p2.speed : 999) << setw(8) << "#" << endl;
	cout << "##############################################################" << endl;
	p1.bag.display();
	cout << "##############################################################" << endl;
}

