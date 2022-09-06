#!/bin/sh

vagrant up --provision && \
vagrant ssh-config > tmp/ssh-config && \
ssh -F tmp/ssh-config -o RequestTTY=yes default /vagrant/scripts/show_xmas_tree.sh
