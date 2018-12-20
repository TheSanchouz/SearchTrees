# Сравнение поисковых деревьев
Лабораторная работа по курсу "Алгоритмы и анализ сложности"

Целью данной работы является сравнение следующих структур данных:
1. AVL Tree (АВЛ дерево)
2. Treap (Декартово дерево)
3. Splay Tree (Косое дерево)
4. RB Tree (Красно-чёрное дерево, не нужно реализовывать, будем использовать std::map)
5. Sorted Array (Отсортированный массив, только для бинарного поиска)

Что измеряется?
1. Время вставки
2. Время удаления
3. Время поиска

Данные:
1. Случайные целые числа
2. Случайные строки/векторы

Вывод должен содержать:
1. График зависимости скорости вставки от количества элементов в дереве
2. График зависимости скорости удаления от количества элементов в дереве
3. График зависимости скорости поиска от количества элементов в дереве

---------
## Информация
По АВЛ деревьям:
1. [wikipedia](https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)
2. [wikibooks](https://ru.wikibooks.org/wiki/%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)
3. [habr](https://habr.com/post/150732/)
4. [neerc.ifmo](https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)

По декартовым деревьям:
1. [habr 1/3](https://habr.com/post/101818/)
2. [habr 2/3](https://habr.com/post/102006/)
3. [habr 3/3](https://habr.com/post/102364/)
4. [e-maxx](http://e-maxx.ru/algo/treap)
5. [wikipedia](https://ru.wikipedia.org/wiki/%D0%94%D0%B5%D0%BA%D0%B0%D1%80%D1%82%D0%BE%D0%B2%D0%BE_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)
6. [neerc.ifmo](https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B5%D0%BA%D0%B0%D1%80%D1%82%D0%BE%D0%B2%D0%BE_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)

По сплей деревьям:
1. [wikipedia](https://ru.wikipedia.org/wiki/%D0%A0%D0%B0%D1%81%D1%88%D0%B8%D1%80%D1%8F%D1%8E%D1%89%D0%B5%D0%B5%D1%81%D1%8F_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)
2. [habr](https://habr.com/company/compscicenter/blog/210296/)
3. [neerc.ifmo](https://neerc.ifmo.ru/wiki/index.php?title=Splay-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)

---------
Еще немного полезной информации:
1. [Конспект Черепанова Валерия](https://vk.com/doc276194869_485410391?hash=9488d90b3d68181d54&dl=c4ba70a8e43fdb2fc2)
