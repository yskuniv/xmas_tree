#!/bin/sh

/vagrant/xmas_tree_workload 11 &

htop

jobs_num=`jobs | sed -n -e 's/^\[\([0-9]*\)\]+\s*Running\s*\/vagrant\/xmas_tree_workload\s.*$/\1/p'`
if [ "x${jobs_num}" != x ]; then
    kill %${jobs_num}
else
    exit 1
fi
