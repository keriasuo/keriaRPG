#include <iostream>
#include <random>
#include <ctime>
#include <sqlite3.h>
#include <string>
#include <windows.h>


#pragma comment(lib, "Winmm.lib")

using namespace std;

int itemss[];

class keriasu {
public:
	keriasu() {}
	int hp, mp, damage, exp, lvl, gold, power, agility, intellect, magpower, maxhp, maxmp, rewardgold, skillpoint;
	int RewardExp, RewardGold;
	double resist;
	string name;
	string items[100], shopitems[100];
	int itemscount[100],cost[100];
public:
	void win() {
		cout << "win!" << endl;
	}
	void lose() {
		cout << "you lose!" << endl;
	}
	void printStatsgg()
	{
		cout << "---------------------------------------------------------\n" << name << endl;
		cout << "Уровень: " << lvl << endl;
		cout << "Опыт: " << exp << endl;
		cout << "Здоровье: " << hp << "HP" << endl;
		cout << "Урон: " << damage << endl;
		cout << "Защита:  " << resist << endl;
		cout << "Голда: " << gold << endl;
		cout << "Сила: " << power << endl;
		cout << "Ловкость:  " << agility << endl;
		cout << "Интеллект:  " << intellect << endl;
		cout << "Магическая сила:  " << magpower << endl;
	}
	void printStatsMob() {
		cout << "---------------------------------------------------------\nВам попался: " << name << endl;
		cout << "Уровень: " << lvl << endl;
		cout << "Здоровье: " << hp << "HP" << endl;
	}
};

class MainHero : public keriasu {
public:
	int hppotion, mppotion;
	MainHero() {}
	void giveup(MainHero& gg)
	{
		gg.hp = 0;
		cout << "You lose!\n" << "HP: " << gg.hp << endl;
	}
	void createHero()
	{	
		name = "keria";
		cost[0] = 10; cost[1] = 10; cost[2] = 25; cost[3] = 25;
		shopitems[0] = "HP potion"; shopitems[1] = "MP potion"; shopitems[2] = "Big HP Potion"; shopitems[3] = "Big MP Potion";
		items[0] = "HP potion"; items[1] = "MP potion"; items[2] = "Big HP Potion"; items[3] = "Big MP Potion";
		itemscount[0] = 5; itemscount[1] = 5; itemscount[2] = 1; itemscount[3] = 1;
		hppotion = 10; mppotion = 10;
		hp = 10;
		maxhp = 10;
		mp = 10;
		maxmp = 10;
		lvl = 1;
		exp = 0;
		gold = 0;
		power = 1;
		damage = 5;
		magpower = 1;
		agility = 1;
		intellect = 1;
		resist = 1;
		skillpoint = 0;
	}
	int showItems(MainHero& gg) {
		string u;
		int j = 1;
		cout << "---------------------------------------------------------\n";
		for (int i = 0; i < size(gg.items); i++)
		{
			if (gg.items[i] != "")
			{
				cout << j << ": " << gg.items[i] << ": " << itemscount[i] << endl;
			}
			j++;
		}
		cout << "Enter any key: Quit\n";
		cout << "Что вы хотите использовать?" << "\nEnter the number: ";
		cin >> u;
		if (u == "1")
		{
			if (itemscount[0] > 0)
			{
				cout << "Вы использовали " << items[0] << endl;
				gg.hp = gg.hp + 10;
				if (gg.hp > gg.maxhp) { gg.hp = gg.maxhp; }
				cout << "Теперь ваши HP: " << gg.hp << endl;
				gg.itemscount[0] = gg.itemscount[0] - 1;
			}
			else { cout << "У вас нет " << items[0] << endl; }
		}
		if (u == "2")
		{
			if (itemscount[1] > 0)
			{
				cout << "Вы использовали " << items[1] << endl;
				gg.hp = gg.hp + gg.mppotion;
				if (gg.mp > gg.maxmp) { gg.mp = gg.maxmp; }
				cout << "Теперь ваши MP: " << gg.mp << endl;
				gg.itemscount[1] = gg.itemscount[1] - 1;
			}
			else { cout << "У вас нет " << items[1] << endl; }
		}
		if (u == "3")
		{
			return 0;
		}
	}
	int showShop(MainHero& gg)
	{
		string p;
		int j=1;
		cout << "---------------------------------------------------------\nWhat you want to buy?\n";
		for (int i = 0; i < size(gg.shopitems); i++)
		{
			if (gg.shopitems[i] != "")
			{
				cout << j << ": " << gg.shopitems[i] << ": " << cost[i] << endl;
			}
			j++;
		}
		cout << "Enter any key = Quit\n" << "What you want to buy?\nEnter the number\n";
		cin >> p;
		if (p == "1")
		{
			if (gg.gold >= cost[0])
			{
				gg.itemscount[0] += 1;
				cout << "Вы купили " << items[0] << endl;
			}
			else
				cout << "Вам не хватает денег! У вас " << gg.gold << "g" << endl;
		}
		if (p == "2")
		{
			if (gg.gold >= cost[1])
			{
				gg.itemscount[1] += 1;
				cout << "Вы купили " << items[1] << endl;
			}
			else
				cout << "Вам не хватает денег! У вас " << gg.gold << "g" << endl;
		}
		if (p == "3")
		{
			if (gg.gold >= cost[2])
			{
				gg.itemscount[2] += 1;
				cout << "Вы купили " << items[2] << endl;
			}
			else
				cout << "Вам не хватает денег! У вас " << gg.gold << "g" << endl;
		}
		if (p == "4")
		{
			if (gg.gold >= cost[3])
			{
				gg.itemscount[3] += 1;
				cout << "Вы купили " << items[3] << endl;
			}
			else
				cout << "Вам не хватает денег! У вас " << gg.gold << "g" << endl;
		}
		if (p == "5")
		{
			return 0;
		}
	}
};

class Mobs : public MainHero {
public:
	Mobs() {};
	~Mobs() {}
	void createSlime() {
		name = "Slime";
		hp = rand() % 5 + 5;
		mp = 10;
		lvl = 1;
		RewardExp = 1 + rand() % 3;
		RewardGold = 1 + rand() % 5;
		damage = 3;
		magpower = 1;
		resist = 0;
	}
	void createSkelet() {
		name = "Skelet";
		hp = rand() % 5 + 10;
		mp = 10;
		lvl = 2;
		RewardExp = 1 + rand() % 3;
		RewardGold = 1 + rand() % 8;
		damage = 4;
		magpower = 1;
		resist = 0;
	}
	void createGoblin() {
		name = "Goblin";
		hp = rand() % 5 + 15;
		mp = 10;
		lvl = 3;
		RewardExp = 1 + rand() % 3;
		RewardGold = 5 + rand() % 10;
		damage = 6;
		magpower = 5;
		resist = 0;
	}
	void createMegaSlime() {
		name = "Mega Slime (Boss)";
		hp = 40 + rand() % 15;
		mp = 40;
		lvl = 5;
		RewardExp = 5 + rand() % 10;
		RewardGold = 15 + rand() % 10;
		damage = 10;
		magpower = 5;
		resist = 0;
	}
	void createOgreMaster() {
		name = "Ogre Master (Boss)";
		hp = 40 + rand() % 15;
		mp = 40;
		lvl = 5;
		RewardExp = 5 + rand() % 10;
		RewardGold = 15 + rand() % 10;
		damage = 10;
		magpower = 5;
		resist = 0;
	}
};

	void Doubleswipe()
	{

	}

	int usemagicalskills(MainHero& gg)
	{
		string g;
		cout << "\n---------------------------------------------------------\n1. Magical strike";
		cin >> g;
		if (g == "1")
		{

		}
		if (g == "2")
		{

		}
		if (g == "3")
		{

		}
		if (g == "4")
		{

		}
		if (g == "5")
		{
			return 0;
		}
	}

	int usephysicalskills(MainHero& gg)
	{
		string g;
		cout << "\n---------------------------------------------------------\n1. Double swipe\n2. Storm lunge\n3. Falcon swing\n4. Meditation\n5. Quit\nEnter the number: ";
		cin >> g;
		if (g == "1")
		{

		}
		if (g == "2")
		{

		}
		if (g == "3")
		{

		}
		if (g == "4")
		{

		}
		if (g == "5")
		{
			return 0;
		}
	}

	int useskills(MainHero& gg)
	{
		string p;
		cout << "\n---------------------------------------------------------\n1. Physical skills\n2. Magical skills\n3. Quit\nEnter the number: ";
		cin >> p;
		if (p == "1")
		{
			usephysicalskills(gg);
		}
		if (p == "2")
		{
			usemagicalskills(gg);
		}
		if (p == "3")
		{
			return 0;
		}
	}

class Equipments {
public:
	int eqplushp, eqplusdamage, eqplusdef, needpower, needagility, needintellect, eqplusmagpower;
	string eqname;
	void createSlimeSword()
	{
		eqname = "Slime Sword";
		eqplusdamage = 3;
		needpower = 3;
		needagility = 1;
	}
};

int removeEquipments(MainHero& gg)
{
	return 0;
}
int requipEquipments(MainHero& gg)
{
	return 0;
}

int AdventureFunc(Mobs* mob,MainHero& gg)
{	
	string v;
	cout << "---------------------------------------------------------\n1. Forest (1+ lvl)\n2. Cave (3+ lvl)\n3. Desert (5+ lvl)\n4. Quit\nEnter the number: ";
	cin >> v;
	if (v == "1")
	{
		int z = 1 + rand() % 100;
			if (z >= 0 && z <= 40)
			{
				mob->createSlime();
			}
			if (z >= 41 && z <= 80)
			{
				mob->createSkelet();
			}
			if (z > 80 && z <= 90)
			{
				mob->createGoblin();
			}
			if (z > 90 && z <= 95)
			{
				mob->createMegaSlime();
			}
			if (z > 95)
			{
				mob->createOgreMaster();
			}
	}
	if (v == "2")
	{
		if (gg.lvl > 2)
		{

		}
		else { cout << "---------------------------------------------------------\nУ вас " << gg.lvl << "lvl" << endl; return 5; }
	}
	if (v == "3")
	{
		if (gg.lvl > 4)
		{

		}
		else { cout << "---------------------------------------------------------\nУ вас " << gg.lvl << "lvl" << endl; }
	}
	if (v == "4")
	{
		return 0;
	}
}

int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;
	return 0;
}

int rolling() {
	int roll;
	cout << "Если вам выпадет число до 90, вы сбежите: ";
	roll = 1 + rand() % 100;
	return roll;
}

int ggattack(Mobs* mob, MainHero& gg)
{
	int k = 1;
	cout << "---------------------------------------------------------\nВаши хп: " << gg.hp << "HP" << endl;
	mob->hp -= gg.damage;
	cout << "Вы нанесли: " << gg.damage << " урона" << endl;
	cout << "У " << mob->name << " осталось " << mob->hp << "HP" << endl;
	if (mob->hp > 0) {
		cout << "---------------------------------------------------------\n" << mob->name << " наносит вам " << mob->damage << " урона" << endl;
		gg.hp = gg.hp - mob->damage;
		cout << "Ваши хп: " << gg.hp << "HP" << endl;
		if (gg.hp <= 0)
		{
			cout << "---------------------------------------------------------\nВы проиграли!\nВас убил " << mob->name << endl;
			gg.hp = 0;
			return 0;
		}
	}
}

void upgglvl(MainHero& gg)
{
	if (gg.lvl == 2) { gg.damage += 3; gg.maxhp += 5; }
	if (gg.lvl == 3) { gg.damage += 4; gg.maxhp += 5; }
	if (gg.lvl == 4) { gg.damage += 5; gg.maxhp += 5; }
	if (gg.lvl == 5) { gg.damage += 6; gg.maxhp += 5; }
	if (gg.lvl == 6) { gg.damage += 7; gg.maxhp += 5; }
	if (gg.lvl == 7) { gg.damage += 8; gg.maxhp += 5; }
	if (gg.lvl == 8) { gg.damage += 9; gg.maxhp += 5; }
	if (gg.lvl == 9) { gg.damage += 10; gg.maxhp += 5; }
	if (gg.lvl == 10) { gg.damage += 11; gg.maxhp += 5; }
}
void levelsystem1(MainHero& gg)
{
	if (gg.exp >= 10 && gg.exp < 20) { upgglvl(gg); gg.lvl = 2; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }

}
void levelsystem2(MainHero& gg)
{
	if (gg.exp >= 20 && gg.exp < 40) { upgglvl(gg); gg.lvl = 3; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem3(MainHero& gg)
{
	if (gg.exp >= 40 && gg.exp < 70) { upgglvl(gg);  gg.lvl = 4; gg.skillpoint += 3; cout << "Вы повысили уровень!\nВаши характеристики повышены!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem4(MainHero& gg)
{
	if (gg.exp >= 70 && gg.exp < 100) { upgglvl(gg);  gg.lvl = 5; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem5(MainHero& gg)
{
	if (gg.exp >= 100 && gg.exp < 120) { upgglvl(gg);  gg.lvl = 6; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem6(MainHero& gg)
{
	if (gg.exp >= 120 && gg.exp < 150) { upgglvl(gg);  gg.lvl = 7; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem7(MainHero& gg)
{
	if (gg.exp >= 150 && gg.exp < 170) { upgglvl(gg);  gg.lvl = 8; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem8(MainHero& gg)
{
	if (gg.exp >= 170 && gg.exp < 200) { upgglvl(gg);  gg.lvl = 9; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem9(MainHero& gg)
{
	if (gg.exp >= 200 && gg.exp < 250) { upgglvl(gg);  gg.lvl = 10; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}
void levelsystem10(MainHero& gg)
{
	if (gg.exp >= 250 && gg.exp < 300) { upgglvl(gg);  gg.lvl = 11; gg.skillpoint += 3; cout << "Вы повысили уровень!\n" << "Теперь у вас " << gg.lvl << " lvl и " << gg.skillpoint << " skillpoints" << endl; }
}


void useItems(MainHero& gg)
{
	string h;
	bool k = 1;
	while (k == 1)
	{
		cout << "---------------------------------------------------------\nWhat you want to use?\n1. " << gg.items[0] << " " << gg.itemscount[0] << "\n2. " << gg.items[1] << " " << gg.itemscount[1] << "3. Quit\nEnter the number: ";
		cin >> h;
		if (h == "1")
		{
			gg.hp += gg.hppotion;
			cout << "Now your HP: " << gg.hp << endl;
		}
		if (h == "2")
		{
			gg.hp += gg.mppotion;
			cout << "Now your MP: " << gg.mp << endl;
		}
		if (h == "3")
		{
			break;
		}
	}
}

int slimeReward()
{
	int rewardslime;
	rewardslime = 1 + rand() % 5;
	return rewardslime;
}
int slimeRewardExp() 
{
	int rewardslimexp;
	rewardslimexp = 1 + rand() % 5;
	return rewardslimexp;
}

int FindNewMob(Mobs* mob, MainHero& gg)
{
	int k = 1;

	if (gg.hp > 0) {
		Mobs* mob = new Mobs;
		if (AdventureFunc(mob, gg) != 5)
		{
			mob->printStatsMob();
			while (k == 1)
			{

				string g;
				cout << "---------------------------------------------------------\nWhat you want?\n1. Attack\n2. Skill\n3. Run\n4. Give up\n5. Items\nEnter the number: ";
				cin >> g;
				if (g == "1")
				{
					if (ggattack(mob, gg) == 0) { k = 0; delete mob; break; }
				}
				if (mob->hp <= 0)
				{
					cout << "---------------------------------------------------------\nВы убили: " << mob->name << endl;
					if (mob->name == "Slime") { gg.exp += mob->RewardExp; gg.gold += mob->RewardGold;   cout << "Reward " << mob->RewardExp << "XP!\n" << mob->RewardGold << " gold\n"; }
					if (mob->name == "Skelet") { gg.exp += mob->RewardExp; gg.gold += mob->RewardGold;   cout << "Reward " << mob->RewardExp << "XP!\n" << mob->RewardGold << " gold\n"; }
					if (mob->name == "Ogre") { gg.exp += mob->RewardExp; gg.gold += mob->RewardGold;   cout << "Reward " << mob->RewardExp << "XP!\n" << mob->RewardGold << " gold\n"; }
					if (gg.lvl == 1) { levelsystem1(gg); }
					if (gg.lvl == 2) { levelsystem2(gg); }
					if (gg.lvl == 3) { levelsystem3(gg); }
					if (gg.lvl == 4) { levelsystem4(gg); }
					if (gg.lvl == 5) { levelsystem5(gg); }
					if (gg.lvl == 6) { levelsystem6(gg); }
					if (gg.lvl == 7) { levelsystem7(gg); }
					if (gg.lvl == 8) { levelsystem8(gg); }
					if (gg.lvl == 9) { levelsystem9(gg); }
					if (gg.lvl == 10) { levelsystem10(gg); }
					delete mob;
					k = 0;
					break;
				}
				if (g == "2")
				{
					useskills(gg);
				}
				if (g == "3")
				{
					if (rolling() < 90) {
						cout << "Вы сбежали!" << endl;
						delete mob;
						k = 0;
						break;
					}
					else
					{
						cout << "Сбежать не удалось!" << endl;
					}
				}
				if (g == "4")
				{
					gg.giveup(gg);
					k = 0;
					delete mob;
					break;
				}
				if (g == "5")
				{
					useItems(gg);
				}

			}
		}
		
		
		
	}
	else
	{
		cout << "---------------------------------------------------------\nВы не можете дальше продолжать, у вас: " << gg.hp << "HP" << endl;
		return 0;
	}

}

void save(MainHero& gg)
{
	sqlite3_stmt* st = nullptr;
	int hpp = 50;
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;
	sql = "UPDATE AllSavesGG set ID = ?,name = ?,hp = ?,hpmax = ?,mp = ?, mpmax = ?, itemscount1 = ?, itemscount2 = ?, lvl = ?, exp = ?, gold = ?, damage = ?, power = ?, magpower = ?, agility = ?, intellect = ?, resist = ? where ID=1; " \
		"SELECT * from COMPANY";
	int n = 1;
	if (sqlite3_open("AllHeroStatsSave.db", &db) == SQLITE_OK)
	{
		sqlite3_prepare(db, sql.c_str(), -1, &st, NULL);
		sqlite3_bind_int(st, 1, n);
		sqlite3_bind_text(st, 2, gg.name.c_str(), gg.name.length(), SQLITE_TRANSIENT);
		sqlite3_bind_int(st, 3, gg.hp);
		sqlite3_bind_int(st, 4, gg.maxhp);
		sqlite3_bind_int(st, 5, gg.mp);
		sqlite3_bind_int(st, 6, gg.maxmp);
		sqlite3_bind_int(st, 7, gg.itemscount[0]);
		sqlite3_bind_int(st, 8, gg.itemscount[1]);
		sqlite3_bind_int(st, 9, gg.lvl);
		sqlite3_bind_int(st, 10, gg.exp);
		sqlite3_bind_int(st, 11, gg.gold);
		sqlite3_bind_int(st, 12, gg.damage);
		sqlite3_bind_int(st, 13, gg.power);
		sqlite3_bind_int(st, 14, gg.magpower);
		sqlite3_bind_int(st, 15, gg.agility);
		sqlite3_bind_int(st, 16, gg.intellect);
		sqlite3_bind_int(st, 17, gg.resist);
		sqlite3_step(st);
	}

	sql = "SELECT * FROM 'AllSavesGG';";
	sqlite3_close(db);
	cout << "---------------------------------------------------------\nВаши данные успешно сохранены!\n" << "name: " << gg.name << "\nlvl: " << gg.lvl << "\n" << "exp: " << gg.exp << endl;
}

void load(MainHero& gg)
{
	sqlite3* db;
	sqlite3_stmt* stmt;

	sqlite3_open("AllHeroStatsSave.db", &db);
	sqlite3_prepare_v2(db, "SELECT * FROM 'AllSavesGG';", -1, &stmt, NULL);
	sqlite3_step(stmt);

	gg.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
	gg.hp = sqlite3_column_int(stmt, 2);
	gg.maxhp = sqlite3_column_int(stmt, 3);
	gg.mp = sqlite3_column_int(stmt, 4);
	gg.maxmp = sqlite3_column_int(stmt, 5);
	gg.itemscount[0] = sqlite3_column_int(stmt, 6);
	gg.itemscount[1] = sqlite3_column_int(stmt, 7);
	gg.lvl = sqlite3_column_int(stmt, 8);
	gg.exp = sqlite3_column_int(stmt, 9);
	gg.gold = sqlite3_column_int(stmt, 10);
	gg.damage = sqlite3_column_int(stmt, 11);
	gg.power = sqlite3_column_int(stmt, 12);
	gg.magpower = sqlite3_column_int(stmt, 13);
	gg.agility = sqlite3_column_int(stmt, 14);
	gg.intellect = sqlite3_column_int(stmt, 15);
	gg.resist = sqlite3_column_int(stmt, 16);

	sqlite3_close(db);

	cout << "---------------------------------------------------------\nВаши данные успешно загружены!\n" << "name: " << gg.name << "\nlvl: " << gg.lvl << "\n" << "exp: " << gg.exp << endl;
}

void renameGG(MainHero& gg)
{
	cout << "---------------------------------------------------------\nEnter new name your hero: ";
	cin >> gg.name;
	cout << "\nNow your name: " << gg.name << endl;
}

int settings(MainHero& gg)
{
	string u;
	cout << "---------------------------------------------------------\n1.Rename your hero\n2.Quit\nEnter the number: ";
	cin >> u;
	if (u == "1")
	{
		renameGG(gg);
	}
	if (u == "2")
	{
		return 0;
	}
}

void skillsTree(MainHero& gg)
{
	bool x = 1;
	int h;
	while (x == 1) {
		cout << "---------------------------------------------------------\nYou have " << gg.skillpoint << " skillpoints\nWhat you want upgrade?\n1.Power\n2.Agility\n3.Intellect\n4.Quit\nEnter the number: ";
		cin >> h;
		if (h == 1)
		{
			gg.power = gg.power + 1;
			cout << "\n---------------------------------------------------------\nТеперь у вас " << gg.power << " силы" << endl;
		}
		if (h == 2)
		{
			gg.agility = gg.agility + 1;
			cout << "\n---------------------------------------------------------\nТеперь у вас " << gg.agility << " ловкости" << endl;
		}
		if (h == 3)
		{
			gg.intellect = gg.intellect + 1;
			cout << "\n---------------------------------------------------------\nТеперь у вас " << gg.intellect << " интеллекта" << endl;
		}
		if (h == 4)
		{
			break;
		}
	}
}

void Equip(MainHero& gg)
{
	string y;
	bool x = 1;
	while (x == 1) {
		cout << "---------------------------------------------------------\n1.Weapon\n2.Armor\n3.Quit\nEnter number: ";
		cin >> y;
		if (y == "1")
		{

		}
		if (y == "2")
		{

		}
		if (y == "3")
		{
			break;
		}
	}
}

void upgradeSkills(MainHero& gg)
{
	string y;
	bool x = 1;
	while (x == 1) {
		cout << "---------------------------------------------------------\n1.Strong Attack\n2.Heal skill\n3.Quit\nEnter number: ";
		cin >> y;
		if (y == "1")
		{

		}
		if (y == "2")
		{

		}
		if (y == "3")
		{
			break;
		}
	}
}

int SkillsAndUpgrades(MainHero& gg)
{
	string y;
	bool x = 1;
	while (x == 1) {
		cout << "---------------------------------------------------------\n1. Skills Tree\n2. Upgrade skills\n3. Skills\n4. Quit\nEnter number: ";
		cin >> y;
		if (y == "1")
		{
			skillsTree(gg);
		}
		if (y == "2")
		{
			upgradeSkills(gg);
		}
		if (y == "3")
		{
			useskills(gg);
		}
		if (y == "4")
		{
			return 0;
		}
	}
}

int saveLoad(MainHero& gg)
{
	string z;
	cout << "---------------------------------------------------------\n1. Save\n2. Load\n3. Quit\nEnter the number: ";
	cin >> z;
	if (z == "1")
	{
		save(gg);
	}
	if (z == "2")
	{
		load(gg);
	}
	if (z == "3")
	{
		return 0;
	}
	else { cin.clear();  return 0; }
}

int quests(MainHero& gg)
{
	return 0;
}

void glmenu(Mobs* mob, MainHero& gg)
{
	string y;
	bool x = 1;
	while (x == 1) {
		cout << "---------------------------------------------------------\n1. Adventure\n2. My stats\n3. Equipment\n4. Skills/Upgrades\n5. Items\n6. Shop\n7. Quests\n8. Save/Load\n9. Settings\n10. Quit\nEnter number: ";
		cin >> y;
			if (y == "1")
			{
				FindNewMob(mob, gg);
			}
			if (y == "2")
			{
				gg.printStatsgg();
			}
			if (y == "3")
			{
				Equip(gg);
			}
			if (y == "4")
			{
				SkillsAndUpgrades(gg);
			}
			if (y == "5")
			{
				gg.showItems(gg);
			}
			if (y == "6")
			{
				gg.showShop(gg);
			}
			if (y == "7")
			{
				quests(gg);
			}
			if (y == "8")
			{
				saveLoad(gg);
			}
			if (y == "9")
			{
				settings(gg);
			}
			if (y == "10")
			{
				break;
			}
			//else { cin.clear(); cin.ignore(); }
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	string a1 = "heroinwater.mp3";
	//mciSendString(L"open \"heroinwater.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	//mciSendString(L"play mp3", NULL, 0, NULL);
	Mobs* mob = new Mobs;
	MainHero gg;
	gg.createHero();
	glmenu(mob, gg);
	system("pause");
	return 0;
}