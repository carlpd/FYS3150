gitcaH: gitAA gitCAA gitget gitP

gitAA:
	git add --all

gitCAA:
	git commit -m 'Added by Henrik'

gitget:
	git pull

gitP:
	git push

LargestOD: LODc LODl LODr

LODc:
	g++ -c LargestOffDiagTest.cpp

LODl:
	g++ -larmadillo LargestOffDiagTest.o -o LOD.out

LODr:
	./LOD.out

runP6: P6c P6l P6r

P6c:
	g++ -c problem6.cpp Project2func.cpp

P6l:
	g++ problem6.o Project2func.o -o Pr6.exe -larmadillo

P6r:
	./Pr6.exe

runP2: P2c P2l P2r

P2c:
	g++ -c Project2.cpp Project2func.cpp

P2l:
	g++ Project2.o Project2func.o -o Pr2.exe -larmadillo

P2r:
	./Pr2.exe

runP7: P7c P7l P2r

P7c:
	g++ -c problem7.cpp Project2func.cpp

P7l:
	g++ -o pr7.exe problem7.o Project2func.o -larmadillo

P7r:
	./pr7.exe
