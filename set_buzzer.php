<?php
if (!isset($_GET['status'])) {
    http_response_code(400);
    echo "Missing status";
    exit;
}

$status = $_GET['status'] == "1" ? "1" : "0";
file_put_contents("buzzer_status.txt", $status);
echo "Buzzer status set to $status";
?>
