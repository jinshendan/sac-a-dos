//********* knapsackheurDP.cpp *********

#include "kpSolverHeurDP.hpp"
#include "kpSolverDP.hpp"

void KpSolverHeurDP::solveUpperBound() {
	//TODO
	int sumWeight = 0;
	upperBoundOPT = 0;
	for(int i = 0; i < nbItems; i++) {		
		int masseLibre = knapsackBound - sumWeight;
		if (sumWeight + weights[i] <= knapsackBound) {
			sumWeight += weights[i];
			upperBoundOPT += values[i];
		}
		else {
			lastIndex = i;
			upperBoundOPT += values[i] * (knapsackBound - sumWeight) * 1.0 / weights[i];
			break;
		}		
	} 
 }

void KpSolverHeurDP::solve() {
	//TODO
	solveUpperBound();

	int left = max(0, lastIndex - nbSelectedReopt), right = min(lastIndex + nbUnselectedReopt, nbItems);
	KpSolverDP* kpDP = new KpSolverDP();
	int _nbItems = right - left + 1;
	int kpBound = knapsackBound;
	costSolution = 0;
	solution.resize(nbItems);
	for (int i = 0; i < left; i++){
		kpBound -= weights[i];
		costSolution += values[i];
		solution[i] = true;
	}
	vector<int> w(weights.begin() + left, weights.begin() + right + 1);
	vector<int> v(values.begin() + left, values.begin() + right + 1);

	kpDP->import(right - left + 1, kpBound, w, v);
	kpDP->solve();

	costSolution += kpDP->getSolutionCost();
	vector<bool> sol;
	kpDP->copySolution(&sol);
	for (int i = 0; i < _nbItems; i++)
		if (sol[i])
			solution[left + i] = true;
}
 
void KpSolverHeurDP::setNeighborhood(int nbSelectedOpt, int nbUnselectedOpt) {
	nbUnselectedReopt = nbUnselectedOpt;
	nbSelectedReopt = nbSelectedOpt;
}
