export MYLIBS_SOURCE_HOME=`pwd`
export MYLIBSHOME=${MYLIBS_SOURCE_HOME}/inst
mkdir -p ${MYLIBSHOME}/lib
mkdir -p ${MYLIBSHOME}/inc

export MYLIBS_CPFLAGS=" -g -c -Wall -fPIC -I ${MYLIBS_SOURCE_HOME}/inc"
export MYLIBS_LKFLAGS=" -shared -WL,-soname,"

cd ${MYLIBS_SOURCE_HOME}/Calculus/
make
cp *.h ${MYLIBSHOME}/inc/
cd ${MYLIBS_SOURCE_HOME}


echo "export MYLIBSHOME=${MYLIBSHOME}" > env.sh
echo "export MYLIBS_CPFLAGS=\" -I \${MYLIBSHOME}/inc -L\${MYLIBSHOME}/lib -lCalculus\"" >> env.sh
echo "export LD_LIBRARY_PATH=\${MYLIBSHOME}/lib:\${LD_LIBRARY_PATH}" >> env.sh

echo "[DONE]   Dont forget to source env.sh!"
