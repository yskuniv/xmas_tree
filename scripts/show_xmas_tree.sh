#!/bin/sh

/vagrant/xmas_tree_workload 11 &

htop

jobs_num=`jobs | sed -n -e 's/^\[\([0-9]*\)\].*xmas_tree_workload.*$/\1/p'`
kill %${jobs_num}
