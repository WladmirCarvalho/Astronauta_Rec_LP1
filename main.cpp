#include <iostream>
#include <string>
#include <vector>
#include "Astronauta.h"
#include "Voo.h"
#include "Nave.h"

using namespace std;

vector<Astronauta*> vetor1;
vector<Voo*> vetor2;
vector<Nave*> vetor3;

Astronauta* procura1(string c) {
	for(int x=0; x<vetor1.size(); x++) {
		if(vetor1[x]->cpf == c) return vetor1[x];
	}
	return nullptr;
}

Voo* procura2(int c) {
	for(int y=0; y<vetor2.size(); y++) {
		if(vetor2[y]->codigo == c) return vetor2[y];
	}
	return nullptr;
}

Nave* procura3(int c) {
	for(int w=0; w<vetor3.size(); w++) {
		if(vetor3[w]->codigo == c) return vetor3[w];
	}
	return nullptr;
}

bool t(Voo* vo, string c) {
	for(int z=0; z<vo->passageiros.size(); z++) {
		if(vo->passageiros[z] == c) return true;
	}
	return false;
}

int main() {
	string ler;

	while (cin >> ler) {
		if(ler == "FIM") break;

		if(ler == "CADASTRAR_ASTRONAUTA") {
			string func, a, b;
			int c;
			cin >> func >> a >> c;
			getline(cin >> ws, b);

			if(procura1(a) != nullptr) {
				cout << "Erro: CPF " << a << " ja existe.\n";
			} else {
				if(func == "COMANDANTE") vetor1.push_back(new Comandante(a, c, b));
				else if(func == "ENGENHEIRO") vetor1.push_back(new Engenheiro(a, c, b));
				else if(func == "CIENTISTA") vetor1.push_back(new Cientista(a, c, b));
				else if(func == "TURISTA") vetor1.push_back(new Turista(a, c, b));
				cout << "Cadastrado com sucesso.\n";
			}
		}
		else if(ler == "CADASTRAR_NAVE") {
			int cod, cap;
			string n;
			cin >> cod >> cap;
			getline(cin >> ws, n);

			if(procura3(cod) != nullptr) cout << "Erro: Nave com codigo " << cod << " ja existe.\n";
			else if(cap <= 0) cout << "Erro: A capacidade deve ser maior que zero.\n";
			else {
				vetor3.push_back(new Nave(cod, cap, n));
				cout << "Nave cadastrada com sucesso.\n";
			}
		}
		else if(ler == "CADASTRAR_VOO") {
			int cod1;
			cin >> cod1;

			if(procura2(cod1) != nullptr) cout << "Erro: Voo com codigo " << cod1 << " ja existe.\n";
			else {
				vetor2.push_back(new Voo(cod1));
				cout << "Voo cadastrado com sucesso.\n";
			}
		}
		else if(ler == "ASSOCIAR_NAVE") {
			int codVoo, codNave;
			cin >> codVoo >> codNave;

			Voo* vo = procura2(codVoo);
			Nave* nv = procura3(codNave);

			if(vo == nullptr) cout << "Erro: Voo nao cadastrado.\n";
			else if(nv == nullptr) cout << "Erro: Nave nao cadastrada.\n";
			else if(vo->estado != planejado) cout << "Erro: Voo nao esta planejado.\n";
			else {
				vo->naveAssociada = nv;
				cout << "Nave associada ao voo com sucesso.\n";
			}
		}
		else if(ler == "ADICIONAR_ASTRONAUTA") {
			string cpf2;
			int cod2;
			cin >> cpf2 >> cod2;

			Astronauta* ast = procura1(cpf2);
			Voo* vo = procura2(cod2);

			if(ast == nullptr) cout << "Erro: Nao cadastrado.\n";
			else if(vo == nullptr) cout << "Erro: Voo nao cadastrado.\n";
			else if(vo->estado != planejado) cout << "Erro: Voo nao esta planejado.\n";
			else if(ast->vivo == false) cout << "Erro: Esta morto.\n";
			else if(t(vo, cpf2)) cout << "Erro: Ja inserido no voo.\n";
			else if(vo->naveAssociada != nullptr && vo->passageiros.size() >= vo->naveAssociada->capacidade) {
				cout << "Erro: Capacidade da nave excedida.\n";
			} else {
				vo->passageiros.push_back(cpf2);
				cout << "Adicionado ao voo.\n";
			}
		}
		else if(ler == "REMOVER_ASTRONAUTA") {
			string cpf3;
			int cod3;
			cin >> cpf3 >> cod3;

			Astronauta* ast = procura1(cpf3);
			Voo* vo = procura2(cod3);

			if(ast == nullptr) cout << "Erro: Nao cadastrado.\n";
			else if(vo == nullptr) cout << "Erro: Voo nao cadastrado.\n";
			else if(vo->estado != planejado) cout << "Erro: Voo nao esta planejado.\n";
			else {
				bool rmv = false;
				for (int i=0; i<vo->passageiros.size(); i++) {
					if(vo->passageiros[i] == cpf3) {
						vo->passageiros.erase(vo->passageiros.begin() + i);
						rmv = true;
						cout << "Removido do voo.\n";
						break;
					}
				}
				if(rmv == false) cout << "Erro: Nao compoe a lista do voo.\n";
			}
		}
		else if (ler == "LANCAR_VOO") {
			int cod4;
			cin >> cod4;
			Voo* vo = procura2(cod4);

			if(vo == nullptr) cout << "Erro: Voo nao cadastrado.\n";
			else if(vo->estado != planejado) cout << "Erro: Voo nao esta planejado.\n";
			else if(vo->passageiros.empty()) cout << "Erro: Voo sem passageiros.\n";
			else if(vo->naveAssociada == nullptr) cout << "Erro: Voo sem nave associada.\n";
			else {
				bool ok = true;
				bool temComandante = false;
				bool temEngenheiro = false;

				for(int i=0; i<vo->passageiros.size(); i++) {
					Astronauta* ast = procura1(vo->passageiros[i]);
					if(ast->vivo == false || ast->disponivel == false) ok = false;
					if(ast->funcao() == "Comandante") temComandante = true;
					if(ast->funcao() == "Engenheiro") temEngenheiro = true;
				}

				if(ok == false) {
					cout << "Erro: Existem passageiros mortos ou indisponiveis no voo.\n";
				} else if(!temComandante || !temEngenheiro) {
					cout << "Erro: O voo precisa de pelo menos um Comandante e um Engenheiro.\n";
				} else {
					vo->estado = emCurso;
					for(int i=0; i<vo->passageiros.size(); i++) {
						procura1(vo->passageiros[i])->disponivel = false;
					}
					cout << "Voo lancado com sucesso.\n";
				}
			}
		}
		else if(ler == "EXPLODIR_VOO") {
			int cod5;
			cin >> cod5;
			Voo* vo = procura2(cod5);

			if(vo == nullptr) cout << "Erro: Voo nao cadastrado.\n";
			else if(vo->estado != emCurso) cout << "Erro: O voo nao esta em curso.\n";
			else {
				vo->estado = finalizadoComExplosao;
				for(int i=0; i<vo->passageiros.size(); i++) {
					Astronauta* ast = procura1(vo->passageiros[i]);
					ast->vivo = false;
					ast->disponivel = false;
				}
				cout << "Voo finalizado com explosao. Tripulacao morta.\n";
			}
		}
		else if(ler == "FINALIZAR_VOO") {
			int cod6;
			cin >> cod6;
			Voo* vo = procura2(cod6);

			if(vo == nullptr) cout << "Erro: Voo nao cadastrado.\n";
			else if(vo->estado != emCurso) cout << "Erro: O voo nao esta em curso.\n";
			else {
				vo->estado = finalizadoComSucesso;
				for (int i=0; i<vo->passageiros.size(); i++) {
					procura1(vo->passageiros[i])->disponivel = true;
				}
				cout << "Voo finalizado com sucesso. Tripulacao retornou.\n";
			}
		}
		else if(ler == "LISTAR_VOOS") {
			cout << "--- Listagem de Voos ---\n";
			est estados[4] = {planejado, emCurso, finalizadoComSucesso, finalizadoComExplosao};
			string n[4] = {"Planejados", "Em Curso", "Finalizados com Sucesso", "Finalizados com Explosao"};

			for(int e=0; e<4; e++) {
				cout << "- " << n[e] << ":\n";
				for(int i=0; i<vetor2.size(); i++) {
					if(vetor2[i]->estado == estados[e]) {
						cout << "  Codigo: " << vetor2[i]->codigo << "\n";
						if(vetor2[i]->naveAssociada != nullptr) {
							cout << "  Nave: " << vetor2[i]->naveAssociada->nome << "\n";
						}
						cout << "  Passageiros:\n";
						for(int j=0; j<vetor2[i]->passageiros.size(); j++) {
							Astronauta* ast = procura1(vetor2[i]->passageiros[j]);
							cout << "    [" << ast->cpf << "] " << ast->nome << " (" << ast->funcao() << ")\n";
						}
					}
				}
			}
		}
		else if(ler == "LISTAR_MORTOS") {
			cout << "--- Mortos ---\n";
			for (int i=0; i<vetor1.size(); i++) {
				if(vetor1[i]->vivo == false) {
					cout << "CPF: " << vetor1[i]->cpf << " | Nome: " << vetor1[i]->nome << " | Funcao: " << vetor1[i]->funcao() << "\n";
					cout << "Voos participados: ";
					bool p1 = true;

					for (int j=0; j<vetor2.size(); j++) {
						if(vetor2[j]->estado != planejado && t(vetor2[j], vetor1[i]->cpf)) {
							if(p1 == false) cout << ", ";
							cout << vetor2[j]->codigo;
							p1 = false;
						}
					}
					cout << "\n";
				}
			}
		}
	}

	return 0;
}