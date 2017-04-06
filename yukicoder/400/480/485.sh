#!/bin/sh

awk '{if($2 % $1){print "NO";} else {print $2/$1;}}'