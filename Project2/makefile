gitcommitall: gitAA gitCAA

gitAA:
	git add --all

gitCAA:
	git commit -m 'Added by Henrik'

LargestOD: LODc LODl LODr

LODc:
	g++ -c LargestOffDiagTest.cpp

LODl:
	g++ -larmadillo LargestOffDiagTest.o -o LOD.out

LODr:
	./LOD.out
