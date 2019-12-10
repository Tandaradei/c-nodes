<?php
	header("Content-Type: application/json");
	$d3_output = array();
	if( !isset($_POST['expr']) {
		echo("No expr found");
	}
	exec("../build/c-nodes input \".$_POST['expr'].\" d3", $d3_output);
	echo $d3_output;
?>
