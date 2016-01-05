function monitor {
    start=`date +%s`
    while ps -fp $1
    do 
        now=`date +%s`
        time=`echo "scale=2; ($now-$start)/60" | bc`
        echo been $time mins
        sleep 5
    done
    while true ; do  echo -e "\a"; sleep 1; done
}