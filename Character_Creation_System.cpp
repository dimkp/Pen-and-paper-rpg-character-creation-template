#include <iostream>
#include <string>
using namespace std;

int character_selection();

class fighting_models {
    public:
        string name {};
        int base_attack_strength {};
        int strong_attack_strength {};
        int backstub_attack {};
        int inteligence {};
        int simple_magic_attack_damage {}; 
        int special_magic_attack_damage {};    
};

int main(){
    int i = character_selection();
    string characters_name {};
    cout << "Give a name fo your character without using spaces : ";
    cin >> characters_name;    

    fighting_models def;
    if(i == 0){
        def.name = characters_name;
        def.base_attack_strength = 1;
        def.strong_attack_strength = 1;
        def.backstub_attack = 1;
        def.inteligence = 1;
        def.simple_magic_attack_damage = 1;
        def.special_magic_attack_damage = 1;
    }

    fighting_models warrior;
    if(i == 1){
        warrior.name = characters_name;
        warrior.base_attack_strength = 10;
        warrior.strong_attack_strength = 20;
        warrior.backstub_attack = 30;
        warrior.inteligence = 0;
        warrior.simple_magic_attack_damage = 0;
        warrior.special_magic_attack_damage = 0;
    }

    fighting_models wizard;
    if(i == 2){    
        wizard.name = characters_name;
        wizard.base_attack_strength = 3;
        wizard.strong_attack_strength = 7;
        wizard.backstub_attack = 10;
        wizard.inteligence = 35;
        wizard.simple_magic_attack_damage = 30;
        wizard.special_magic_attack_damage = 40;
    }

    fighting_models assassin;
    if(i == 3){
        assassin.name = characters_name;
        assassin.base_attack_strength = 12;
        assassin.strong_attack_strength = 23;
        assassin.backstub_attack = 35;
        assassin.inteligence = 10;
        assassin.simple_magic_attack_damage = 5;
        assassin.special_magic_attack_damage = 15;
    }
    
    fighting_models players_choise;
    if(i == 4){
        int stat_sum = 0, max_stat_sum = 100;
        players_choise.name = characters_name;
        int base_attack = 0, strong_attack = 0, backstub = 0, inteligence = 0;
        while(stat_sum <= max_stat_sum && max_stat_sum - stat_sum > 0){
            cout << "\nYou have " << max_stat_sum - stat_sum << " available stat points for " << players_choise.name << "'s creation" << endl;
            cout << "Base attack : "; cin >> base_attack;
            stat_sum += base_attack;
            if(max_stat_sum - stat_sum == 0) break;
            cout << "You have " << max_stat_sum - stat_sum << "more points to use" << endl;
            cout << "Strong attack : "; cin >> strong_attack;
            stat_sum += strong_attack;
            if(max_stat_sum - stat_sum == 0) break;
            cout << "You have " << max_stat_sum - stat_sum << "more points to use" << endl;
            cout << "Backstub attack :"; cin >> backstub;
            stat_sum += backstub;
            if(max_stat_sum - stat_sum == 0) break;
            cout << "You have " << max_stat_sum - stat_sum << "more points to use" << endl;
            cout << "Inteligence : "; cin >> inteligence;
            stat_sum += inteligence;
            if(max_stat_sum - stat_sum == 0) break;
            cout << "You have " << max_stat_sum - stat_sum << "more points to use" << endl;
        }
        players_choise.base_attack_strength = base_attack;
        players_choise.strong_attack_strength = strong_attack;
        players_choise.backstub_attack = backstub;
        players_choise.inteligence = inteligence;
        if(players_choise.inteligence > 5){
            players_choise.simple_magic_attack_damage = players_choise.inteligence - 5;
            players_choise.special_magic_attack_damage =  players_choise.inteligence + 10;
        }else{
            players_choise.simple_magic_attack_damage = 0;
            players_choise.special_magic_attack_damage = players_choise.inteligence;
        }
    }
    cout << "Hello there " << characters_name;

return 0;
}

int character_selection(){
    int choise, i = 0;
    cout << "WELCOME TO THE GAME!!!" << endl;
    cout << "Here you can choose your character class or create your own" << endl;
    cout << "0. for the default character" << endl;
    cout << "1. for the default warrior class" << endl;
    cout << "2. for the default wizard class" << endl;
    cout << "3. for the default assassin class" << endl;
    cout << "4. to create your own character" << endl;
    do{
        if(i == 0){
            cout << "Type your choise here : "; cin >> choise;
        }else{
            cout << "Invalid choise" << endl;
            cout << "Type your choise here : "; cin >> choise;
        }
        i++;
    }while(choise != 0 && choise != 1 && choise != 2 && choise != 3 && choise != 4);

return choise;
}