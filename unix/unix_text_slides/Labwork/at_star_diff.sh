echo for with '$*'
for i in $*
do
echo --$i--
done
echo ---------------------------------------

echo for with '$@'
for i in $@
do
echo --$i--
done

echo ---------------------------------------
echo for with '"$@"'
for i in "$@"
do
echo --$i--
done
echo ---------------------------------------
echo for with '"$*"'
for i in "$*"
do
echo --$i--
done
