<?php
	header("Content-Type: application/json");
	$json_output = array();
	$post = file_get_contents('php://input');
	$data = JSON_decode($post, true);
	if( !isset($data['expr'])) {
		echo("{\"expr\":\"\", \"trees\":{}}");
	}
	else {
		$expr = str_replace(PHP_EOL, '', $data['expr']);
		exec("./c-nodes.out -expr \"".$expr."\" -symbols \"".$data['symbols']."\" -json", $json_output);

		echo "{ \"expr\": \"".$expr."\",";
		echo "  \"list\": ";
		foreach($json_output as $line) {
			echo $line;
		}
		echo "}";
	}
?>
