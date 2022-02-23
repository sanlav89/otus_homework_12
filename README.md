## Домашнее задание №12 “Компьютерное зрение”  
В качестве модели машинного обучения выбрана модель, построенная на сверточных нейронных сетях с использованием фреймворка tensorflow.  
Для сборки использовал docker  
```bash  
$ docker run --rm -ti -v $(pwd):/usr/src/app sdukshis/cppml  
```  
## Запуск исполняемого файла  
```bash  
$ git clone https://github.com/sanlav89/otus_homework_12  
$ cd ./otus_homework_12  
$ cmake -B build  
$ cmake --build build  
$ ./build/bin/fashion_demo ./train/test.csv  
0.909  
```  
## Запуск unit-тестов  
```bash  
$ ./build/bin/test_fashion  
```  
