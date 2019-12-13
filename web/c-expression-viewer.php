<?php
	header("Content-Type: application/json");
	$d3_output = array();
	$post = file_get_contents('php://input');
	$data = JSON_decode($post, true);
	if( !isset($data['expr'])) {
		echo("{\"expr\":\"\", \"tree\":{}}");
	}
	else {
		exec("./c-nodes.out -expr \"".$data['expr']."\" -symbols \"".$data['symbols']."\" -d3", $d3_output);

		echo "{ \"expr\": \"".$data['expr']."\",";
		echo "  \"tree\": ";
		foreach($d3_output as $line) {
			echo $line;
		}
		echo "}";
	}
?>
