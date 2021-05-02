#!/bin/bash

g++ *.cpp -o vereadores
valgrind ./vereadores csv-exemplos/capitais/vitória-candidatos.csv csv-exemplos/capitais/vitória-partidos.csv