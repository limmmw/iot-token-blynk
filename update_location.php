<?php
if (!isset($_GET['lat']) || !isset($_GET['lon'])) {
    http_response_code(400);
    echo "Latitude and longitude required.";
    exit;
}

$lat = $_GET['lat'];
$lon = $_GET['lon'];

$data = date("Y-m-d H:i:s") . " - Lat: $lat, Lon: $lon\n";
file_put_contents("location_log.txt", $data, FILE_APPEND);

echo "Location updated.";
?>
