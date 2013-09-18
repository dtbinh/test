sed -n '/<a /p' html.txt | sed 's#<a \([^>]*\)>#--SYN--\1--FIN--#g; s/<//g; s/>//g' | \
    sed 's/--SYN--/</g; s/--FIN--[^<]*</></g; s/[^<]*</</; s/--FIN--.*/>/;' | \
    sed "s#<[^>]*href=\([^a-zA-Z>]*http://[^ >]*\)[^>]*># @\1@#g; s/<[^>]*>//g; s/'//g; s/@/ /g" > url.txt
