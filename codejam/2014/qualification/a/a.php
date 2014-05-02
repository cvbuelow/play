<?php

/**
 *  a.php
 *  Carl von Buelow
 */

fscanf(STDIN, "%d\n", $T);

for ($i = 0; $i < $T; $i++) {

  $row = array();
  $array = array();

  for ($j = 0; $j < 2; $j++) {
    fscanf(STDIN, "%d\n", $row[$j]);

    for ($k = 0; $k < 4; $k++) {
      $array[$j][$k] = fscanf(STDIN, "%d %d %d %d\n");
    }
  }

  $result = array_intersect($array[0][$row[0] - 1], $array[1][$row[1] - 1]);
  $num_results = count($result);

  if ($num_results == 1) {
    $output = array_pop($result);
  } elseif (!$num_results) {
    $output = "Volunteer cheated!";
  } else {
    $output = "Bad magician!";
  }

  echo "Case #" . ($i + 1) . ": " . $output . "\n";
}