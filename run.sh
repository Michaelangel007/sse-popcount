size=1000000
iter=1000
names="cpu sse-lookup sse-bit-parallel bit-parallel-optimized bit-parallel lookup-8 lookup-64 lookup-3 lookup-4 lookup-7"

for name in $names
do
    ./$1 $name $size $iter
done
