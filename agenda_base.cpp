// ========================================================== 
// Arquivo: agenda_base.cpp 
// Autor: Equipe de estagiarios - 03/02/2024 
// Alterado por: Joao - 15/05/2025 
// Alterado por: Marina - 09/01/2026 
// ========================================================== 

#include <iostream> 
#include <stdexcept>
#include <string> 
#include <vector> 

using namespace std; 

struct Agendamento { 
    string paciente; 
    string profissional; 
    string data; 
    
    int horario; 
    int duracao; 
    
    string status;
}; 


//Referentes à regra de negócio 3, onde o estabelecimento atende das 8h às 18h.
const int HORARIO_INICIAL = 8;
const int HORARIO_FINAL = 18;

/**
 * @brief Retorna um bool indicando se o hoario fornecido está livre.
 *
 * @param agenda Vetor de agendamentos que será varrido buscando se o horario está livre.
 * @param profissional Nome do profissional que atendedrá no horário.
 * @param data Ano-Mês-Dia do agendamento a ser verificado.
 * @param horario Horário(24H) do agendamento a ser verificado.
 * 
 * @return bool True se o horário e profissional está livre, caso contrário, false.
 *
 */
bool horario_esta_livre(vector<Agendamento> & agenda, string profissional, string data, int horario) {
    for (size_t i = 0; i < agenda.size(); i++) { 
        if (agenda[i].data == data && agenda[i].horario == horario && agenda[i].profissional == profissional) { 
            return false;
        } 
    } 

    return true;
}

/**
 * @brief Adicona um Agendamento à agenda fornecida. O registro é feito usando os dados da função.
 *
 * @param agenda Vetor de agendamentos no qual o Agendamento será adicionado.
 * @param paciente Nome do paciente que fez o agendamento.
 * @param profissional Nome do profissional que vai atender o paciente.
 * @param data Ano-Mês-Dia que o agendamento é marcado.
 * @param horario Horário(24H) que o agendamento será marcado.
 * @param duracao Duração do atendimento em horas.
 *
 */

void adicionar(vector<Agendamento> & agenda, string paciente, string profissional, string data, int horario, int duracao) { 
 
    if (horario < HORARIO_INICIAL or horario >= HORARIO_FINAL or duracao <= 0) return;
    
    bool livre = horario_esta_livre(agenda, profissional, data, horario); 
                
    if (livre) { 
        agenda.push_back({paciente, profissional, data, horario, duracao, "MARCADO"}); 
                    
        cout << "Atendimento marcado para " << paciente << endl; 
    } else { 
        throw invalid_argument("Horario ocupado");
    } 
    
} 

/**
 * @brief Remarca o agendamento de um paciente, recebe paciente, dia e horarios antigos e muda dia e horario.
 *
 * @param agenda Vetor de agendamentos no qual o Agendamento será remarcado.
 * @param paciente Nome do paciente que quer modificar seu agendamento.
 * @param data Ano-Mês-Dia do agendamento antigo.
 * @param horario Horário(24H) que o agendamento antigo foi marcado.
 * @param nova_data Nova data (Ano-Dia-Mês) que o agendamento será remarcado.
 * @param novo_horario Novo horario(24H) que o agendamento será remarcado.
 *
*/

    
void remarcar(vector<Agendamento> & agenda,string paciente, string data, int horario, string nova_data, int novo_horario) { 
    
    if (novo_horario < HORARIO_INICIAL or novo_horario >= HORARIO_FINAL) return;

    for (size_t i = 0; i < agenda.size(); i++) { 
        if (agenda[i].paciente != paciente or agenda[i].data != data or agenda[i].horario != horario) continue;

        bool livre = horario_esta_livre(agenda, agenda[i].profissional, nova_data, novo_horario); 
                
        if (livre) { 
            agenda[i].data = nova_data; agenda[i].horario = novo_horario; 
            
            cout << "Remarcado" << endl; 
        } else { 
            throw invalid_argument("Horario ocupado");
        } 
    } 
}

/**
 * @brief Remove um agendamento da agenda fornecida.
 *
 * @param agenda Vetor de agendamentos no qual o Agendamento será removido.
 * @param paciente Nome do paciente do agendamento a ser desmarcado.
 * @param profissional Nome do profissional no agendamento a ser desmarcado.
 * @param data Ano-Mês-Dia do agendamento a ser desmarcado.
 * @param horario Horário(24H) do agendamento a ser desmarcado.
 *
*/
void desmarcar(vector<Agendamento> & agenda, string paciente, string profissional, string data, int horario) { 
    bool encontrado{false};

    for (size_t i = 0; i < agenda.size(); i++){
        if (agenda[i].paciente == paciente && agenda[i].profissional == profissional && agenda[i].data == data && agenda[i].horario == horario){
            agenda.erase(agenda.begin() + i);
            encontrado = true;
            break;
        }
    }
    
    if (encontrado){
        cout << "Atendimento desmarcado" << endl;
    } else throw invalid_argument("Atendimento nao encontrado");
} 

/**
 * @brief Mostra todos os agendamentos marcados para o dia fornecido.
 *
 * @param agenda Vetor de agendamentos que será usado como base de busca.
 * @param data Ano-Mês-Dia dos agendamentos a serem exibidos.
 *
*/
void exibir(vector<Agendamento> & agenda, string data) { 
    // lista os atendimentos do dia
    bool vazio{true};

    for (size_t i = 0; i < agenda.size(); i++) { 
        if (agenda[i].data == data) { 
            cout << agenda[i].horario << " " << agenda[i].paciente << " " << agenda[i].profissional << " " << agenda[i].status << endl; 
            vazio = false;
        }     
    } 
    if(vazio) cout << "Dia vazio" << endl;
} 

int main() { 
    vector<Agendamento> agenda;

    try {
        adicionar(agenda,"Ana", "Dr. Silva", "2026-10-05", 9, 30); 
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        adicionar(agenda,"Bruno", "Dr. Silva", "2026-10-05", 9, 30); 
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        adicionar(agenda, "Carla", "Dra. Souza", "2026-10-05", 14, 60); 
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        remarcar(agenda, "Ana", "2026-10-05", 9, "2026-10-06", 10);    
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
    }
    
    exibir(agenda, "2026-10-05"); 

    try {
        desmarcar(agenda, "Carla", "Dra. Souza", "2026-10-05", 14);    
    } catch(const invalid_argument& e) {
        cout << e.what() << endl;
    }

    exibir(agenda, "2026-10-05");
    
    return 0; 
}
