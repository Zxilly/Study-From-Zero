<?php
$array = array(9, 8, 7, 6, 5, 4, 3, 2, 1, 754, 23, 62, 63, 85, 12, 86);

for ($i = count($array) - 1; $i >= 0; $i--) {
    for ($j = 0; $j < $i; $j++) {
        if ($array[$j + 1] > $array[$j]) {
            $swap = $array[$j + 1];
            $array[$j + 1] = $array[$j];
            $array[$j] = $swap;
        }
    }
}

print_r($array);