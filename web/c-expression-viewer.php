<?php
	header("Content-Type: application/json");
	$d3_output = array();
	if( !isset($_POST['expr'])) {
		echo("No expr found");
	}
	else {
		exec("./c-nodes.out input \"".$_POST['expr']."\" d3", $d3_output);

		echo "{ \"expr\": \"".$_POST['expr']."\",";
		echo "  \"tree\": ";
		foreach($d3_output as $line) {
			echo $line;
		}
		echo "}";
	}
?>
