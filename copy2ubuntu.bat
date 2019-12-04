::rm
rmdir /s/q ubuntu

::root
mkdir .\ubuntu
copy .\README.md .\ubuntu
copy .\TODO.txt .\ubuntu

::file
mkdir .\ubuntu\file
copy .\file\* .\ubuntu\file

::project interview
mkdir .\ubuntu\interview
copy .\interview\*.py .\ubuntu\interview
copy .\interview\ans_card.jpg .\ubuntu\interview

::project learn_pycpp
mkdir .\ubuntu\learn_pycpp
copy .\learn_pycpp\*.py .\ubuntu\learn_pycpp
copy .\learn_pycpp\*.h .\ubuntu\learn_pycpp
copy .\learn_pycpp\*.cpp .\ubuntu\learn_pycpp

::project learn_pycy
mkdir .\ubuntu\learn_pycy
copy .\learn_pycy\*.pyx .\ubuntu\learn_pycy
copy .\learn_pycy\*.py .\ubuntu\learn_pycy

::project learn_tf
mkdir .\ubuntu\learn_tf
copy .\learn_tf\*.py .\ubuntu\learn_tf

::project REFERENCE
mkdir .\ubuntu\REFERENCE
copy .\REFERENCE\* .\ubuntu\REFERENCE

::copy to ubuntu
::xcopy /E/Y .\ubuntu X:\

pause

