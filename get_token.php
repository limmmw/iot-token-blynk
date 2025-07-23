<?php
$status = @file_get_contents("buzzer_status.txt");
if ($status === false) {
    echo "BUZZ0"; // default mati
} else {
    echo $status; // BUZZ1 atau BUZZ0
}
?>
