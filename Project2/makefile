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

runP2: P2c P2l P2r

P2c:
	g++ -c Project2.cpp Project2func.cpp

P2l:
	g++ Project2.o Project2func.o -o Pr2.exe -larmadillo

P2r:
	./Pr2.exe
