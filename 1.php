<?php
error_reporting(0);
$query = $_GET['address'];
$item_count = $_GET['itemCount'];

$client_id = '96dHZVzsAus7ScBAW1B5QeVFMMpAgiqEOS78ZR8d7jsrY7W5KuBnWep_iK2vMjnNhvx_c1VYNpWIsBWBIhujSQ==';
$client_secret = 'lrFxI-iSEg-ou-BZCSM4KaK0BNRN-qmhcZ-cuV33IC1-ApVjQ2iX2snQ1Hlw8EI5nCFozbipIvu5lg7XF2SKo9nNznP1OeGd';

$token_url = "https://outpost.mapmyindia.com/api/security/v2.3.0/oauth/token?grant_type=client_credentials&client_id=$client_id&client_secret=$client_secret";
$curl_token = curl_init();
curl_setopt($curl_token, CURLOPT_URL, $token_url);
curl_setopt($curl_token, CURLOPT_POST, 1);
curl_setopt($curl_token, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($curl_token, CURLOPT_SSL_VERIFYHOST, 0);
curl_setopt($curl_token, CURLOPT_SSL_VERIFYPEER, 0);

$result_token = curl_exec($curl_token);
$json = json_decode($result_token, true);

$access_token = $json['access_token'];
$token_type = $json['token_type'];

curl_close($curl_token);

$url = "https://atlas.mappls.com/api/places/geocode?address=" . urlencode($query) . "&itemCount=" . $item_count;

$header = array();
$header[] = 'Content-length: 0';
$header[] = 'Content-type: application/json';
$header[] = 'Authorization: ' . $token_type . ' ' . $access_token;

$curl = curl_init();
curl_setopt($curl, CURLOPT_URL, $url);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, 0);
curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, 0);
curl_setopt($curl, CURLOPT_HTTPHEADER, $header);

$result = curl_exec($curl);

$http_status = curl_getinfo($curl, CURLINFO_HTTP_CODE);
$header_size = curl_getinfo($curl, CURLINFO_HEADER_SIZE);
$response_header = explode("\r\n", substr($result, 0, $header_size));
$body = substr($result, $header_size);

curl_close($curl);

$res = array();
if ($http_status == 200) {
    $res['status'] = 'success';
    $res['data'] = $body;
} elseif ($http_status == 400) {
    $res['status'] = 'fail';
    $res['data'] = "Bad request.";
} else {
    $res['status'] = 'fail';
    $res['data'] = str_replace("message:", "", $response_header[5]);
}
echo json_encode($res);
?>
