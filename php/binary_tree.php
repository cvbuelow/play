<?php

class Tree 
{
	public $root;
	public $sorted;
	public $visited;
	
	function add_node($key)
	{
		$this->insert($this->root, $key);
	}
	
	function insert(&$parent, $key)
	{		
		if ($parent === NULL) {
			$parent = new Node($key);
		} elseif ($key < $parent->key) {
			$this->insert($parent->left, $key);
		} elseif ($key > $parent->key) {
			$this->insert($parent->right, $key);
		}
	}
	
	function root_traverse($order)
	{
		$this->sorted = $this->visited = array();
		$this->traverse($this->root, $order);
	}
	
	function traverse($node, $order, $path = array())
	{
		if ($node !== NULL) {
			
			$path[] = $node->key;
			$this->visited[] = $node->key;
			
			if ($node->left === NULL && $node->right === NULL) {
				$this->print_path($path);
			}
			
			if ($order == 'pre') {
				$this->sorted[] = $node->key;
			}
			
			// For graph paths check here to see if we already visited $node->left
			if (!in_array($node->left->key, $this->visited)) {
				$this->traverse($node->left, $order, $path);
			}
			
			if ($order == 'in') {
				$this->sorted[] = $node->key;
			}
			
			if (!in_array($node->right->key, $this->visited)) {
				$this->traverse($node->right, $order, $path);
			}
			
			if ($order == 'post') {
				$this->sorted[] = $node->key;
			}
		}
	}
	
	function print_path($path)
	{
		echo implode('->', $path) . "\n";
	}
}

class Node 
{
	public $left;
	public $right;
	public $key;
	
	function __construct($key)
	{
		$this->key = $key;
	}
	
	function __toString()
	{
		return $this->left . '/' . $this->key;
	}
}

$mytree = new Tree();
foreach (array(13, 23, 24, 78, 1, 33, 99) as $value) {
	$mytree->add_node($value);
}
echo "\npre-order traversal (top down)\n";
$mytree->root_traverse('pre');
print_r($mytree->sorted);

echo "\nin-order traversal\n";
$mytree->root_traverse('in');
print_r($mytree->sorted);

echo "\npost-order traversal (bottom up)\n";
$mytree->root_traverse('post');
print_r($mytree->sorted);
