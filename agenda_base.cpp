// ========================================================== 
// Arquivo: agenda_base.cpp 
// Autor: Equipe de estagiarios - 03/02/2024 
// Alterado por: Joao - 15/05/2025 
// Alterado por: Marina - 09/01/2026 
// ========================================================== 

#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct A { 
    string paciente; 
    string profissional; 
    string data; 
    
    int horario; 
    int duracao; 
    
    string status;
}; 

vector<A> agenda; 

void adicionar(string paciente, string profissional, string data, int horario, int duracao) { 
    int horario_inicial{8};
    int horario_final{18};
 
    if (horario >= horario_inicial && horario < horario_final && duracao > 0) {  
        bool ok = true; 
                    
        for (int i = 0; i < agenda.size(); i++) { 
            if (agenda[i].data == data && agenda[i].horario == horario && agenda[i].profissional == profissional) { 
                ok = false;
                break;
            } 
        } 
                    
        if (ok) { 
            agenda.push_back({paciente, profissional, data, horario, duracao, "MARCADO"}); 
                        
            cout << "Atendimento marcado para " << paciente << endl; 
        } else { 
            cout << "Horario ocupado" << endl; 
        } 
    } 
    
} 
    
void remarcar(string paciente, string data, int horario, string nova_data, int novo_horario) { 
    // remarca o atendimento 
    for (int i = 0; i < agenda.size(); i++) { 
        if (agenda[i].paciente == paciente && agenda[i].data == data && agenda[i].horario == horario) { 
            bool ok = true; 
            
            for (int j = 0; j < agenda.size(); j++) { 
                if (agenda[j].data == nova_data && agenda[j].horario == novo_horario && agenda[j].profissional == agenda[i].profissional) { 
                    ok = false; 
                } 
            } 
            
            if (ok) { 
                agenda[i].data = nova_data; agenda[i].horario = novo_horario; cout << "Remarcado" << endl; 
            } else { 
                cout << "Horario ocupado" << endl; 
            } 
        } 
    } 
}

// void desmarcar(string paciente, stringstirstring d, int h) { 
// ag.erase(...); 
// } 

// TODO: rever isso depois (Joao, 2025) 

void exibir(string data) { 
    // lista os atendimentos do dia
    
    for (int i = 0; i < agenda.size(); i++) { 
        if (agenda[i].data == data) { 
            cout << agenda[i].horario << " " << agenda[i].paciente << " " << agenda[i].profissional << " " << agenda[i].status << endl; 
        } 
    } 
} 

int main() { 
    adicionar("Ana", "Dr. Silva", "2026-10-05", 9, 30); 
    adicionar("Bruno", "Dr. Silva", "2026-10-05", 9, 30); 
    adicionar("Carla", "Dra. Souza", "2026-10-05", 14, 60); 
    remarcar("Ana", "2026-10-05", 9, "2026-10-06", 10);
     
    exibir("2026-10-05"); 
    
    return 0; 
}