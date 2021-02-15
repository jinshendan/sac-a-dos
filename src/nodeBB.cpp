//********* nodeBB.cpp *********

#include "nodeBB.hpp"
//#include <iostream>
//#include <fstream>

bool NodeBB::canBeRemoved() {
	return overCapacitated;
}

void NodeBB::init(int size){
	overCapacitated= false;

	isFixed.resize(size);
	isRemoved.resize(size);

	for(int i=0; i<size;i++){
		isFixed[i] = false;
		isRemoved[i] = false;
	}


    criticalIndex=-1;
    fractionalVariable=0;
    localLowerBound=0;
}

//TODO
void NodeBB::primalHeuristic(int kpBound, int nbItems, vector<int> & weights,  vector<int> & values) {
	//TODO
	primalSolution.resize(nbItems);
	localLowerBound = 0;

	int sumWeight = 0, sumValue = 0;
	
	for (int i = 0; i < nbItems; i++){
		if (isFixed[i]){
			sumWeight += weights[i];
			sumValue += values[i];
		}
	}
	if (sumWeight > kpBound){
		overCapacitated = true;
		return;
	}

	for (int i = 0; i < nbItems; i++) {
		if (isFixed[i]) {
			primalSolution[i] = true;
		}
		else if (!isRemoved[i]) {
			if(sumWeight + weights[i] <= kpBound) {
				primalSolution[i] = true;
				sumWeight += weights[i];
				sumValue += values[i];
			}	
		}
	}
	localLowerBound = sumValue;
}


//TODO:
void NodeBB::solveUpperBound(int kpBound, int nbItems, vector<int> & weights,  vector<int> & values) {
	//TODO
	criticalIndex = -1;
	localUpperBound = 0;

	int sumWeight = 0, sumValue = 0;
	
	for (int i = 0; i < nbItems; i++)
		if (isFixed[i]){
			sumWeight += weights[i];
			sumValue += values[i];
		}

	if (sumWeight > kpBound){
		overCapacitated = true;
		return;
	}

	for(int i = 0; i < nbItems; i++) {		
		if (!isRemoved[i] && !isFixed[i]) {
			if(sumWeight + weights[i] <= kpBound) {
				sumWeight += weights[i];
				sumValue += values[i];
				if (weights[i] == kpBound) break;
			}
			else {
				criticalIndex = i;
				fractionalVariable = (kpBound - sumWeight) * 1.0 / weights[i];
				sumValue += values[i] * fractionalVariable;
				break;
			}		
		}
	} 
	localUpperBound = sumValue;
}
