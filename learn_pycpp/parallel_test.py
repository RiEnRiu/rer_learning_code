import threading
import time
def python_fun(name):
    for i in range(10):
        print('python_fun({0}) {1}'.format(name,i))
        time.sleep(0.2)
    return 

'''
# frist install boost
unzip boost_1_69_0.zip
cd boost_1_69_0
# ./bootstrap.sh --with-libraries=python --with-toolset=gcc --with-python=$HOME/anaconda3/bin/python3 --with-python-version=3.6 --with-python-root=~/anaconda3/lib/python3
./bootstrap.sh --with-libraries=python --with-toolset=gcc 
./b2 cflags='-fPIC' cxxflags='-fPIC' --with-python include="$HOME/anaconda3/include/python3.6m/"
sudo ./b2 install
cd /usr/local/lib
sudo ln -s libboost_python36.so libbost_python3.so
sudo ln -s libboost_python36.a libboost_python3.so
sudo ln -s libboost_numpy36.so libboost_numpy3.so
sudo ln -s libboost_numpy36.a libboost_numpy3.a
sudo vim $HOME/.bashrc
    export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
'''

'''
# second make .os library
g++ -shared -fPIC -std=c++11 -O3 $HOME/anaconda3/lib/libpython3.6m.a parallel_not_work.cpp  -o parallel_not_work.so -I$HOME/anaconda3/include/python3.6m -lboost_python36
'''

'''
# third use .os in python
from parallel_not_work import test as test_not_parallel
'''
from parallel_not_work import test as test_not_parallel


print('***********    test parallel_not_work    ***********')
thp = threading.Thread(target=python_fun,args=('py',),daemon=True)
th1 = threading.Thread(target=test_not_parallel,args=('th1',),daemon=True)
th2 = threading.Thread(target=test_not_parallel,args=('not_work_2',),daemon=True)
print('thp start')
thp.start()
time.sleep(0.3)
print('th1 start')
th1.start()
time.sleep(0.3)
print('th2 start')
th2.start()
print('thp join')
thp.join()
print('th1 join')
th1.join()
print('th2 join')
th2.join()
print('')


'''
# first make .os library
g++ -shared -fPIC -std=c++11 -O3 parallel_work.cpp  -o parallel_work.so
'''

'''
# second use .os in python
import ctypes
so = ctypes.cdll.LoadLibrary
parallel_work = so('./parallel_work.so')
test_parallel = parallel_work.test
'''
import ctypes
so = ctypes.cdll.LoadLibrary
parallel_work = so('./parallel_work.so')
test_parallel = parallel_work.test
print('***********    test parallel_not_work    ***********')
thp = threading.Thread(target=python_fun,args=('py',),daemon=True)
th1 = threading.Thread(target=test_parallel,args=('th1',),daemon=True)
th2 = threading.Thread(target=test_parallel,args=('not_work_2',),daemon=True)
print('thp start')
thp.start()
time.sleep(0.3)
print('th1 start')
th1.start()
time.sleep(0.3)
print('th2 start')
th2.start()
print('thp join')
thp.join()
print('th1 join')
th1.join()
print('th2 join')
th2.join()


