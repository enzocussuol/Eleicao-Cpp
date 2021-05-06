#!/bin/bash

echo "Compilando..."
g++ *.cpp -o vereadores

echo "Compilado com sucesso. Executando..."

./vereadores csv-exemplos/capitais/vitória-candidatos.csv csv-exemplos/capitais/vitória-partidos.csv 15/11/2020