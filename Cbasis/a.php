<?php

//$a = 1;
//$b = 2;
//
//echo "初始值：a=$a,b=$b\n";
//
//// 应用传递函数
//function f(&$x,&$y){
//    $tmp = $x;
//    $x = $y;
//    $y = $tmp;
//}
//
//f($a,$b);
//echo "变量转换后：a=$a,b=$b\n";
ob_start();
echo "Hello";

ob_end_clean();
echo "World\n";


