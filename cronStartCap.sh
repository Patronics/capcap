#!/usr/bin/env bash

#move to your home directory and start with a cron job

source ./.bashrc
pulseaudio --start
cd capcap
./start.sh
