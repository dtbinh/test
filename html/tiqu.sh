#!/bin/sh

ls ~/ -Al | grep "vim" >./log 
cat ./log | awk -F ' ' {'print $9'}
