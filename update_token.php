<?php
if (!isset($_GET['lat']) || !isset($_GET['lon'])) {
    http_response_code(400);
    echo "Missing coordinates.";
    exit;
}

$lat = $_GET['lat'];
$lon = $_GET['lon'];

// Simpan ke file
file_put_contents("last_location.txt", "$lat,$lon");

echo "Location saved: $lat,$lon";
?>
