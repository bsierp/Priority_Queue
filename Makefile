OBJ=./obj
FLAGS= -Wall -pedantic -std=c++2a -iquote inc
TRGDIR=./

__start__: ${TRGDIR}/Priority_Queue
			${TRGDIR}/Priority_Queue
${TRGDIR}/Priority_Queue: ${OBJ}	${OBJ}/main.o ${OBJ}/QueueC.o
						g++ -o ${TRGDIR}/Priority_Queue ${OBJ}/main.o ${OBJ}/QueueC.o

${OBJ}:
						mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Queue.hh

						g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/QueueC.o: inc/Queue.hh src/Queue.cpp src/QueueC.cpp
						g++ -c ${FLAGS} -o ${OBJ}/QueueC.o src/QueueC.cpp
clear:
						rm -f ${TRGDIR}/Priority_Queue ${OBJ}/*