## thought process:
1) Необходимо разобраться в том, какие конкретно у нас входные данные, а именно:

    * Вид данных (строки, числа, символы и тд.)
    * Ограничения внутри одного вида данных (возможные символы, возможные числа и т.д.)

    1.1 В нашем случае:
    * Нам дано ЧИСЛО P
    * P принадлежит ПРОМЕЖУТКУ [2, 2000)
    * P - ПРОСТОЕ число
2) Необходимо разобраться какие действия необходимо произвести над входными данными для получения выходных данных:
    * как требуется преобразовать данные?
    * на какие вопросы необходимо ответить касательно входных данных?

    2.1 В нашем случае:
    * Необходимо понять какое число ПЕРВООБРАЗНЫХ КОРНЕЙ есть у введенного числа 
3) Ориентируясь по ключевым моментам - начинаем писать программу.
    * Прежде всего обеспечим корректный ввод стартовых данных:
        * Проверим что с клавиатуры введено число
        * Проверим что число входит в заданный промежуток
        * Проверим что число является простым
    * В случае некорректного ввода данных - необходимо предусмотреть завершение работы приложения сигнализирующего ту или иную ошибку (Данные действия - совершаются несколько раз в нашей программе - что говорит о том, что требуется Выделить логику сигнализации в отдельную функцию и вызывать ее по требованию)
    * Обработаем данные:
        * первообразными корнями в теории могут быть любые числа нв промежутке [1, P), следовательно введем цикл обрабатывающий каждую из этих возможностей
        * Для каждого из перебираемых чисел необходимо проверить является ли оно примитивным корнем или нет, введем функцию позволяющую проверять число на то, является ли оно примитивным корнем введенного с клавиатуры числа или нет
        * будем вызывать созданную функцию на каждой итеррации цикла
            * в случае если оно является примитивным корнем - выведем число на экран и сделаем инкремент счетчика отвечающего за количество примитивных корей
            * в случае если оно не является примитивным корнем - будем идти дальше по циклу до тех пор пока не проверим все числа
