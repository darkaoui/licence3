#!/bin/bash
#We need to create a fifo file named fifofile before
while true;do
sleep 2s
flock fifofile -c 'echo  bonjour les potes' > fifofile
done
