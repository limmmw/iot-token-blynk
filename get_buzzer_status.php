<?php
$status = file_exists("buzzer_status.txt") ? trim(file_get_contents("buzzer_status.txt")) : "0";
echo $status;
?>
