#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627

#!/bin/bash

# 'inputfile' in the directory is the test file for partB

version=$1

if [ "$#" != 1 ]; then
	echo "Usage: partB.bash version"
else
	if [ "$version" = "A1" ] || [ "$version" = "A2" ]; then
		echo "Please enter numThreads, deadline(secs), numSquares for $version, or enter 'q' for quit:"
		while read numThreads deadline numSquares
		do
			if [ "$numThreads" == "q" ] || [ "$numThreads" == "quit" ]; then
				echo "See you!"
				break
			elif ! [[ $numThreads =~ ^[\-0-9]+$ ]]  ||
				! [[ $deadline =~ ^[\-0-9]+$ ]] ||
				! [[ $numSquares =~ ^[\-0-9]+$ ]] ;then
				# check if arguments are integer
				echo "Invalid input, please enter 3 integers slipt by space:"
			else
				if [ "$version" = "A1" ];then
					./partA1 $numThreads $deadline $numSquares
				elif [ "$version" = "A2" ]; then
					./partA2 $numThreads $deadline $numSquares
				fi				
				echo "Enter numThreads, deadline, numSquares for next test or enter 'q' for quit? "
			fi			
		done
	elif [ "$version" = "A3" ]; then
		echo "Coming soon: A3 version not implemented"
	else
		echo "Versions available: A1, A2, A3"
	fi
fi
