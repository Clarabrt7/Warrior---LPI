#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// enum class para ações
 enum class action {
    attack, 
    defend,
    heal,
};


class warrior { 
    public:
        warrior(std::string name, int health, int attackPower) // Construtor
            : name(name), health(health), attackPower(attackPower) {} // Usado para criar um guerreiro com nome 

        void attack(warrior& target) { //Não const porque o alvo pode ser modificado
            std::cout << name << " attacks " << target.name << " for " << attackPower << " damage!" << std::endl; // Exibe a mensagem de ataque pelo guerreiro da vez
            target.health -= attackPower; // Reduz a saúde do alvo
        }

        void defend() {
            std::cout << name << " is defending!" << std::endl; 
        }

        void heal() { 
            std::cout << name << " heals for 10 health!" << std::endl; // Exibe a mensagem quando o guerreiro se cura
            health += 10; // Aumenta a saúde do guerreiro
            //Adicionar lógica para não ultrapassar a saúde máxima
        }

        // Mostra a vida do guerreiro e seu nome
        void displayStatus() const { // Const porque não altera o estado do objeto
             std::cout << name << "'s Health: " << health << std::endl;
        }
     
        private: // Dados do guerreiro 
            std::string name;   
            int health;
            int attackPower;

};

class coliseum{ 
    
    public: // Construtor
        void addWarrior(const warrior& w) { // Método para adicionar um guerreiro ao coliseu
            warriors.push_back(w); // Adiciona o guerreiro ao vetor
        }

        void startBattle() { // Método para iniciar a batalha
            for (size_t i = 0; i < warriors.size(); ++i) { // Itera sobre os guerreiros
                warriors[i].displayStatus(); // Exibe o status de cada guerreiro
            }
            // Implementar lógica de batalha aqui

        }

    private: // Atributos do coliseu
        std::vector<warrior> warriors; 

};

class dado{ 
    public: // Construtor
           int roll() {
            return rand() % 6 + 1; // Gera um número aleatório entre 1 e 6
        }

        private:
            int sides;
};

int main() {
    // Criação de guerreiros
    warrior warrior1("Warrior 1", 100, 20);
    warrior warrior2("Warrior 2", 100, 15);

    // Criação do coliseu
    coliseum coliseum;
    coliseum.addWarrior(warrior1);
    coliseum.addWarrior(warrior2);

    // Início da batalha
    coliseum.startBattle();

    return 0;
}   


