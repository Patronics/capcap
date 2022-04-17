#!/usr/bin/env bash
#echo "pre-start"
source twilio.env
/home/pi/.pyenv/shims/python captionator.py -m ./models/model.tflite -s ./models/large_vocabulary.scorer -t 2>&1 > ../output.txt
#python captionator.py -m ./models/model.tflite -t
#echo "started"
