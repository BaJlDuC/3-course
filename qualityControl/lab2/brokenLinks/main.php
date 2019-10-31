<?php

 $validLinks = fopen('valid.txt', 'w');
 $invalidLinks = fopen('invalid.txt', 'w');
 
 $validLinksArray = array();
 $invalidLinksArray = array();

$index = -1;
do {
     //echo "index $index\n";
     if (count($validLinksArray) == 0) {
         $contents = file_get_contents("http://52.136.215.164/broken-links/");
         //echo "null array\n";
     }
     else {
         $contents = file_get_contents("http://52.136.215.164/broken-links/$validLinksArray[$index]");
         //echo "not null array\n";
     }
     preg_match_all('/a+\s+href="([^#"]+)"/', $contents, $links);
     foreach ($links[1] as $key => $link) {
       //  echo "link: $link\n";
             $headers = get_headers("http://52.136.215.164/broken-links/$link");
             $output = "$link\n$headers[0]; $headers[1]\n\n";
             if ((strpos($headers[0], '200') !== false) && ($link !== "#")) {
                 if ((!in_array($link, $validLinksArray) && strpos($link, '.css') === false)) {
                     array_push($validLinksArray, $link);
                 }
             } else if ($link !== "#") {
                 if (!in_array($link, $invalidLinksArray)) {
                     array_push($invalidLinksArray, $link);
                 }
             }
     }
     $index++;
}
while ($index !== count($validLinksArray));

foreach ($validLinksArray as $key => $link) {
    $headers = get_headers("http://52.136.215.164/broken-links/$link");
    $output = "$link\n$headers[0]; $headers[1]\n\n";
    fwrite($validLinks, $output);
 }

foreach ($invalidLinksArray as $key => $link) {
    if (strpos($link, 'https') !== false)
    {
       // echo "https? $links\n";
        $headers = get_headers($link);
        $output = "$link\n$headers[0]; $headers[1]\n\n";
        fwrite($validLinks, $output);
    }
    else {
        $headers = get_headers("http://52.136.215.164/broken-links/$link");
        $output = "$link\n$headers[0]; $headers[1]\n\n";
        fwrite($invalidLinks, $output);
    }
}

// print_r($validLinksArray);
// print_r($invalidLinksArray);