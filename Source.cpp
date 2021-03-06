#include<iostream>
#include "Creature.h"
#include "Player.h"
#include "Monsterr.h"
#include <ctime>
using namespace std;
void attackMonster(Player& p, Monster& m);
void attackPlayer(Player& p, Monster& m);
int main() {
	//настраиваем генератор случайных чисел
	srand(time(0));
	rand();
	//создаем игрока, передаем только имя, в остальные поля 
	//устанавливаются значения по умолчанию из конструктора
	Player p("ibragim");
	//основной игровой цикл
	//пока игрок не умер и не выиграл
	while (!p.isDead() && !p.hasWon()) {
		//созадётся монст
		Monster m = Monster::gerRandomMonster();
		cout << "You have encountered a " << m.getName() << endl;
		char input;
		// предлагаем выбрать Побег или Бой
		cout << "(R)un or (F)ight : ";
		cin >> input;
		// игрок выбрал побег
		if (input == 'R' || input == 'r') {
			//задаем вероятность 50% что сбежать удалось
			if (rand() % 100 < 50) {
				cout << "You successfully fled\n";
				continue;
			}
			//сбежать не удалось
			else {
//монстер бьёт игрока
			}
		}
		//игрок выбрал сражение
		if (input == 'F' || input == 'f') {
			//игрок бьёт монстра
			attackMonster(p, m);
			//монстр бьёт игрока
			attackPlayer(p, m);
		}
	}
		//проверка на смерть и выигрыш
	if (p.isDead()) {
		cout << "You died!\n";
	}
	else if (p.hasWon()) {
		cout << "You win!!!\n";
	}
	return 0;
}
void attackMonster(Player& p, Monster& m) {
	cout << "You hit " << m.getName() << " for " << p.getDamage() << " damage\n";
	m.reduceHealth(p.getDamage());
	if (m.isDead()) {
		cout << "You kill " << m.getName() << endl;
		p.levelUp();
		cout << "Your level is " << p.getLevel() << endl;
		p.addGold(m.getGold());
		cout << "You found " << m.getGold() << " gold\n";
	}
}
void attackPlayer(Player& p, Monster& m) {
	if (m.isDead()) return;
	cout << m.getName()  << "hit you for" << m.getDamage() << " damage\n";
	p.reduceHealth(m.getDamage());
}