CXX=g++

SYSTEMC_PATH=/usr/local/systemc-2.3.1
SYSTEMC_AMS_PATH=/usr/local/systemc-ams-2.1

MAIN=sin_source.cpp
MAIN2=escalador.cpp
MAIN3=integrador.cpp
MAIN4=escalador2.cpp
MAIN5=adc.cpp
MAIN6=convertidor_centigrados.cpp
MAIN7=kelvin.cpp
MAIN8=faren.cpp
MAIN9=alarma.cpp
MAIN10=display.cpp
TB=testbench.cpp

COMP=sin_source.o
COMP2=escalador.o
COMP3=integrador.o
COMP4=escalador2.o
COMP5=adc.o
COMP6=convertidor_centigrados.o
COMP7=kelvin.o
COMP8=faren.o
COMP9=alarma.o
COMP10=display.o

COMP_TB=testbench.o
EXE=sin_source_tb.exe

INC=-I${SYSTEMC_PATH}/include -I${SYSTEMC_AMS_PATH}/include
LINK=ar -rcs libmodels.a
LIBDIR=-L${SYSTEMC_PATH}/lib-linux64 -L$(SYSTEMC_AMS_PATH)/lib-linux64
LIBS=-L. -o ${EXE} -lmodels -lsystemc-ams -lsystemc

all:
	${CXX} -c ${MAIN} ${INC} 
	${LINK} ${COMP}
	${CXX} -c ${MAIN2} ${INC} 
	${LINK} ${COMP2}
	${CXX} -c ${MAIN3} ${INC} 
	${LINK} ${COMP3}
	${CXX} -c ${MAIN4} ${INC} 
	${LINK} ${COMP4}
	${CXX} -c ${MAIN5} ${INC} 
	${LINK} ${COMP5}
	${CXX} -c ${MAIN6} ${INC} 
	${LINK} ${COMP6}
	${CXX} -c ${MAIN7} ${INC} 
	${LINK} ${COMP7}
	${CXX} -c ${MAIN8} ${INC} 
	${LINK} ${COMP8}
	${CXX} -c ${MAIN9} ${INC} 
	${LINK} ${COMP9}
	${CXX} -c ${MAIN10} ${INC} 
	${LINK} ${COMP10}
	${CXX} -c ${TB} ${INC}
	${CXX} ${COMP_TB} ${LIBDIR} ${LIBS}
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/systemc-ams-2.1/lib-linux64
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/systemc-2.3.1/lib-linux64/
	export LD_LIBRARY_PATH