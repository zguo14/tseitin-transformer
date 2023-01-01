#include "satSolver.h"
#include "minisat/core/SolverTypes.h"
#include "minisat/core/Solver.h"
#include <memory>

bool satCallingMiniSat(unsigned int numVar, std::vector<std::vector<int>> &cnf) {
  // your code starts here
  	std::unique_ptr<Minisat::Solver> solver(new Minisat::Solver());
	std::vector<Minisat::Lit> lits;
	
	for (int i = 0; i < numVar; i++) {
		lits.push_back(Minisat::mkLit(solver->newVar()));// lits[0] is var 1
	}

	for (int i = 0; i < cnf.size(); i++) {
		Minisat::vec<Minisat::Lit> clause;
		for (int j = 0; j < cnf.at(i).size(); j++) {
			int l = cnf.at(i).at(j);
			if (l > 0) {
				clause.push(lits.at(l - 1));
			} else {
				clause.push(~lits.at(-l - 1));
			}
		}
		solver->addClause(clause); 
		clause.clear();
	}
	return solver->solve();
}