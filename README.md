# Package_Installation_task
Нека имаме списък с N на брой пакети, всеки от които зависи на други пакети от списъка.
Напишете конзолно приложение, което да приема от стандартния вход числото N (брой
редове) и съответните редове, като на всеки ред първо пишем името на пакета, а след
това изброяваме чрез интервали пакетите, на които зависи. Ако на реда има само име на
пакет то се счита, че пакетът няма зависимости. Приложението трябва да печата на
конзолата ред, в който тези пакети могат да бъдат инсталирани успешно.

Пояснение:
Ако пакетът A зависи на пакета B и B не е инсталиран, то пакетът A не може да бъде
инсталиран успешно, т.е. трябва да се инсталира първо B, след което А.

Примерен вход:

7

A B C

B C E

C D

D

E F

F C

G

Примерен изход:
(възможни са няколко решения)

G D C F E B A
