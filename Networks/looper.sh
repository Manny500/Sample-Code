#!/bin/bash

output_file="data.csv"

A="test.txt" ## file name
B=10 ####time between messages

############ VARS TO LOOP ##############
C=0.0 #### loss probability
D=0.0 ####corruption probability
E=1 ### window size
F=0 ## only 0 or 1, determines if tcp or not

############ VARS TO LOOP #############

G=0 ###debug

printf "Time_Between_Messages,Loss_Probability,Corruption_Probability,Window_Size,Protocol_Type,Number_Of_Events,Nanoseconds\n" >> "$output_file"

for l in $(seq 0 1 1);do
	for k in $(seq 1 1 10);do
		for j in $(seq 0.0 0.1 0.9);do 
			for i in $(seq 0.0 0.1 0.9);do 
				java "NetworkSimulator" $A $B $i $j $k $l $G >> "$output_file"
				printf "\n" >> "$output_file"
			done
		done
	done
done