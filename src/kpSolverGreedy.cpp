//********* knapsackGreedy.cpp *********

#include "kpSolverGreedy.hpp"


//TODO: calcul de relaxation continue, c'est le glouton ou un objet peut etre fractionaire
// seule la valeur du sac a dos continu est gardee, sauvegardee dans upperBoundOPT, pas la composition du sac a dos continu
void KpSolverGreedy::solveUpperBound() {
	//TODO
	int sumWeight = 0;
	upperBoundOPT = 0;
	for(int i = 0; i < nbItems; i++) {		
		if(sumWeight + weights[i] <= knapsackBound) {
			sumWeight += weights[i];
			upperBoundOPT += values[i];
		}
		else {
			upperBoundOPT += values[i] * (knapsackBound - sumWeight) * 1.0 / weights[i];
			break;
		}		
	} 
}

//TODO: resolution de borne inferieure: algorithme glouton "discret", qui donne une borne inferieure a mettre a jour dans costSolution
// et une composition du sac a dos a ecrire dans le vector<bool> solution heritee de la classe mere

void KpSolverGreedy::solveLowerBound() {
	//TODO
	int sumWeight = 0;
	solution.resize(nbItems);
	for (int i = 0; i < nbItems; i++) {
		if(sumWeight + weights[i] <= knapsackBound) {
			sumWeight += weights[i];
			costSolution += values[i];
			solution[i] = 1;
		}	
	}
}

void KpSolverGreedy::solve() {
	solveUpperBound();
	solveLowerBound();
}
