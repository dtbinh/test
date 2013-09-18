#! /bin/sh

sed '/^#/d' quotas | sort > quotas.sorted
sed '/^#/d' sales  | sort > sales.sorted

join quotas.sorted sales.sorted
rm quotas.sorted sales.sorted
