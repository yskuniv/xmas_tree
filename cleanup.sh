#!/bin/sh

vagrant ssh-config > tmp/ssh-config && \
ssh -F tmp/ssh-config default make -C /vagrant clean && \
vagrant destroy -f
