all: testProgDyn testHeur testBB testIterHeur


testIterHeur: KpSolver.o KpSolverDP.o  KpSolverHeurDP.o KpSolverGreedy.o ../test/testIterHeur.cpp
	g++ -std=c++17 -O3 -W -I../src KpSolver.o KpSolverDP.o KpSolverHeurDP.o KpSolverGreedy.o ../test/testIterHeur.cpp -o testIterHeur

testBB: KpSolver.o KpSolverDP.o NodeBB.o KpSolverHeurDP.o KpSolverGreedy.o KpSolverBB.o ../test/testBB.cpp
	g++ -std=c++17 -O3 -W -I../src KpSolver.o KpSolverDP.o KpSolverGreedy.o NodeBB.o KpSolverHeurDP.o KpSolverBB.o ../test/testBB.cpp -o testBB

testHeur: KpSolver.o KpSolverDP.o  KpSolverHeurDP.o KpSolverGreedy.o ../test/testHeur.cpp
	g++ -std=c++17 -O3 -W -I../src KpSolver.o KpSolverDP.o KpSolverHeurDP.o KpSolverGreedy.o ../test/testHeur.cpp -o testHeur

testProgDyn:  KpSolver.o KpSolverDP.o ../test/testProgDyn.cpp
	g++ -std=c++17 -O3 -W -I../src KpSolver.o KpSolverDP.o ../test/testProgDyn.cpp -o testProgDyn 

KpSolverBB.o: ../src/kpSolverBB.cpp
	g++ -std=c++17 -o KpSolverBB.o -O3 -W -c -I../src ../src/kpSolverBB.cpp

NodeBB.o: ../src/nodeBB.cpp
	g++ -std=c++17 -o NodeBB.o -O3 -W -c -I../src ../src/nodeBB.cpp

KpSolverHeurDP.o: ../src/kpSolverHeurDP.cpp
	g++ -std=c++17 -o KpSolverHeurDP.o -O3 -W -c -I../src ../src/kpSolverHeurDP.cpp

KpSolverGreedy.o: ../src/kpSolverGreedy.cpp
	g++ -std=c++17 -o KpSolverGreedy.o -O3 -W -c -I../src ../src/kpSolverGreedy.cpp

KpSolverDP.o: ../src/kpSolverDP.cpp
	g++ -std=c++17 -o KpSolverDP.o -O3 -W -c -I../src ../src/kpSolverDP.cpp

KpSolver.o: ../src/kpSolver.cpp
	g++ -std=c++17 -o KpSolver.o -O3 -W -c -I../src ../src/kpSolver.cpp

clean:
	rm -rf *.o

