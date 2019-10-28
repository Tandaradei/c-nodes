<?php
	header("Content-Type: application/json");
	$data =  file_get_contents('php://input');

	passthru("/media/sf_websocketfreigabe/expressionviewer/a.out \"$data\"");
?>
