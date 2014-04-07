<?php

function myrealpath($abs, $rel)
{
    $remove = 0;
    $realpath = array();
    $path = $abs . '/' . $rel;
    $segs = array_reverse(explode('/', $path));
    foreach ($segs as $seg) {
        if ($seg !== '' && $seg !== '.') {
            if ($seg === '..') {
                $remove++;
            } elseif ($remove) {
                $remove--;
            } else {
                array_unshift($realpath, $seg);
            }
        }
    }
    return '/' . implode('/', $realpath);
}

echo myrealpath('/etc/usr/bin', '../cvb/../foo');