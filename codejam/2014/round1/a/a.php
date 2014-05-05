<?php

/**
 *  a.php
 *  Carl von Buelow
 */

fscanf(STDIN, "%d\n", $T);

for ($i = 0; $i < $T; $i++) {

  fscanf(STDIN, "%d\n", $N);
  
  $char_lengths = array();
  $nodups = array();

  for ($j = 0; $j < $N; $j++) {
    fscanf(STDIN, "%s\n", $string);
    $chars = str_split($string);
    $lastchar = NULL;
    $charnum = -1;
    // Calculate length of each series of the same character for each string
    foreach ($chars as $char) {
      if ($char === $lastchar) {
        $char_lengths[$charnum][$j]++;
      } else {
        $char_lengths[++$charnum][$j] = 1;
      }
      $lastchar = $char;
    }
    // Remove dups and comapare all strings
    $nodups[$j] = preg_replace('/(.)\\1+/', '$1', $string);
  }

  if (count(array_unique($nodups)) === 1) {
    $output = 0;
    foreach ($char_lengths as $lengths) {
      // Find median and calculate offset of each length from it
      rsort($lengths); 
      $middle = ceil(count($lengths) / 2); 
      $median = $lengths[$middle - 1];
      foreach ($lengths as $length) {
        $output += abs($length - $median);
      }
    }
  } else {
    $output = "Fegla Won";
  }

  echo "Case #" . ($i + 1) . ": " . $output . "\n";
}