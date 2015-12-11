${MYLIBSHOME}/lib/libCalculus.so: CalculusIntegral1F.cxx
	g++ ${MYLIBS_CPFLAGS} -c *.cxx -o CalculusIntegral1F.o 
	g++ ${MYLIBS_LKFLAGS}libCalculus.so *.o -o ${MYLIBSHOME}/lib/libCalculus.so
	rm *.o
