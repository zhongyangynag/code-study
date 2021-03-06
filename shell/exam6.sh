#!/bin/bash




#该程序使用 $* 可以引用所有的参数。这样用户可以使用不定数目的参数，对这些参数执行相同的操作。如下命令，则可以输出所有的输入文件
cat  $*
echo "-----------------------------"




#算数操作符的使用：
# 1) 使用expr命令：
#    可以使用操作符：+ - \* / %
#    在使用上述运算符前后需留有空白


i=1


#在使用的运算符前后要留空白
i=`expr $i + 5`
echo i=$i


#使用let命令：
#let命令和expr命令可以互换，let语句中不需要在变量前面加$符号，但必须将单个或带有空格的表达式用双引号引起来
let i=$i+10
echo i=$i
let i=i+20
echo i=$i
