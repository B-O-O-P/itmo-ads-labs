# Запросы на деревьях

## A. LCA

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 5 секунд

Ограничение по памяти: 256 мегабайт

Дано подвешенное дерево с корнем в первой вершине. Вам нужно ответить наmзапросов вида
"найти LCA двух вершин".

LCA вершин _u_ и _v_ в подвешенном дереве — это наиболее удалённая от корня дерева верши-
на, лежащая на обоих путях отuиvдо корня.

### Формат входных данных

В первой строке задано целое число _n_ — число вершин в дереве ( 1 ⩽ _n_ ⩽ 2 * 10^5 ).
В следующих _n_ - 1 строках записано одно целое число _x_. Число _x_ на строке _i_ означает, что _x_ —
предок вершины _i_ (_x_ < _i_).
Затем дано числоm.
Далее заданы _m_ ( 0 ⩽ _m_ ⩽ 5 * 10^5 ) запросов вида (_u_, _v_) — найти LCA двух вершин _u_ и _v_
 ( 1 ⩽ _u_, _v_ ⩽ _n_ , _u_ ≠ _v_).

### Формат выходных данных

Для каждого запроса выведите LCA двух вершин на отдельной строке.

### Примеры

**стандартный ввод**
```c++
5 
1 
1 
2 
3 
2
2 3
4 5
```
**стандартный вывод**
```c++
1 1 
```
**стандартный ввод**
```c++
5 
1 
1 
2 
2 
3
4 5
4 2
3 5
```

**стандартный вывод**
```c++
2
2
1
```

### [Решение](A.cpp)

## B. Самое дешевое ребро

Имя входного файла: minonpath.in

Имя выходного файла: minonpath.out

Ограничение по времени: 4 секунды

Ограничение по памяти: 256 мегабайт

Дано подвешенное дерево с корнем в первой вершине. Все ребра имеют веса (стоимости). Вам
нужно ответить на _M_ запросов вида "найти у двух вершин минимум среди стоимостей ребер пути
между ними".

### Формат входных данных

В первой строке задано целое число _n_ — число вершин в дереве ( 1 ⩽ _n_ ⩽ 2 * 10^5 ).
В следующих _n_ - 1 строках записаны два целых числа _x_ и _y_. Число _x_ на строке _i_ означает, что
_x_ — предок вершины _i_, _y_ задает стоимость ребра ( _x_ < _i_;|y| ⩽ 10^6 ).
Далее заданы _m_ ( 0 ⩽ _m_ ⩽ 5 * 10^5 ) запросов вида ( _x_, _y_) — найти минимум на пути из _x_ в _y_
( 1 ⩽ _x_, _y_ ⩽ _n_; _x_≠_y_).

### Формат выходных данных

Выведите ответы на запросы.

### Примеры

**minonpath.in**
```c++
5
1 2
1 3
2 5
3 2
2
2 3
4 5
```

**minonpath.out**
```c++
2
2
```

**minonpath.in**
```c++
5
1 1
1 2
2 3
3 4
2
1 4
3 2
```

**minonpath.out**
```c++
1
1
```

### [Решение](B.cpp)

## C. Прибавление на пути

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Задано дерево. В каждой вершине есть значение, изначально все значения равны нулю. Требу
ется обработать запрос прибавления на пути и запрос значения в вершине.

### Формат входных данных

В первой строке задано целое число _n_ — число вершин в дереве ( 1 ⩽ _n_ ⩽ 3 * 10^5 ).
В следующих _n_ - 1 строках заданы ребра дерева: по два целых числа _v_ и _u_ в строке — номера
вершин, соединенных ребром ( 1 ⩽ _v_; _u_ ⩽ _n_).
В следующей строке задано целое число _m_ — число запросов ( 1 ⩽ _m_ ⩽ 5 * 10^5 ).
Следующие _m_ строк содержат запросы в одном из двух форматов:


* + v u d — прибавить число _d_ во все значения в вершинах на пути от _v_ до _u_ ( 1 ⩽ _v_, _u_ ⩽ _n_;
1 ⩽ _d_ ⩽ 10^9 );

* ? v — вывести значение в вершине _v_ ( 1 ⩽ _v_ ⩽ _n_).

### Формат выходных данных

Выведите ответы на все запросы.

### Примеры

**стандартный ввод**
```c++
5
1 2
1 3
3 4
3 5
5
+ 2 5 1

?
+ 1 1 2
?
?
```

**стандартный вывод**
```c++
1
3
1
```

## D. Почтовая реформа

Имя входного файла: mail.in

Имя выходного файла: mail.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

В Флатландии идет пора реформ. Недавно была проведена реформа дорог, так что теперь по
дорогам страны из любого города можно добраться в любой другой, причем только одним спосо
бом. Также была проведена реформа волшебников, так что в каждом городе остался ровно один
волшебник. Теперь же началась реформа почтовой системы.
Недавно образованное почтовое агентство «Экс-Федя» предлагает уникальную услугу — коллек
тивную посылку. Эта услуга позволяет отправлять посылки жителям всех городов на каком-либо
пути по цене обычной посылки. Удивительно, но пользоваться такой услугой стали только волшеб
ники Флатландии, которые стали в большом количестве отправлять друг другу магические кактусы.
Агентство столкнулось с непредвиденной проблемой: как известно, все волшебники живут в башнях
и мало того, что не строят в них лестницы, так еще время от времени меняют их высоту. Поэто
му, чтобы доставить посылку волшебнику, который живет в башне высотой _h_, курьеру агентства
требуется иметь с собой не менее _h_ метров веревки.
Вам поручено руководить отделом логистики — по имеющимся данным о высотах башен и об их
изменениях вам нужно определять минимальную длину веревки, которую нужно выдать курьеру,
который доставляет посылки между городами _i_ и _j_.

### Формат входных данных

Первая строка входного файла содержит число _n_ — количество городов в Флатландии
( 1 ⩽ _n_ ⩽ 50000 ). Во второй строке находится _n_ положительных чисел, не превосходящих 10^5 —
высоты башен в городах. В следующих _n_ - 1 строках содержится по два числа _ui_ и _vi_ — описание
 _i_-й дороги, 1 ⩽ _ui_, _vi_⩽ _n_; _ui_≠_vi_. В следующий строке содержится число _k_ — количество запросов
( 1 ⩽ _k_ ⩽ 100000 ). В следующих _k_ строках содержатся описания запросов в следующем формате:

* Уведомление от волшебника из города _i_ о том, что высота его башни стала равна _h_, имеет вид
! i h, 1 ⩽ _i_ ⩽ _n_, 1 ⩽ _h_ ⩽ 10^5.

* Запрос от курьера о выдаче веревки для доставки посылок во все города на пути отiдоj
включительно имеет вид ?i j, 1 ⩽ _i_, _j_ ⩽ _n_.

### Формат выходных данных

Для каждого запроса доставки посылок выведите минимальную длину веревки, которую необ
ходимо выдать курьеру.


### Примеры

**mail.in** 
```c++
3
1 2 3
1 3
2 3
5
? 1 2
! 1 5
? 2 3
! 3 2
? 1 2
```

**mail.out** 
```c++
3
3
5
```

**mail.in** 
```c++
1 
100 
5 
! 1 1 
? 1 1 
! 1 1000 
? 1 1 
! 1 1
```

**mail.out** 
```c++
1
1000
```

## E. Декомпозиция

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Рассмотрим дерево _T_. Назовем **деревом декомпозиции** корневое дерево _D_(_T_).
Выберем любую из вершин дерева _T_, назовем ее _r_. Рассмотрим все компоненты связности дерева
 _T_, после удаления вершины _r_: _S1_, _S2_,...; _Sk_. Тогда корнем _D_(_T_) будет вершина _r_, а детьми _r_ в _D_(_T_) 
будут _D_(_S1_), _D_(_S2_),..., _D_(_Sk_).
Вам задано _T_. Найдите дерево декомпозиции, высота которого не более 20. Высотой дерева
называется максимальное число вершин, которые может содержать простой путь начинающийся в
корне.

### Формат входных данных

Первая строка содержит _n_ — число вершин дерева _T_ ( 1 ⩽ _n_ ⩽ 2 * 10^5 ).
Следующие _n_ - 1 строк содержат ребра дерева. Каждое ребро описывается парой чисел _vi_,_ui_ —
концы ребра ( 1 ⩽ _vi_, _ui_ ⩽ _n_).

### Формат выходных данных

Выведите _n _ чисел: _i_-е число — родитель вершины _i_ в дереве декомпозиции, если вершина явля
ется корнем, выведите 0.

### Примеры

**стандартный ввод**
```c++
3
1 2
2 3
```

**стандартный вывод**
```c++
2 0 2
```

**стандартный ввод**
```c++
9
3 2
4 2
1 2
5 1
1 6
7 6
6 8
8 9
```

**стандартный вывод**
```c++
0 1 2 2 1 1 6 6 8
```

## F. Опекуны карнотавров

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 2 секунды

Ограничение по памяти: 64 мегабайта

Карнотавры очень внимательно относятся к заботе о своем потомстве. У каждого динозавра
обязательно есть старший динозавр, который его опекает. В случае, если опекуна съедают (к сожа-
лению, в юрский период такое не было редкостью), забота о его подопечных ложится на плечи того,
кто опекал съеденного динамозавра. Карнотавры — смертоносные хищники, поэтому их обычаи
строго запрещают им драться между собой. Если у них возникает какой-то конфликт, то, чтобы
решить его, они обращаются к кому-то из старших, которому доверяют, а доверяют они только
тем, кто является их опекуном или опекуном их опекуна и так далее (назовем таких динозавров
суперопекунами). Поэтому для того, чтобы решить спор двух карнотавров, нужно найти такого
динозавра, который является суперопекуном для них обоих. Разумеется, беспокоить старших по
пустякам не стоит, поэтому спорщики стараются найти самого младшего из динозавров, который
удовлетворяет этому условию. Если у динозавра возник конфликт с его суперопекуном, то этот су
перопекун сам решит проблему. Если у динозавра нелады с самим собой, он должен разобраться с
этим самостоятельно, не беспокоя старших. Помогите динозаврам разрешить их споры.

### Формат входных данных

Во входном файле записано число _M_, обозначающее количество запросов ( 1 ⩽ _M_ ⩽ 200000 ).
Далее на отдельных строках следуют _M_ запросов, обозначающих следующие события:

* + v — родился новый динозавр и опекунство над ним взял динозавр с номером _v_. Родившемуся
динозавру нужно присвоить наименьший натуральный номер, который до этого еще никогда
не встречался.

* - _v_ — динозавра номер _v_ съели

* ? u v — у динозавров с номерами _u_ и _v_ возник конфликт и вам надо найти им третейского
судью.

Изначально есть один прадинозавр номер 1; гарантируется, что он никогда не будет съеден.

### Формат выходных данных

Для каждого запроса типа «?» в выходной файл нужно вывести на отдельной строке одно число
— номер самого молодого динозавра, который может выступить в роли третейского судьи.

### Пример

**стандартный ввод**
```c++
11
+ 1
+ 1
+ 2
? 2 3
? 1 3
? 2 4
+ 4
+ 4
- 4
? 5 6
? 5 5
```

**стандартный вывод**
```c++
1
1
2
2
5
```

## G. Генеалогия

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 4 секунды

Ограничение по памяти: 256 мегабайт

Во время обсуждений в Парламенте лорды, с похожими взглядами на решение проблемы, обычно
объединяются в группы. Как правило, результат обсуждения зависит от решения наиболее влия-
тельной группы лордов. Именно поэтому подсчёт влиятельности группы является наиболее важной
задачей.
Естественно, каждый лорд дорожит древностью своего рода, поэтому влиятельность лорда равна
древности его рода. Древность рода лорда — количество предков лорда: его отец, его дед, его прадед,
и т.д. Чтобы посчитать влиятельность группы лордов, требуется посчитать количество лордов в
группе вместе с их предками. Отметим, что если лорд является предком двух или более лордов в
группе, то этот лорд должен быть посчитан только один раз.
Вам дано фамильное дерево лордов (удивительно, но все лорды произошли от одного пра-лорда)
и список групп. Для каждой группу найдите её влиятельность.

### Формат входных данных

Первая строка входного файла содержит число _n_ — количество лордов ( 1 ⩽ _n_ ⩽100 000). Лорды
нумеруются целыми числами от 1 до _n_. Следующая строка содержит _n_ целых чисел _p1_ , _p2_,...,_pn_, где
 _pi_ — отец лорда с номером _i_. Если лорд является основателем рода, то _pi_ равно 1. Гарантируется,
что исходные данные формируют дерево. Третья строка входного файла содержит одно число _g_ —
количество групп ( 1 ⩽ _g_ ⩽3 000 000). Следующие _g_ строк содержат описания групп. _j_-ая строка
содержит число _kj_ — размер _j_-ой группы, после которого следуют _kj_ различных чисел — номера
лордов, состоящих в _j_-ой группе. Гарантируется, что сумма всех _kj_ во входном файле не превосходит
3 000 000.

### Формат выходных данных

В выходной файл выведите _g_ строк. В _j_-ой строке выведите единственное число: влиятельность
 _j_-ой группы. Гарантируется, что размер выходного файла не превосходит шести мегабайт.

### Примеры

**стандартный ввод**
```c++
4
-1 1 2 3
4
1 4
2 3 4
3 2 3 4
4 1 2 3 4
```

**стандартный вывод**
```c++
4
4
4
4
```

**стандартный ввод**
```c++
5
2 -1 1 2 3
10
3 3 4 1
3 2 4 3
4 1 3 5 4
1 4
2 2 3
3 1 4 3
1 2
3 3 4 5
1 1
3 1 2 4
```

**стандартный вывод**
```c++
4
4
5
2
3
4
1
5
2
3
```

## H. Дерево

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Задано подвешенное дерево, содержащее _n_ ( 1 ⩽ _n_ ⩽1 000 000) вершин. Каждая вершина по
крашена в один из _n_ цветов. Требуется для каждой вершины _v_ вычислить количество различных
цветов, встречающихся в поддереве с корнем _v_.

### Формат входных данных

В первой строке входного файла задано число _n_. Последующие _n_ строк описывают вершины, по
одной в строке. Описание очередной вершины _i_ имеет вид _pi_ _ci_, где _pi_ — номер родителя вершины _i_,
а _ci_— цвет вершины _i_ ( 1 ⩽ _ci_ ⩽n). Для корня дерева _pi_ = 0.

### Формат выходных данных

Выведитеnчисел, обозначающих количества различных цветов в поддеревьях с корнями в вер
шинах 1 ,..., _n_.

### Пример

**стандартный ввод**
```c++
5
2 1
3 2
0 3
3 3
2 1
```

**стандартный вывод
```c++
1 2 3 1 1
```

### [Решение](H.cpp)

## I. Размер компонент

Имя входного файла: стандартный ввод

Имя выходного файла: стандартный вывод

Ограничение по времени: 2 секунды

Ограничение по памяти: 64 мегабайта

Есть граф из _n_ вершин. Требуется обрабатывать следующие запросы:

* link U V — добавить ребро _UV_. Гарантируется, что до этого запроса вершины _U_ и _V_ были в
разных компонентах связности.

* cut U V — удалить ребро _UV_. Гарантируется, что такое ребро существовало.

* size V — узнать размер компоненты связности вершины _V_.

### Формат входных данных

Первая строка содержит два числа _n_ ( 2 ⩽ _n_ ⩽ 10^5 ) и _m_ ( 1 ⩽ _m_ ⩽ 10^5 ) — число вершин и число
операций. Следующие _m_ строк содержат операции.

### Формат выходных данных

Для каждой операции connected V U выведите 1 , если вершины в одной компоненте или 0 если
в разных.

### Пример

**стандартный ввод**
```c++
5 10
link 2 5
link 1 5
size 1
cut 2 5
size 1
size 2
link 2 3
link 2 4
link 3 5
size 1
```

**стандартный вывод**
```c++
3
2
1
5
```
