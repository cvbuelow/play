<?php
/**
 * Check if an anagram of $needle is contained in $haystack
 */
function is_anagram($needle, $haystack)
{
	$haystack_length = strlen($haystack);
	$needle_length = strlen($needle);
	
	if ($needle_length > $haystack_length) {
		return FALSE;
	}
	
	$needle_array = str_split($needle);
	sort($needle_array);
	
	for ($i = 0; $i <= $haystack_length - $needle_length; $i++) {
		$substring = substr($haystack, $i, $needle_length);
		$substring_array = str_split($substring);
		sort($substring_array);
		if ($needle_array === $substring_array) {
			return TRUE;
		}
	}
	return FALSE;
}
