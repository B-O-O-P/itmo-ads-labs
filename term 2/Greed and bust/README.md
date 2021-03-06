# Жадность и перебор

## A. Проблема сапожника

Имя входного файла: cobbler.in

Имя выходного файла: cobbler.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

В некоей воинской части есть сапожник. Рабочий день сапожника длится _K_ минут. Заведую
щий складом оценивает работу сапожника по количеству починенной обуви, независимо от того,
насколько сложный ремонт требовался в каждом случае. Дано _n_ сапог, нуждающихся в починке.
Определите, какое максимальное количество из них сапожник сможет починить за один рабочий
день.

### Формат входного файла

В первой строке вводятся числа _K_ (натуральное, не превышает 1000 ) и _n_ (натуральное, не
превышает 500 ). Затем идет _n_ чисел — количество минут, которые требуются, чтобы починить
_i_-й сапог (времена — натуральные числа, не превосходят 100 ).

### Формат выходного файла

Выведите одно число — максимальное количество сапог, которые можно починить за один ра-
бочий день.

### Примеры

**cobbler.in**
```c++
10 3
6 2 8
```

**cobbler.out**
```c++
2
```

**cobbler.in**
```c++
3 2
10 20
```

**cobbler.out**
```c++
0
```

### [Решение](A.cpp)

## B. Выбор заявок

Имя входного файла: request.in

Имя выходного файла: request.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Вы прекрасно знаете, что в ЛКШ.Зима 2016 лекции читают лучшие преподаватели мира. К со
жалению, лекционных аудиторий у нас не так уж и много, поэтому каждый преподаватель составил
список лекций, которые он хочет прочитать ЛКШатам. Чтобы ЛКШата, утром идя на завтрак, уви
дели расписание лекций, необходимо его составить прямо сейчас. И без вас нам здесь не справиться.
У нас есть список заявок от преподавателей на лекции для одной из аудиторий. Каждая заявка
представлена в виде временного интервала [_si_, _fi_) — время начала и конца лекции. Лекция считается
открытым интервалом, то есть какая-то лекция может начаться в момент окончания другой, без
перерыва. Необходимо выбрать из этих заявок такое подмножество, чтобы суммарно выполнить
максимальное количество заявок. Учтите, что одновременно в лекционной аудитории, конечно же,
может читаться лишь одна лекция.

### Формат входного файла

В первой строке вводится натуральное число _N_, не более 1000 — общее количество заявок на
лекции. Затем вводится _N_ строк с описаниями заявок — по два числа в каждом _si_ и _fi_. Гарантиру
ется, что _si_ < _fi_. Время начала и окончания лекции — натуральные числа, не превышают 1440 (в
минутах с начала суток).

### Формат выходного файла

Выведите одно число — максимальное количество заявок, которые можно выполнить.

### Примеры

**request.in**
```c++
1
5 10
```

**request.out**
```c++
1
```

**request.in**
```c++
3
1 5
2 3
3 4
```

**request.out**
```c++
2
```

### [Решение](B.cpp)

## C. Распечатка условий

Имя входного файла: printing.in

Имя выходного файла: printing.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Популярность окружной олимпиады по информатике растёт год от года. При этом организато
ры должны заранее распечатать как условия задач, так и другие материалы олимпиады (анкеты,
памятки и т.п.). В этом году они оценили объём печатной продукции в _N_ листов.
Фирма, готовая размножить печатные материалы, предлагает следующие финансовые условия.
Один лист она печатает за _A1_ рублей, 10 листов — за _A2_ рублей, 100 листов — за _A3_ рублей, 1000
листов — за _A4_ рублей, 10000 листов — за _A5_ рублей, 100000 листов — за _A6_ рублей, 1000000 листов —
за _A7_ рублей. При этом не гарантируется, что один лист в более крупном заказе обойдется дешевле,
чем в более мелком. И даже может оказаться, что для любой партии будет выгодно воспользоваться
тарифом для одного листа.
Печать конкретного заказа производится или путем комбинации нескольких тарифов, или путем
заказа более крупной партии. Например, 980 листов можно распечатать, заказав печать 9 партий
по 100 листов плюс 8 партий по 10 листов, сделав 98 заказов по 10 листов, 980 заказов по 1 листу
или заказав печать 1000 (или даже 10000 и более) листов, если это окажется выгоднее. Требуется
по заданному объему заказа в листах _N_ определить минимальную сумму денег в рублях, которой
будет достаточно для выполнения заказа.

### Формат входного файла

На вход программе сначала подается число _N_ ( 1 ≤ _N_ ≤ 2 × 10^9 ) –— количество листов в заказе. В
следующих 7 строках ввода находятся натуральные числа _A1_, _A2_, _A3_, _A4_, _A5_, _A6_, _A7_ соответственно
( 1 ≤ _Ai_ ≤ 10^6 ).

### Формат выходного файла

Выведите одно число –— минимальную сумму денег в рублях, которая нужна для выполнения
заказа. Гарантируется, что правильный ответ не будет превышать 2 × 10^9.

### Примеры

**printing.in**
```c++
980
1
9
90
900
1000
10000
10000
```

**printing.out**
```c++
882
```

**printing.in**
```c++
980
1
10
100
1000
900
10000
10000
```

**printing.out**
```c++
900
```

## D. Последовательность

Имя входного файла: sequence.in

Имя выходного файла: sequence.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Дана последовательность натуральных чисел _a1_, _a2_,..., _an_, и известно, что _ai_ ≤ _i_ для любого
1 ≤ _i_ ≤ _n_. Требуется определить, можно ли разбить элементы последовательности на две части
таким образом, что сумма элементов в каждой из частей будет равна половине суммы всех элементов
последовательности.

### Формат входного файла

В первой строке входного файла находится одно целое число _n_ ( 1 ≤ _n_ ≤ 40 000). Во второй
строке находитсяnцелых чисел _a1_, _a2_,..., _an_ ( 1 ≤ _ai_ ≤ _i_).

### Формат выходного файла

В первую строку выходного файла выведите количество элементов посделовательности в лю
бой из получившихся двух частей, а во вторую строку через пробел номера этих элементов. Если
построить такое разбиение невозможно, выведите -1.

### Примеры

**sequence.in**
```c++
3
1 2 3
```

**sequence.out**
```c++
1
3
```

## E. Алиса и яблоки

Имя входного файла: apples.in

Имя выходного файла: apples.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Алисе в стране чудес попалисьnволшебных яблок. Про каждое яблоко известно, что после
того, как его съешь, твой рост сначала уменьшится на _ai_ сантиметров, а потом увеличится на _bi_
сантиметров. Алиса очень голодная и хочет съесть все _n_ яблок, но боится, что в какой-то момент ее
рост станет равным нулю или еще меньше, и она пропадет совсем. Помогите ей узнать, можно ли
съесть яблоки в таком порядке, чтобы в любой момент времени рост Алисы был больше нуля.

### Формат входного файла

В первой строке вводятся натуральные числа _n_ и _s_, не более 1000 — число яблок и начальный
рост Алисы. В следующих _n_ строках вводятся пары натуральных чисел _ai_, _bi_, не больших 1000.

### Формат выходного файла

Если яблоки съесть нельзя, выведите число -1. Иначе выведите _n_ чисел — номера яблок, в том
порядке, в котором их нужно есть.

### Примеры

**apples.in**
```c++
3 5
2 3
10 5
5 10
```

**apples.out**
```c++
1 3 2
```

**apples.in**
```c++
3 5
2 3
10 5
5 6
```

**apples.out**
```c++
-1
```

### [Решение](E.cpp)

## F. Инверсии и Сережа

Имя входного файла: john.in

Имя выходного файла: john.out

Ограничение по времени: 3 секунды

Ограничение по памяти: 256 мегабайт

Недавно Сережа изучил понятие инверсии. Инверсией в последовательности чисел _sk_ называется
пара _si_, _sj_, такая что _i_ < _j_ и _si_> _sj_.
Петя дал Сереже _n_ карточек. На каждой карточке написано два числа: одно красное и одно
синее. Сережа хочет применить свои знания об инверсиях к этому набору карточек.
Сережа хочет выложить перед собой карточки в таком порядке, чтобы количество инверсий
было как можно меньше. При этом он считает число инверсий между числами одного цвета. Таким
образом, он хочет выложить карточки в таком порядке, чтобы если рассмотреть отдельно красные
числа в этом порядке и отдельно синие числа в этом порядке, суммарное число инверсий было как
можно меньше.

### Формат входного файла

Первая строка входного файла содержит число _n_ — число карточек в наборе ( 1 ≤ _n_ ≤ 100 000).
Следующие _n_ строк описывают карточки, по одной на строке, _i_-я строка содержит целые числа _ri_
и _bi_ ( 1 ≤ _ri_, _bi_ ≤ 10^9 ) — соответственно красное и синее число на _i_-й карточке.

### Формат выходного файла

Выведите одно число — минимальное возможное число одноцветных инверсий.

### Примеры

**john.in**
```c++
3
10 3
20 2
30 1
```

**john.out**
```c++
3
```

**john.in**
```c++
4
2 2
5 25
2 1
10 9
```

**john.out**
```c++
1
```

## G. Красивые перестановки

Имя входного файла: beautiful.in

Имя выходного файла: beautiful.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 64 мегабайта

Будем называть ценностью перестановки ⟨ _a1_, _a2_,..., _an_ ⟩ величину
( _a1_ _a2_ + _a2_ _a3_ + ... + _an-1_ _an_ ) mod _r_.
Петя считает число красивым, если оно либо равно 0, либо число его делителей кратно 3. На
пример, 9 — красивое число (у него три делителя: 1, 3 и 9), а 6 — нет (у него 4 делителя: 1, 2, 3 и
6).
Вам даны _n_ и _r_, найдите число перестановок, ценность которых является красивым числом.

### Формат входного файла

Во входном файле заданы числаnиr( 2 ≤ _n_ ≤ 10 , 2 ≤ _r_ ≤ 1000 ).

### Формат выходного файла

Выведите в выходной файл число перестановок, ценность которых является красивым числом.

### Пример

**beautiful.in**
```c++
3 10 
```

**beautiful.out**
```c++
2
```

### Комментарий

В примере искомые перестановки — ⟨  1 , 3 , 2 ⟩ и ⟨ 2 , 3 , 1 ⟩

### Система оценки:

В этой задаче вы получите 70 баллов, если ваша программа будет правильно работать на тестах,
где _n_ ≤ 8. И, кстати, в этой задаче проблема со временем может быть не только из-за питона. Будьте
осторожны!

### [Решение](G.cpp)

## H. Двоичные вектора 2

Имя входного файла: vectors2.in

Имя выходного файла: vectors2.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 64 мегабайта

Выведите в выходной файл все двоичные вектора, в которых нет двух единиц подряд.

### Формат входного файла

Во входном файле задано число _n_ ( 1 ≤ _n_ ≤ 16 ).

### Формат выходного файла

В первой строке выходного файла выведите количество двоичных векторов длиныnв которых
нет двух единиц подряд. В следующих строках выведите сами эти вектора в лексикографическом
порядке по одному в строке.

### Пример

**vectors2.in**
```c++
3 5
```

**vectors2.out**
```c++
000
001
010
100
101
```
### Система оценки:

Злые члены жюри не хотят оценивать частичные решения в этой задаче. Так что только 100.

### [Решение](H.cpp)

## I. Квадратный корень

Имя входного файла: sqroot.in

Имя выходного файла: sqroot.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайта

Введем в рассмотрение так называемые 0-1 матрицы размером 4 на 4. Такая матрица — это
квадратная таблица, содержащая 16 чисел _ai,j_ ( _i_ = 1...4 , _j_ = 1...4 ), каждое из которых равно 0
или 1.
Произведением двух матриц _A_ и _B_ называется матрица _A_ · _B_ = _C_, элементы которой вычисля
ются по формуле

```
ci;j=( ∑{k=1..4} (ai,k) * (bk,j) ) mod 2:
```

Квадратным корнем из матрицы _A_ называется 0-1 матрица _B_, такая что _B_ · _B_ = _A_.
Задана некоторая 0-1 матрица размера 4 на 4. Вычислите ее квадратный корень или установите,
что его не существует.

### Формат входного файла

Входной файл содержит четыре строки, каждая из которых содержит четыре числа, каждое из
этих чисел — либо 0, либо 1, _j_-е число _i_-й строки соответствует элементу _ai,j_ заданной матрицыA.

### Формат выходного файла

Выведите в выходной файл квадратный корень из заданной матрицы в формате, аналогичном
входному файлу. Если квадратного корня не существует — выведите в выходной файл **NO SOLUTION**.
Если решений несколько, выведите любое.

### Примеры

**sqroot.in**
```c++
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
```

**sqroot.out**
```c++
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
```

**sqroot.in**
```c++
0 0 0 1
0 1 0 1
0 1 0 1
1 0 0 0
```

**sqroot.out**
```c++
NO SOLUTION
```

### [Решение](I.cpp)

### Система оценки:

Вы уже видели эту задачу, но мало кто ее решил. Решите ее теперь и получите 100 баллов.

## J. Останки Юрского периода

Имя входного файла: jurassic.in

Имя выходного файла: jurassic.out

Ограничение по времени: 2 seconds

Ограничение по памяти: 256 мегабайта

Археологи недавно нашли фрагменты динозавра Юрского периода. Археологи решили, что они
отправят кости динозавра в музей. Но, к сожалению, кости такие большие, что они не смогли по
ложить их в один ящик. Поэтому они разделили скелет на отдельные кости и отправили каждый
из них по-отдельности. Теперь сотрудникам музея предстоит собрать скелет. Для того, чтобы они
могли это сделать, археологи отметили точки, в которых кости должны были быть соединены, спе
циальными пометками. А именно — в каждой точке, где соединялись две кости, археологи написали
на каждой из них одинаковые заглавные латинские буквы.
Однако пока археологи разбирали и упаковывали скелет, были обнаружены еще кости и они
тоже были отправлены в музей. Причем они тоже могли быть соединены друг с другом, поэтому
на них также могли быть пометки. Более того, археологи всегда использовали одинаковые пометки
в точках на костях, которые должны были быть соединены, но они могли использовать одну и ту
же пометку для различных соединений. Правда на каждой кости было не более одной пометки
конкретной буквой.
Теперь работники музея пытаются разобраться с этой ситуацией и найти хотя бы какое-нибудь
теоретически возможное множество костей исходного скелета динозавра. А именно, они хотят найти
множество костей, которое удовлетворяет следующим условиям.

* Кости, помеченные некоторой буквой, можно попарно соединить друг с другом. Иначе говоря,
    каждая пометка встречается четное число раз.
* Число костей в наборе максимально.

### Формат входного файла

Первая строка входного файла содержит _N_ — число костей ( 1 ≤ _N_ ≤ 24 ). Следующие _N_ строк
содержат описание костей: каждая строка содержит непустую последовательность различных за-
главных букв латинского алфавита — метки на костях.

### Формат выходного файла

На первой строке выходного файла выведите _L_ — максимальное вомзожное число костей, из
которых можно собрать скелет. Вторая строка должна содержать _L_ чисел — номера костей. Кости
пронумерованы от 1 до _N_ в порядке, в котором они заданы во входном файле.

### Пример

**jurassic.in**
```c++
6
ABD
EG
GE
ABE
AC
BCD
```

**jurassic.out**
```c++
5
1 2 3 5 6
```

**jurassic.in**
```c++
1
ABC
```

**jurassic.out**
```c++
0

```

### Система оценки:

Первая группа содержит тесты, в которых _N_ ≤ 12. Она оценивается в 60 баллов.
Вторая группа содержит тесты, в которых _N_ ≤ 24. Она оценивается в 40 баллов.

## K. Сокровища

Имя входного файла: dowry.in

Имя выходного файла: dowry.out

Ограничение по времени: 2 секунды

Ограничение по памяти: 256 мегабайт

Дочь короля Флатландии собирается выйти за прекрасного принца. Принц хочет подарить прин
цессе сокровища, но он не уверен какие именно бриллианты из своей коллекции выбрать.
В коллекции принцаnбриллиантов, каждый характеризуется весом _wi_ и стоимостью _vi_. Принц
хочет подарить наиболее дорогие бриллианты, однако король умен и не примет бриллиантов сум
марного веса больше _R_. С другой стороны, принц будет считать себя жадным всю оставшуюся
жизнь, если подарит бриллиантов суммарным весом меньше _L_.
Помогите принцу выбрать набор бриллиантов наибольшей суммарной стоимости, чтобы суммар
ный вес был в отрезке [_L_, _R_].

### Формат входного файла

Первая строка содержит число _n_ ( 1 ≤ _n_ ≤ 32 ), _L_ и _R_ ( 0 ≤  _L_ ≤  _R_ ≤ 10^18 ). Следующие _n_ строк
описывают бриллианты и содержит по два числа — вес и стоимость соответствующего бриллианта
( 1 ≤  _wi_, _vi_ ≤ 10^15 ).

### Формат выходного файла

Первая строка вывода должна содержать _k_ — количество бриллиантов, которые нужно подарить
принцессе. Вторая строка должна содержать номера даримых бриллиантов.
Бриллианты нумеруются от 1 до _n_ в порядке появление во входных данных.
Если составить подарок принцессе невозможно, то выведите 0 в первой строке вывода.

### Примеры

**dowry.in**
```c++
3 6 8
3 10
7 3
8 2
```

**dowry.out**
```c++
1
2
```
### Система оценки:

В этой задаче вы получите 100 баллов, если ваша программа будет правильно работать на всех
тестах. Такие дела.


