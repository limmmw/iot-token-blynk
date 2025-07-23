<?php
if (isset($_GET['status'])) {
    $status = $_GET['status'] == '1' ? 'BUZZ1' : 'BUZZ0';
    file_put_contents("buzzer_status.txt", $status);
    echo "Buzzer status updated to: $status";
} else {
    echo "Gunakan ?status=1 (ON) atau ?status=0 (OFF)";
}
?>