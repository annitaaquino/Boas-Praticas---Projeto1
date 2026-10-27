# Introdução
Este projeto é uma implementação simples de um sistema de agenda em C++ que controla consultas e atendimentos.

Cada agendamento possui um campo para o nome do paciente, nome do profissional associado à consulta, data do agendamento, horário, duração estimada e status.

O sistema permite adicionar, remarcar, remover e exibir agendamentos e permite também verificar se um horário desejado está livre.

Tentar marcar ou remarcar dois procedimentos para o mesmo horário com o mesmo profissional ou desmarcar um atendimento inexistente resultam em exceções, controlando possíveis erros na execução do programa e qualquer procedimento que tentar ser marcado fora do horário válido (das 8h às 18h por padrão) será descartado.

# Autores
Annita Aquino Freitas
(annitaaquino@gmail.com)

Anthony Gabriel Gomes Rocha
(aggr5555@gmail.com)

Júlia de Medeiros Borba
(borba.julia06@gmail.com)

Matheus Lucheze Lopes
(matlopes775@gmail.com)


# Compilando e rodando

Para compilar este programa, baixe o compilador g++, abra o terminal na paste desse projeto e execute o seguinte comando:

```bash
g++ agenda_base.cpp -I./include -std=c++17 -o agenda
```

Após compilar, rode o executável:

* **Linux / macOS:**
  ```bash
  ./agenda
  ```
* **Windows (PowerShell / Prompt):**
  ```cmd
  agenda.exe
  ```