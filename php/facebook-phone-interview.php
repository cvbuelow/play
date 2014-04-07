<?php
// Given an array as input return true if the sum of any two numbers is zero
// [4, -1, 2, 1, 0, 1, -2]
// [-2, -1, 0, 1, 1, 4]

function hasZeroSum($arr)
{
    foreach($arr as $i => $num)
    {
        foreach($arr as $j => $num2)
        {
            if($i !== $j && !($num1 + $num2)) {
                return TRUE;
            }        
        }
    }
    return FALSE;
}

function hasZeroSumFaster($arr)
{
    sort($arr);
    $j = count($arr) - 1;
    if(sum($arr, 0, $j)) {
        return TRUE;
    }
    return FALSE;
}

function sum($arr, $i, $j)
{
    if($i === $j)
        return FALSE;
    $sum = $arr[$i] + $arr[$j];
       
    if(!$sum) {
        return TRUE;
    } elseif($sum > 0) {
        return sum($arr, $i, $j - 1);
    } else {
        return sum($arr, $i + 1, $j);
    }
}