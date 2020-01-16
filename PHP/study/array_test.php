<?php
$array = array("A", "B", "C", "D", "E");
echo count($array);
echo "<br>";
$countnum = count($array);
for ($i = 0; $i < $countnum; $i++) {
    echo $array[$i] . " ";
}
