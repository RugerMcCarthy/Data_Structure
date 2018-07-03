#!/bin/bash
#指定解释器

declare -a prime
for i in `seq 0 10000`;do
    prime[$i]=0
done;
for i in `seq 2 1000`;do
    if [[ ${prime[$i]} -eq 0 ]];then
        prime[0]=$[${prime[0]}+1]
        prime[${prime[0]}]=$i;
        echo $i;
    fi
    for (( j=1;j<=${prime[0]};++j));do
        if [[ $[ ${prime[$j]} * $i ] -gt 1000 ]];then
            break
        fi
        prime[$[${prime[$j]}*$i]]=1
        if [[ $[$i%${prime[$j]}] -eq 0 ]];then
            break
        fi
    done
done

