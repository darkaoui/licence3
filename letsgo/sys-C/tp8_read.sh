#!/bin/bash
#we need to tp8_write.sh before

while true; do
  flock fifofile -c 'read line' < fifofile
  echo $line
done
