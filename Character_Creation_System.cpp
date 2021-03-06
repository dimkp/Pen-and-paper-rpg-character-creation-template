#include <iostream>
#include <string>
#include <cmath>
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
        int archery {}; 
        int range {};
    void models_stats(string pname, int pBas, int pSas, int pBack, int pInt, int pSmd, int pSpecialM, int pArch){
        name = pname;
        base_attack_strength = pBas;
        strong_attack_strength = pSas;
        backstub_attack = pBack;
        inteligence = pInt;
        simple_magic_attack_damage = pSmd; 
        special_magic_attack_damage = pSpecialM;
        archery = pArch; 
        range = round(30/100 * archery);
    }
};

int main(){
    int i = character_selection();
    string characters_name {};
    cout << "\nGive a name fo your character without using spaces : ";
    cin >> characters_name;    

    fighting_models def;
    if(i == 0)
        def.models_stats(characters_name, 1, 1, 1, 1, 1, 1, 1);

    fighting_models warrior;
    if(i == 1)
        warrior.models_stats(characters_name, 10, 20, 30, 0, 0, 0, 2);
        
    fighting_models wizard;
    if(i == 2) 
        wizard.models_stats(characters_name, 3, 7, 10, 35, 30, 40, 12);
        
    fighting_models assassin;
    if(i == 3)
        assassin.models_stats(characters_name, 12, 23, 35, 10, 5, 15, 8);
    
    fighting_models archer;
    if(i == 4)
        archer.models_stats(characters_name, 7, 9, 11, 15, 7, 16, 36); 

    fighting_models players_choise;
    if(i == 5){
        int stat_sum = 0, max_stat_sum = 100, add_another = 1;
        players_choise.name = characters_name;
        int base_attack = 0, strong_attack = 0, backstub = 0, inteligence = 0, archery = 0, simple_magic_attack_damage, special_magic_attack_damage;
        int range;
        while(stat_sum <= max_stat_sum && max_stat_sum - stat_sum > 0 && add_another == 1){
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
            cout << "Archery skill : "; cin >> archery;
            if(max_stat_sum - stat_sum == 0) break;
            cout << "You have " << max_stat_sum - stat_sum << "more points to use" << endl;
            do{
                cout << "1. for making changes to the attributes" << endl;
                cout << "2. for character finalisation" << endl;
                cout << "Do you want to make further changes to your attributes : "; cin >> add_another; 
            }while(add_another != 1 || add_another != 2);
        }
        if(players_choise.inteligence > 5){
            simple_magic_attack_damage = inteligence - 5;
            special_magic_attack_damage =  inteligence + 10;
        }else{
            simple_magic_attack_damage = 0;
            special_magic_attack_damage = inteligence;
        }
        if(archery > 0){
            range = round(30/100 * players_choise.archery);
        }else{
            range = 0;
        }
        players_choise.models_stats(characters_name, base_attack, strong_attack, backstub, inteligence, simple_magic_attack_damage, special_magic_attack_damage, archery);
    }
    cout << "\nHello there " << characters_name << ". Your character has been created." << endl;
    cout << "\n================Good luck on your jurney!!================" << endl << endl;

return 0;
}

int character_selection(){
    int choise, i = 0;
    cout << "\n================WELCOME TO THE GAME!!================\n" << endl;
    cout << "Class selection" << endl;
    cout << "0. for the default character" << endl;
    cout << "1. for the default warrior class" << endl;
    cout << "2. for the default wizard class" << endl;
    cout << "3. for the default assassin class" << endl;
    cout << "4. for the default archer class" << endl;
    cout << "5. to create your own character" << endl;
    do{
        if(i == 0){
            cout << "Type your choise here : "; cin >> choise;
        }else{
            cout << "Invalid choise" << endl;
            cout << "Type your choise here : "; cin >> choise;
        }
        i++;
    }while(choise != 0 && choise != 1 && choise != 2 && choise != 3 && choise != 4 && choise != 5);

return choise;
}
