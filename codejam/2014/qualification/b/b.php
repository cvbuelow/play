<?php

/**
 *  b.php
 *  Carl von Buelow
 */

fscanf(STDIN, "%d\n", $T);

for ($i = 0; $i < $T; $i++) {

  list($C, $F, $X) = fscanf(STDIN, "%f %f %f\n");
  $rate = 2;
  $time = 0;

  while (true) {

    $time_to_wait_till_next_farm = $C / $rate;
    $time_to_wait_without_buying = $X / $rate;
    $time_to_wait_buying = $X / ($rate + $F) + $time_to_wait_till_next_farm;

    if ($time_to_wait_without_buying > $time_to_wait_buying) {
      $time += $time_to_wait_till_next_farm;
      $rate += $F;
    } else {
      $time += $time_to_wait_without_buying;
      break;
    }
  }
  
  echo "Case #" . ($i + 1) . ": " . sprintf('%.7f', $time) . "\n";
}