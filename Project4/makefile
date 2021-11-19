ChainComp: ChainC Chainl ChainR

ChainC:
	g++ -c main/Chain.cpp cppfunk/ising2dfunk.cpp -larmadillo

Chainl:
	g++ Chain.o ising2dfunk.o -o Chain.out -larmadillo 

ChainR:
	./Chain.out

ChainLComp: ChainCL ChainlL ChainRL

ChainCL:
	g++ -c main/ChainLong.cpp cppfunk/ising2dfunk.cpp -larmadillo -fopenmp

ChainlL:
	g++ ChainLong.o ising2dfunk.o -larmadillo -lomp

ChainRL:
	./a.out

ChainParComp: ChainCPar ChainlPar ChainRPar

ChainCPar:
	g++ -c main/ChainPar.cpp cppfunk/ising2dfunk.cpp -larmadillo -fopenmp

ChainlPar:
	g++ ChainPar.o ising2dfunk.o -larmadillo -fopenmp

ChainRPar:
	./a.out
