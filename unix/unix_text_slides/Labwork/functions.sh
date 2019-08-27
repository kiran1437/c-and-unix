function f()
{
echo in function $FUNCNAME
echo "\$1=$1"
echo "\$2=$2"
echo "\$3=$3"
echo "\$*=$*"
echo "\$#=$#"
echo "\$0=$0"

echo CMDARGS is ${CMDARGS[*]}
echo bye from function
}


echo "\$#=$#"
echo "\$1=$1"
echo "\$3=$3"

CMDARGS=( $* )

f  one two three  xyz 

echo "\$#=$#"
echo "\$1=$1"
echo "\$3=$3"

